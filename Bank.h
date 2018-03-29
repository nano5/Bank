#ifndef BANKH
#define BANKH

#define ACCOUNT_HASHTABLE_SIZE 1000
#include "Account_Hashtable.h"
#include "Account.h"
#include <stdlib.h>
struct Bank {
	struct Account_Hashtable *account_hashtable;
}; // will store all the accounts

struct Bank *new_Bank();

#endif