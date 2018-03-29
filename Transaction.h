#ifndef TRANSACTIONH
#define TRANSACTIONH
#define WITHDRAW 0
#define DEPOSIT 1
#define TRANSFER 2
#include "Account.h"

struct Transaction *create_withdraw_transaction(int amount, int transaction_time);

struct Transaction *create_deposit_transaction(int amount, int transaction_time);

struct Transaction *create_transfer_transaction(int amount, int transaction_time, struct Account *sender, struct Account *receiver);


#endif