#include <stdio.h>

void swap(int *a, int *b);
void selectionsort(int *a, int n);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	selectionsort(a, 10);

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

void selectionsort(int *a, int n)
{
	int i, j, min;

	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(&a[i], &a[min]);
	}
}
