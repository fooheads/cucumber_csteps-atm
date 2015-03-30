#include "atm.h"

Result atm_withdraw(ATM* atm, Card* card, int amount, int* dispensed_amount) {
  *dispensed_amount = 0;

  if (!card->valid)
    return ResultCardRetained;

  Account* account = card->account;
  if (account->balance < amount)
    return ResultInsufficientFunds;

  account->balance -= amount;
  atm->balance -= amount;

  *dispensed_amount = amount;

  return ResultOk;
}
