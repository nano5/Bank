#ifndef ACCOUNT_HASHTABLEH
#define ACCOUNT_HASHTABLEH

#include "Account.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Account_Hashtable {
	int size;
	struct Account_Bucket **account_arr;
	void (*put_account)(struct Account_Hashtable *this, 
				 		char *key, 
				 		struct Account account);
	const struct Account *(*get_account)(struct Account_Hashtable *this, char *key);
};

struct Account_Bucket {
	char *key;
	struct Account account;
	struct Account_Bucket *next;
};

struct Account_Hashtable *new_Account_Hashtable(int n);
#endif

