#ifndef ACCOUNTH
#define ACCOUNTH

#include "Deposit.h"

// account types
#define SAVINGS 0
#define CHECKING 1

struct Account {
	char *account_holder;
	char *address;
	char account_number[7];
	char phone_number[7];
	int account_type;
	int total_deposited;
	struct Deposit head;

};

#endif