#ifndef ACCOUNT_NUMBER_SETH
#define ACCOUNT_NUMBER_SETH
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct Account_Number_Set {
	unsigned long size;
	struct Account_Number_Bucket **account_number_buckets;
	void (*put_account_number) (struct Account_Number_Set *this, char *account_number);
	void (*delete_Account_Number_Set) (struct Account_Number_Set *this);
	void (*print_self) (struct Account_Number_Set *this);
	int (*contains_account_number) (struct Account_Number_Set *this, char *account_number);
};

struct Account_Number_Bucket {
	char *account_number;
	struct Account_Number_Bucket *next;
};

struct Account_Number_Set *new_Account_Number_Set(unsigned long n);

#endif