#include "Bank.h"
#include "Account_Hashtable.h"

int main() {
	return 0;
}

struct Bank *new_Bank() {
	struct Bank *bank = calloc(1, sizeof(struct Bank));
	bank->account_hashtable = new_Account_Hashtable(1000);
	return bank;
}
