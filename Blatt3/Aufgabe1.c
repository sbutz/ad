#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

void init_matrix(int a[N][N], int size);
void print_matrix(int a[N][N], int size);
int max_teil_sum(int a[N], int size);
int max_teil_sum_2d(int a[N][N], int size);

int main() {
	int max;
	int arr[N][N];

	init_matrix(arr, N);
	print_matrix(arr, N);
	max = max_teil_sum_2d(arr, N);
	printf("Maximale Teilsumme: %d\n", max);
	
	return 0;
}

void init_matrix(int a[N][N], int size) {
	int i, j, r;
	srand(5);

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			r = rand() % 20;
			r = r > 10 ? (r-20) : r;
			a[i][j] = r;
		}
	}
}

void print_matrix(int a[N][N], int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}

int max_teil_sum_2d(int a[N][N], int size) {
	int i, j, k, max, row_max;
	int *row;

	for (max = INT_MIN, i = 0; i < size; i++) {
		row = calloc(size, sizeof(int));
		for (j = i; j < size; j++) {
			for (k = 0; k < size; k++) {
				row[k] += a[j][k];
			}
			row_max = max_teil_sum(row, size);
			if (row_max > max) max = row_max;
		}
		free(row);
	}

	return max;
}

int max_teil_sum(int a[N], int size) {
	int i, s, max, aktSum;

	max = INT_MIN;
	aktSum = 0;
	for (i = 0; i < size; i++) {
		s = aktSum += a[i];
		if (s > a[i]) aktSum = s;
		else aktSum = a[i];
		if (aktSum > max) max = aktSum;
	}

	return max;
}
