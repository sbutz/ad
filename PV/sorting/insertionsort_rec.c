#include <stdio.h>

void insertionsort_rec(int *a, int n, int i);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	insertionsort_rec(a, 10, 0);

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void insertionsort_rec(int *a, int n, int i)
{
	int j, key;

	if (i != n)
	{
		key = a[i];
		for (j = i-1; j >= 0 && a[j] > key; j--)
			a[j+1] = a[j];
		a[j+1] = key;

		insertionsort_rec(a, n, i+1);
	}
}
