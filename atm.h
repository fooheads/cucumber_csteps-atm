#ifndef  _ATM__H_
#define  _ATM__H_

#include <stdbool.h>

typedef struct _ATM {
  int balance;
} ATM;

typedef struct _Account {
  int balance;
} Account;

typedef struct _Card {
  Account* account;
  bool valid;
} Card;

typedef enum _Result {
  ResultOk,
  ResultInsufficientFunds,
  ResultCardRetained,
} Result;

Result atm_withdraw(ATM* atm, Card* card, int amount, int* dispensed_amount);


#endif //_ATM__H_
