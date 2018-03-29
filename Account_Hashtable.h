#ifndef ACCOUNT_HASHTABLEH
#define ACCOUNT_HASHTABLEH

#include "Account.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Account_Hashtable {
	unsigned long size;
	struct Account_Bucket **account_buckets;
	const struct Account *(*get_account)(struct Account_Hashtable *this, char *key);
	void (*put_account)(struct Account_Hashtable *this, 
				 		char *key, 
				 		struct Account *account);
	void (*delete_Account_Hashtable)(struct Account_Hashtable *this);
	void (*print_self)(struct Account_Hashtable *this);
};

struct Account_Bucket {
	char *key;
	struct Account *account;
	struct Account_Bucket *next;
};

struct Account_Hashtable *new_Account_Hashtable(unsigned long n);
#endif

