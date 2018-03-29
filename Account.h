#ifndef ACCOUNTH
#define ACCOUNTH

#include <stdlib.h>
#include <string.h>
#include <time.h>

// account types
#define SAVINGS 0
#define CHECKING 1
struct Account {
	char *account_holder;
	char *address;
	char *account_number;
	char *phone_number;
	int account_type;
	int balance;
	struct Transaction *head;

	void (*delete_Account)(struct Account *this);
};

struct Transaction {
	int transaction_type;
	int amount;
	int transaction_time;
	// + 4 bytes
	void (*delete_transaction)(struct Transaction *this); // 8 bytes
};

struct Account *new_Account(char *account_holder, char *address, char *phone_number, int account_type);

void init_account_structure();
#endif