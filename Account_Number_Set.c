#include "Account_Number_Set.h"

static void delete_Account_Number_Set(struct Account_Number_Set *this);
static unsigned long hash(char *str);
static char *create_account_number(struct Account_Number_Set *this);
static void put_account_number(struct Account_Number_Set *this, char *account_number);
static int contains_account_number(struct Account_Number_Set *this, char *account_number);
static void print_self(struct Account_Number_Set *this);

struct Account_Number_Set *new_Account_Number_Set(unsigned long n) {
	struct Account_Number_Set *account_number_set = calloc(1, sizeof(struct Account_Number_Set));
	account_number_set->account_number_buckets = calloc(n, sizeof(struct Account_Number_Set *));
	account_number_set->size = n;
    account_number_set->delete_Account_Number_Set = &delete_Account_Number_Set;
    account_number_set->put_account_number = &put_account_number;
    account_number_set->contains_account_number = &contains_account_number;
    account_number_set->print_self = &print_self;
    return account_number_set;
}

void delete_Account_Number_Set(struct Account_Number_Set *this) {
    for (int i = 0; i < 10; ++i) {
        struct Account_Number_Bucket *account_number_bucket = this->account_number_buckets[i];
        struct Account_Number_Bucket *next = NULL;

        while(account_number_bucket != NULL) {
            next = account_number_bucket->next;
            free(account_number_bucket->account_number);
            free(account_number_bucket);
            account_number_bucket = next;
        }
    }

    free(this->account_number_buckets);
    free(this);
}


static void put_account_number(struct Account_Number_Set *this, char *account_number) {
	unsigned long index = hash(account_number) % this->size;

	struct Account_Number_Bucket *head = this->account_number_buckets[index];
    struct Account_Number_Bucket *account_number_bucket = calloc(1, sizeof(struct Account_Number_Bucket));
    struct Account_Number_Bucket *temp_account_number_bucket = head;

    account_number_bucket->account_number = calloc(strlen(account_number), sizeof(char));
    account_number_bucket->next = NULL;

    strcpy(account_number_bucket->account_number, account_number);
    
    if (head == NULL) {
        this->account_number_buckets[index] = account_number_bucket;

    } else {
        temp_account_number_bucket = head;

        while(temp_account_number_bucket->next != NULL) {
            if (strcmp(temp_account_number_bucket->account_number, account_number) == 0) {
                free(account_number_bucket->account_number);
                free(account_number_bucket);
                return;
            }
            temp_account_number_bucket = temp_account_number_bucket->next;
        }

        temp_account_number_bucket->next = account_number_bucket;
    }
}

static int contains_account_number(struct Account_Number_Set *this, char *account_number) {
    unsigned long index = hash(account_number) % this->size;
    struct Account_Number_Bucket *head = this->account_number_buckets[index];
    struct Account_Number_Bucket *account_number_bucket = NULL;

    if (head == NULL) {
        return 0;
    }

    account_number_bucket = head;

    while(account_number_bucket != NULL) {
        if (strcmp(account_number_bucket->account_number, account_number) == 0) {
            return 1;
        }
        account_number_bucket = account_number_bucket->next;
    }

    return 0;
}

static void print_self(struct Account_Number_Set *this) {
    for (int i = 0; i < this->size; ++i) {
        struct Account_Number_Bucket *account_number_bucket = this->account_number_buckets[i];
        struct Account_Number_Bucket *next = NULL;

        while(account_number_bucket != NULL) {
            printf("account_number: %s\n", account_number_bucket->account_number);
            next = account_number_bucket->next;
            account_number_bucket = next;
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