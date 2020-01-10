#include <stdio.h>
#include <stdlib.h>

#define QUICK 1

#ifdef QUICK
	#define N 150000
#else
	#define N 118000
#endif

void init_arr(int *arr, int size);
void print_arr(int *arr, int size);
void bubble_sort(int *arr, int size);
void swap(int *a, int *b);
void quick_sort(int *a, int f, int l);
void quick_sort_prepare_partition(int *a, int f, int l, int *p);

int main() {
	int arr[N];

	init_arr(arr, N);
#ifdef QUICK
	quick_sort(arr, 0, N-1);
#else
	bubble_sort(arr, N);
#endif

	return 0;
}

void init_arr(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = rand() % 20;
	}
}

void print_arr(int *arr, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubble_sort(int *arr, int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void swap(int *a, int *b) {
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void quick_sort(int *a, int f, int l) {
	int p;
	if (f < l) {
		quick_sort_prepare_partition(a, f, l, &p);
		quick_sort(a, f, p-1);
		quick_sort(a, p+1, l);
	}
}

void quick_sort_prepare_partition(int *a, int f, int l, int *p) {
	int i, pivot;

	for (pivot = a[f], *p = f-1, i = 0; i <= l; i++) {
		if (a[i] <= pivot) {
			(*p)++;
			swap(&a[i], &a[*p]);
		}
	}
	swap(&a[f], &a[*p]);
}
