#include "Transaction_Linked_List.h"

static void delete_transaction_linked_list(struct Transaction_Linked_List *this);
static void insert(struct Transaction_Linked_List *this, const struct Transaction *transaction, int index);
static void my_remove(struct Transaction_Linked_List *this, const struct Transaction *transaction);
static void add(struct Transaction_Linked_List *this, const struct Transaction *transaction);
static const struct Transaction_Bucket *front(struct Transaction_Linked_List *this);
static const struct Transaction_Bucket *back(struct Transaction_Linked_List *this);
static void print_self(struct Transaction_Linked_List *this);

struct Transaction_Linked_List *create_transaction_linked_list() {
	struct Transaction_Linked_List *transaction_linked_list = calloc(1, sizeof(struct Transaction_Linked_List));
	transaction_linked_list->size = 0;
	transaction_linked_list->head = NULL;
	transaction_linked_list->tail = NULL;
	transaction_linked_list->delete_transaction_linked_list = &delete_transaction_linked_list;
	transaction_linked_list->insert = &insert;
	transaction_linked_list->remove = &my_remove;
	transaction_linked_list->add = &add;
	transaction_linked_list->print_self = &print_self;
	return transaction_linked_list;
}

static void delete_transaction_linked_list(struct Transaction_Linked_List *this) {
	if (this == NULL) {
		return;
	}

	struct Transaction_Bucket *transaction_bucket = this->head;
	struct Transaction_Bucket *next = NULL;

	while (transaction_bucket != NULL) {
		next = transaction_bucket->next;
		free(transaction_bucket);
		transaction_bucket = next;
	}
	free(this);
}

static void insert(struct Transaction_Linked_List *this, const struct Transaction *transaction, int index) {
	if (this == NULL || transaction == NULL || index < 0) {
		return;
	}

	int i = 0;
	struct Transaction_Bucket *transaction_bucket = this->head;
	struct Transaction_Bucket *new_transaction_bucket = calloc(1, sizeof(struct Transaction_Bucket));
	struct Transaction_Bucket *next = NULL;
	new_transaction_bucket->transaction = transaction;

	// check if head is null
	if (transaction_bucket == NULL && index == 0) {
		this->head = new_transaction_bucket;
		this->tail = this->head;
		++(this->size);
		return;
	}

	// check if index is adding to back
	if (index == (this->size - 1)) {
		this->tail->next = new_transaction_bucket;
		this->tail = this->tail->next;
		++(this->size);
		return;
	}

	while(transaction_bucket != NULL) {
		next = transaction_bucket->next;

		if (i == index) {
			transaction_bucket->next = new_transaction_bucket;
			new_transaction_bucket->next = next;
			++(this->size);
			return;
		}

		transaction_bucket = next;
		++i;
	}

	free(new_transaction_bucket);

}

static void my_remove(struct Transaction_Linked_List *this, const struct Transaction *transaction) {
	if (this == NULL) {
		return;
	}

	struct Transaction_Bucket *transaction_bucket = this->head;
	struct Transaction_Bucket *prev = NULL;
	while(transaction_bucket != NULL) {
		if (transaction_bucket->transaction == transaction) {
			// check if this is the head
			if (prev == NULL) {
				this->head = NULL;
				// check if this is also the tail
				if (transaction_bucket->next == NULL) {
					this->tail = NULL;
				} else {
					this->head = transaction_bucket->next;
				}
			} else {
				// check if this is the tail
				if (transaction_bucket->next == NULL) {
					prev->next = NULL;
				} else {
					prev->next = transaction_bucket->next;
				}
			}
			--(this->size);
			free(transaction_bucket);
			return;
		}
		prev = transaction_bucket;
		transaction_bucket = transaction_bucket->next;
	}
}

static void add(struct Transaction_Linked_List *this, const struct Transaction *transaction) {
	if (this->head == NULL) {
		insert(this, transaction, 0);
	} else {
		insert(this, transaction, this->size - 1);
	}
}

static const struct Transaction_Bucket *front(struct Transaction_Linked_List *this) {
	return this->head;
}

static const struct Transaction_Bucket *back(struct Transaction_Linked_List *this) {
	return this->tail;
}

static void print_self(struct Transaction_Linked_List *this) {
	if (this == NULL) {
		return;
	}

	struct Transaction_Bucket *transaction_bucket = this->head;

	while(transaction_bucket != NULL) {
		printf("transaction_type: %d\n", transaction_bucket->transaction->transaction_type);
		printf("amount: %d\n", transaction_bucket->transaction->amount);
		printf("transaction_time: %d\n\n", transaction_bucket->transaction->transaction_time);
		transaction_bucket = transaction_bucket->next;
	}
}
