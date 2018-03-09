#ifndef DEPOSITH
#define DEPOSITH

struct Deposit {
	int amount;
	int deposit_time;
	struct Deposit *next;
};

#endif