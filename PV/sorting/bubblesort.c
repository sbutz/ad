#include <stdio.h>

void swap(int *a, int *b);
void bubblesort(int *a, int n);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	bubblesort(a, 10);

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

void bubblesort(int *a, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = n-2; j >= 0; j--)
		{
			if (a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
}
