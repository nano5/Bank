#include "Account_Hashtable.h"
#include "Account_Number_Set.h"
#include "Account.h"
#include "Transaction_Linked_List.h"
#include "Transaction.h"

void put_account();
void put_account2();
void put_account_number();
void put_account_number2();
void delete_Account_Number_Set();
void new_account();
void remove_account_number();
void insert();
void add();
void my_remove();
void assert(int result);

int main() {
	put_account();
	put_account2();
	put_account_number();
	put_account_number2();
	delete_Account_Number_Set();
	init_account_structure();
	new_account();
	remove_account_number();
	insert();
	add();
	my_remove();
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

	
}

void put_account2() {
	struct Account_Hashtable *account_hashtable = new_Account_Hashtable(10);

	
}

void put_account_number() {
	struct Account_Number_Set *account_number_set = new_Account_Number_Set(10);
	account_number_set->put_account_number(account_number_set, "1234567");
	int good_result = account_number_set->contains_account_number(account_number_set, "1234567");
	int bad_result = account_number_set->contains_account_number(account_number_set, "1");

	assert(good_result == 1);
	assert(bad_result == 0);
}

void put_account_number2() {
	struct Account_Number_Set *account_number_set = new_Account_Number_Set(1);
	account_number_set->put_account_number(account_number_set, "1234567");
	int good_result = account_number_set->contains_account_number(account_number_set, "1234567");
	int bad_result = account_number_set->contains_account_number(account_number_set, "1");
	account_number_set->delete_Account_Number_Set(account_number_set);
	assert(good_result == 1);
	assert(bad_result == 0);
}

void delete_Account_Number_Set() {
	struct Account_Number_Set *account_number_set = new_Account_Number_Set(5);
	account_number_set->put_account_number(account_number_set, "1234567");
	account_number_set->put_account_number(account_number_set, "1234567");
	account_number_set->put_account_number(account_number_set, "554342");
	account_number_set->put_account_number(account_number_set, "98589");
	account_number_set->put_account_number(account_number_set, "324352");
	account_number_set->put_account_number(account_number_set, "5463552");
	//account_number_set->print_self(account_number_set);
	assert(account_number_set->contains_account_number(account_number_set, "1234567") == 1);
	assert(account_number_set->contains_account_number(account_number_set, "554342") == 1);
	assert(account_number_set->contains_account_number(account_number_set, "98589") == 1);
	assert(account_number_set->contains_account_number(account_number_set, "324352") == 1);
	assert(account_number_set->contains_account_number(account_number_set, "5463552") == 1);
	account_number_set->delete_Account_Number_Set(account_number_set);
}


//struct Account *new_Account(char *account_holder, char *address, char *phone_number, int account_type);
void new_account() {
	struct Account *account = new_Account("Christiano Contreras", "11803 Kings Arms", "5103759223", CHECKING);
	struct Account *account2 = new_Account("Christiano Contreras", "11803 Kings Arms", "5103759223", CHECKING);
	account->delete_Account(account);
	account->delete_Account(account2);
}

void remove_account_number() {
	struct Account_Number_Set *account_number_set = new_Account_Number_Set(15);
	account_number_set->put_account_number(account_number_set, "1234567");
	assert(account_number_set->contains_account_number(account_number_set, "1234567"));
	account_number_set->remove_account_number(account_number_set, "1234567");
	assert(account_number_set->contains_account_number(account_number_set, "1234567") == 0);
	account_number_set->delete_Account_Number_Set(account_number_set);
}

void insert() {
	struct Transaction *transaction1 = create_withdraw_transaction(50, 1);
	struct Transaction *transaction2 = create_deposit_transaction(100, 3);
	struct Transaction *transaction3 = create_withdraw_transaction(1000, 5);
	struct Transaction_Linked_List *transaction_linked_list = create_transaction_linked_list();
	transaction_linked_list->insert(transaction_linked_list, transaction1, 0);
	transaction_linked_list->insert(transaction_linked_list, transaction2, 0);
	transaction_linked_list->insert(transaction_linked_list, transaction3, 0);
}

void add() {
	struct Transaction *transaction1 = create_withdraw_transaction(50, 1);
	struct Transaction *transaction2 = create_deposit_transaction(100, 3);
	struct Transaction *transaction3 = create_withdraw_transaction(1000, 5);
	struct Transaction_Linked_List *transaction_linked_list = create_transaction_linked_list();
	transaction_linked_list->add(transaction_linked_list, transaction1);
	transaction_linked_list->add(transaction_linked_list, transaction2);
	transaction_linked_list->add(transaction_linked_list, transaction3);
}

void my_remove() {
	struct Transaction *transaction1 = create_withdraw_transaction(50, 1);
	struct Transaction *transaction2 = create_deposit_transaction(100, 3);
	struct Transaction *transaction3 = create_withdraw_transaction(1000, 5);
	struct Transaction_Linked_List *transaction_linked_list = create_transaction_linked_list();
	transaction_linked_list->add(transaction_linked_list, transaction1);
	transaction_linked_list->add(transaction_linked_list, transaction2);
	transaction_linked_list->add(transaction_linked_list, transaction3);
	transaction_linked_list->remove(transaction_linked_list, transaction1);
	transaction_linked_list->remove(transaction_linked_list, transaction3);
	transaction_linked_list->remove(transaction_linked_list, transaction2);
}

