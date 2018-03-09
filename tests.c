#include "Account_Hashtable.h"
void put_account();
void put_account2();
void assert(int result);

int main() {
	put_account();
	put_account2();
	return 0;
}

void assert(int result) {
	if (!result) {
		exit(0);
	}
}

void put_account() {
	struct Account_Hashtable *account_hashtable = new_Account_Hashtable(10);

	struct Account account;
	struct Account account2;
	const struct Account *account_ptr1;
	const struct Account *account_ptr2;
	
	account.account_holder = "nano";
	account2.account_holder = "nano2";
	account_hashtable->put_account(account_hashtable, "234tgt", account);
	account_hashtable->put_account(account_hashtable, "35y32", account2);
	account_ptr1 = account_hashtable->get_account(account_hashtable, "234tgt");
	account_ptr2 = account_hashtable->get_account(account_hashtable, "35y32");
	assert(strcmp(account_ptr1->account_holder, "nano") == 0);
	assert(strcmp(account_ptr2->account_holder, "nano2") == 0);

}

void put_account2() {
	struct Account_Hashtable *account_hashtable = new_Account_Hashtable(10);

	struct Account account;
	struct Account account2;
	const struct Account *account_ptr1;
	const struct Account *account_ptr2;

	account.account_holder = "nano";
	account2.account_holder = "nano2";
	account_hashtable->put_account(account_hashtable, "rwerw523rf", account);
	account_hashtable->put_account(account_hashtable, "213rt24wf", account2);
	account_ptr1 = account_hashtable->get_account(account_hashtable, "rwerw523rf");
	account_ptr2 = account_hashtable->get_account(account_hashtable, "213rt24wf");
	assert(strcmp(account_ptr1->account_holder, "nano") == 0);
	assert(strcmp(account_ptr2->account_holder, "nano2") == 0);
}