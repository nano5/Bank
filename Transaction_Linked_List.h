#ifndef TRANSACTION_LINKED_LISTH
#define TRANSACTION_LINKED_LISTH
#include <stdio.h>
#include <stdlib.h>
#include "Account.h"

struct Transaction_Linked_List {
	int size;
	struct Transaction_Bucket *head;
	struct Transaction_Bucket *tail;
	void (*insert)(struct Transaction_Linked_List *this, const struct Transaction *transaction, int index);
	void (*remove)(struct Transaction_Linked_List *this, const struct Transaction *transaction);
	void (*add)(struct Transaction_Linked_List *this, const struct Transaction *transaction);
	void (*print_self)(struct Transaction_Linked_List *this);
};

struct Transaction_Bucket {
	const struct Transaction *transaction;
	struct Transaction_Bucket *next;
};

struct Transaction_Linked_List *create_transaction_linked_list();

#endif