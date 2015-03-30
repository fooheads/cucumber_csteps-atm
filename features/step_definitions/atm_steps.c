#include <atm.h>

#include <csteps.h>
#include <assertion-macros/assertion-macros.h>

#include <stdio.h>

#define STEP_PREFIX atm_steps

static ATM atm;
static Account account;
static Card card;
static Result result;
static int dispensed_amount;

void before_scenario() {
  // make sure that failed assertions are aborted
  __assert_bail = 1;

  atm.balance = 0;
  account.balance = 0;
  card.account = &account;
  card.valid = false;
  result = -1;
  dispensed_amount = -1;
}

GIVEN("^the account balance is (\d+)$") (int balance) {
  account.balance = balance;
}

GIVEN("^the card is valid$") () {
  card.valid = true;
}

GIVEN("^the machine contains enough money$") () {
  atm.balance = 1000;
}

WHEN("^the account holder requests (\d+)$") (int amount) {
  result = atm_withdraw(&atm, &card, amount, &dispensed_amount);
}

THEN("^the ATM should dispense (\d+)$") (int amount) {
  assert_equal(amount, dispensed_amount);
}

THEN("^the account balance should be (\d+)$") (int balance) {
  assert_equal(balance, account.balance);
}

THEN("^the card should be returned$") () {
  // assert card is returned
}

THEN("^the ATM should not dispense any money$") () {
  assert_equal(0, dispensed_amount);
}

THEN("^the ATM should say there are insufficient funds$") () {
  assert_equal(ResultInsufficientFunds, result);
}

GIVEN("^the card is disabled$") () {
  card.valid = false;
}

THEN("^the ATM should retain the card$") () {
  assert_equal(ResultCardRetained, result);
}

