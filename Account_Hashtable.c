#include "Account_Hashtable.h"

static unsigned long hash(char *str);
static void put_account(struct Account_Hashtable *this, 
				 char *key, 
				 struct Account *account);
static const struct Account *get_account(struct Account_Hashtable *this,
				 				  char *key);
static void delete_Account_Hashtable(struct Account_Hashtable *this);
static void print_self(struct Account_Hashtable *this);

struct Account_Hashtable *new_Account_Hashtable(unsigned long n) {
	struct Account_Hashtable *account_hashtable = calloc(1, sizeof(struct Account_Hashtable));
	account_hashtable->size = n;
	account_hashtable->account_buckets = calloc(n, sizeof(struct Account_Bucket *));
	account_hashtable->put_account = &put_account;
	account_hashtable->get_account = &get_account;
	account_hashtable->delete_Account_Hashtable = &delete_Account_Hashtable;
	account_hashtable->print_self = &print_self;
	return account_hashtable;
}

static void delete_Account_Hashtable(struct Account_Hashtable *this) {
	struct Account_Bucket *account_bucket;
	struct Account_Bucket *next;

	for (int i = 0; i < this->size; ++i) {
		account_bucket = this->account_buckets[i];

		while (account_bucket != NULL) {
			free(account_bucket->key);
			next = account_bucket->next;
			account_bucket->account->delete_Account(account_bucket->account);
			free(account_bucket);
			account_bucket = next;
		}
	}

	free(this->account_buckets);
	free(this);
}

static void put_account(struct Account_Hashtable *this, 
				 char *key, 
				 struct Account *account) {
	unsigned long index = hash(key) % this->size;
	struct Account_Bucket *head = this->account_buckets[index];
	struct Account_Bucket *account_bucket = (struct Account_Bucket *) calloc(1, sizeof(struct Account_Bucket));
	struct Account_Bucket *temp_account_bucket = head;
	account_bucket->account = account;
	account_bucket->next = NULL;
	account_bucket->key = calloc(strlen(key) + 1, sizeof(char));
	strcpy(account_bucket->key, key);
	
	if (head == NULL) {
		head = account_bucket;
		this->account_buckets[index] = head;
	} else {
		while (temp_account_bucket->next != NULL) {
			if (strcmp(temp_account_bucket->key, key) == 0) {
				free(account_bucket->key);
				free(account_bucket);
				return;
			}
			temp_account_bucket = temp_account_bucket->next;
		}

		if (strcmp(temp_account_bucket->key, key) == 0) {
			free(account_bucket->key);
			free(account_bucket);
			return;
		}
		(temp_account_bucket->next) = account_bucket;
	}
}

static const struct Account *get_account(struct Account_Hashtable *this,
				 				  char *key)	{
	unsigned long index = hash(key) % this->size;
	struct Account_Bucket *account_bucket = this->account_buckets[index];

	while(account_bucket != NULL) {
		if (strcmp(account_bucket->key, key) == 0) {
			return account_bucket->account;
		}
		account_bucket = account_bucket->next;
	}
	return NULL;
}

static void print_self(struct Account_Hashtable *this) {
	for (int i = 0; i < this->size; ++i) {
		struct Account_Bucket *account_bucket = this->account_buckets[i];
		printf("array_index: %d\n", i);
		while(account_bucket != NULL) {
			printf("key: %s\n", account_bucket->key);
			account_bucket = account_bucket->next;
		}

	}
}

static unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int size = strlen(str);

    for (int i = 0; i < size; ++i) {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash;
}

  