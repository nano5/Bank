#include "Transaction.h"

static void delete_transaction(struct Transaction *this);

static void delete_transaction(struct Transaction *this) {
	free(this);
}

struct Transaction *create_withdraw_transaction(int amount, int transaction_time) {
	struct Transaction *transaction = calloc(1, sizeof(struct Transaction));
	transaction->transaction_type = WITHDRAW;
	transaction->amount = amount;
	transaction->transaction_time = transaction_time;
	transaction->delete_transaction = &delete_transaction;
	return transaction;
}

struct Transaction *create_deposit_transaction(int amount, int transaction_time) {
	struct Transaction *transaction = calloc(1, sizeof(struct Transaction));
	transaction->transaction_type = DEPOSIT;
	transaction->amount = amount;
	transaction->transaction_time = transaction_time;
	transaction->delete_transaction = &delete_transaction;
	return transaction;
}

struct Transaction *create_transfer_transaction(int amount, int transaction_time, struct Account *sender, struct Account *receiver) {
	struct Transaction *transaction = calloc(1, sizeof(struct Transaction) + sizeof(struct Account *) * 2);
	char *helper_ptr = (char *) transaction;
	struct Account **ptr1 = ((struct Account **)(((char *) transaction) + 24));
	struct Account **ptr2 = ((struct Account **)(((char *) transaction) + 32));
	transaction->transaction_type = DEPOSIT;
	transaction->amount = amount;
	transaction->transaction_time = transaction_time;
	transaction->delete_transaction = &delete_transaction;
	*ptr1 = sender;
	*ptr2 = receiver;
	return transaction;
}

