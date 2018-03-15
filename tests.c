#include "Account_Hashtable.h"
#include "Account_Number_Set.h"

void put_account();
void put_account2();
void put_account_number();
void put_account_number2();
void delete_Account_Number_Set();
void assert(int result);

int main() {
	put_account();
	put_account2();
	// put_account_number();
	// put_account_number2();
	delete_Account_Number_Set();
	return 0;
}

void assert(int result) {
	if (!result) {
		printf("error\n");
		exit(1);
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
	account_hashtable->delete_Account_Hashtable(account_hashtable);
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
	account_hashtable->delete_Account_Hashtable(account_hashtable);
}

// void put_account_number() {
// 	struct Account_Number_Set *account_number_set = new_Account_Number_Set(10);
// 	account_number_set->put_account_number(account_number_set, "1234567");
// 	int good_result = account_number_set->contains_account_number(account_number_set, "1234567");
// 	int bad_result = account_number_set->contains_account_number(account_number_set, "1");

// 	assert(good_result == 1);
// 	assert(bad_result == 0);
// }

// void put_account_number2() {
// 	struct Account_Number_Set *account_number_set = new_Account_Number_Set(1);
// 	account_number_set->put_account_number(account_number_set, "1234567");
// 	int good_result = account_number_set->contains_account_number(account_number_set, "1234567");
// 	int bad_result = account_number_set->contains_account_number(account_number_set, "1");

// 	assert(good_result == 1);
// 	assert(bad_result == 0);
// }

void delete_Account_Number_Set() {
	struct Account_Number_Set *account_number_set = new_Account_Number_Set(5);
	account_number_set->put_account_number(account_number_set, "1234567");
	account_number_set->put_account_number(account_number_set, "1234567");
	account_number_set->put_account_number(account_number_set, "554342");
	account_number_set->put_account_number(account_number_set, "98589");
	account_number_set->put_account_number(account_number_set, "324352");
	account_number_set->put_account_number(account_number_set, "5463552");
	account_number_set->print_self(account_number_set);
	// assert(account_number_set->contains_account_number(account_number_set, "1234567") == 1);
	// assert(account_number_set->contains_account_number(account_number_set, "554342") == 1);
	// assert(account_number_set->contains_account_number(account_number_set, "98589") == 1);
	// assert(account_number_set->contains_account_number(account_number_set, "324352") == 1);
	// assert(account_number_set->contains_account_number(account_number_set, "5463552") == 1);

}



