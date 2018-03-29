#include "Bank.h"

int main() {
	return 0;
}

struct Bank *new_Bank() {
	struct Bank *bank = calloc(1, sizeof(struct Bank));
	return bank;
}
