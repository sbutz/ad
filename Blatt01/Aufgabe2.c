#include <stdio.h>

/*
Teilaufgabe 1: Sieb des Erastosthenes von Hand
1		2       3       -       5       -       7       -       -       --
11      --      13      --      --      --      17      --      19      --
--      --      23      --      --      --      --      --      29      --
31      --      --      --      --      --      37      --      --      --
41      --      43      --      --      --      47      --      --      --
--      --      53      --      --      --      --      --      59      --
61      --      --      --      --      --      67      --      --      --
71      --      73      --      --      --      --      --      79      --
--      --      83      --      --      --      --      --      89      --
--      --      --      --      --      --      97      --      --      ---
*/


void sieb_des_erastosthenes(int k);

int main() {
	sieb_des_erastosthenes(100000);

	return 0;
}

void sieb_des_erastosthenes(int k) {
	int i, j;
	int len = k - 1;
	int arr[len];

	for (i = 0; i < len; i++) {
		arr[i] = i + 2;
	}

	for (i = 0; i < len; i++) {
		if (arr[i] == -1)
			continue;

		for (j = i + arr[i]; j < len; j += arr[i]) {
			arr[j] = -1;
		}
	}

	for (i = 0; i < len; i++) {
		if (arr[i] == -1)
			continue;

		printf("%d ", arr[i]);
	}
}
