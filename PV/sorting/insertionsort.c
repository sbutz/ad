#include <stdio.h>

void swap(int *a, int *b);
void insertionsort(int *a, int n);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	insertionsort(a, 10);

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertionsort(int *a, int n)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = a[i];

		for (j = i-1; j >= 0 && a[j] > key; j--)
			a[j+1] = a[j];

		a[j+1] = key;
	}
}
