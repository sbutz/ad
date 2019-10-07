#include <stdio.h>

int euklid(unsigned int a, unsigned int b);
int euklid_rec(unsigned int a, unsigned int b);

int main() {
	int a = 36, b = 21;

	printf("GGT: %d, %d\n", euklid(a, b), euklid_rec(a, b));

	return 0;
}

int euklid(unsigned int a, unsigned int b) {
	int r;

	do {
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);

	return a;
}

int euklid_rec(unsigned int a, unsigned int b) {
	if (b == 0) {
		return a;
	} else {
		return euklid_rec(b, a % b);
	}
}
