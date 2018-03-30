#ifndef ACCOUNTH
#define ACCOUNTH

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Transaction_Linked_List.h"

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
	struct Transaction_Linked_List *transaction_linked_list;

	void (*delete_Account)(struct Account *this);
};

struct Transaction {
	int transaction_type;
	int amount;
	int transaction_time;
	// + 4 bytes
	void (*delete_transaction)(struct Transaction *this); // 8 bytes
};

struct Transaction_Linked_List {
	int size;
	struct Transaction_Bucket *head;
	struct Transaction_Bucket *tail;
	void (*delete_transaction_linked_list)(struct Transaction_Linked_List *this);
	void (*insert)(struct Transaction_Linked_List *this, const struct Transaction *transaction, int index);
	void (*remove)(struct Transaction_Linked_List *this, const struct Transaction *transaction);
	void (*add)(struct Transaction_Linked_List *this, const struct Transaction *transaction);
	void (*print_self)(struct Transaction_Linked_List *this);
};

struct Account *new_Account(char *account_holder, char *address, char *phone_number, int account_type);

void init_account_structure();
#endif