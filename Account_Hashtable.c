#include "Account_Hashtable.h"

static unsigned long hash(unsigned char *str);
static void put_account(struct Account_Hashtable *this, 
				 char *key, 
				 struct Account account);
static const struct Account *get_account(struct Account_Hashtable *this,
				 				  char *key);

struct Account_Hashtable *new_Account_Hashtable(int n) {
	struct Account_Hashtable *account_hashtable = calloc(1, sizeof(struct Account_Hashtable));
	account_hashtable->size = n;
	account_hashtable->account_arr = calloc(n, sizeof(struct Account_Bucket *));
	account_hashtable->put_account = &put_account;
	account_hashtable->get_account = &get_account;
	return account_hashtable;
}

static void put_account(struct Account_Hashtable *this, 
				 char *key, 
				 struct Account account) {
	unsigned long index = hash((unsigned char *)key) % this->size;
	struct Account_Bucket *head = this->account_arr[index];
	struct Account_Bucket *account_bucket = (struct Account_Bucket *) malloc(sizeof(struct Account_Bucket));
	account_bucket->account = account;
	account_bucket->next = NULL;
	account_bucket->key = malloc(sizeof(char) * strlen(key));
	strcpy(account_bucket->key, key);
	
	if (head == NULL) {
		head = account_bucket;
		this->account_arr[index] = head;
	} else {
		struct Account_Bucket *bucket = head;
		while (bucket->next != NULL) {
			if (strcmp(bucket->key, key) == 0) {
				free(account_bucket->key);
				free(account_bucket);
				return;
			}
			bucket = bucket->next;
		}

		if (strcmp(bucket->key, key) == 0) {
			free(account_bucket->key);
			free(account_bucket);
		}
		(bucket->next) = account_bucket;
	}
}

static const struct Account *get_account(struct Account_Hashtable *this,
				 				  char *key)	{
	unsigned long index = hash((unsigned char *)key) % this->size;
	struct Account_Bucket *head = this->account_arr[index];

	while(head != NULL) {
		if (strcmp(head->key, key) == 0) {
			return &head->account;
		}
		head = head->next;
	}
	return NULL;
}

static unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = (*str)))
    	++str;
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}