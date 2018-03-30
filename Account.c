#include "Account.h"
#include "Account_Number_Set.h"
#define ACCOUNT_HOLDER_LENGTH 50
#define ADDRESS_LENGTH 50
#define PHONE_NUMBER_LENGTH 10

static struct Account_Number_Set *account_number_set = NULL;

static char *generate_account_number();

static void delete_Account(struct Account *this);

struct Account *new_Account(char *account_holder, char *address, char *phone_number, int account_type) {
	if (strlen(account_holder) < ACCOUNT_HOLDER_LENGTH && 
		strlen(address) < ADDRESS_LENGTH &&
		strlen(phone_number) <= PHONE_NUMBER_LENGTH) {

		struct Account *account = calloc(1, sizeof(struct Account));
		account->account_holder = calloc(strlen(account_holder) + 1, sizeof(char));
		account->address = calloc(strlen(address) + 1, sizeof(char));
		account->phone_number = calloc(strlen(phone_number) + 1, sizeof(char));
		strcpy(account->account_holder, account_holder);
		strcpy(account->address, address);
		strcpy(account->phone_number, phone_number);
		account->account_number = generate_account_number();
		account->balance = 0;
		account->account_type = account_type;
		account->delete_Account = &delete_Account;
		account->transaction_linked_list = create_transaction_linked_list();
		return account;
	}
	return NULL;
}

static void delete_Account(struct Account *this) {
	this->transaction_linked_list->delete_transaction_linked_list(this->transaction_linked_list);
	account_number_set->remove_account_number(account_number_set, this->account_number);
	free(this->account_holder);
	free(this->address);
	free(this->phone_number);
	free(this->account_number);
	free(this);
}

static char *generate_account_number() {
	int account_number = (rand() % 9999999) + 1000000;
	char *account_number_string = calloc(8, sizeof(char));
	sprintf(account_number_string, "%d", account_number);

	while(account_number_set->contains_account_number(account_number_set, account_number_string)) {
		account_number = (rand() % 9999999) + 1000000;
		sprintf(account_number_string, "%d", account_number);
	}
	account_number_set->put_account_number(account_number_set, account_number_string);
	return account_number_string;
}

void init_account_structure() {
	srand(time(NULL));
	if (account_number_set == NULL) {
		account_number_set = new_Account_Number_Set(1000);
	}
}