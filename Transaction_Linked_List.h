#ifndef TRANSACTION_LINKED_LISTH
#define TRANSACTION_LINKED_LISTH
#include <stdio.h>
#include <stdlib.h>
#include "Account.h"

struct Transaction_Bucket {
	const struct Transaction *transaction;
	struct Transaction_Bucket *next;
};

struct Transaction_Linked_List *create_transaction_linked_list();

#endif