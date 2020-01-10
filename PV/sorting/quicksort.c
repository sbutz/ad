#include <stdio.h>

void swap(int *a, int *b);
void quicksort(int *a, int f, int l);
int prepare_partition(int *a, int f, int l);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	quicksort(a, 0, 10-1);

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

void quicksort(int *a, int f, int l)
{
	int p;

	if (f < l)
	{
		p = prepare_partition(a, f, l);
		quicksort(a, f, p-1);
		quicksort(a, p+1, l);
	}
}

int prepare_partition(int *a, int f, int l)
{
	int pivot, i, p;

	pivot = a[f];
	p = f-1;

	for (i = f; i <= l; i++)
	{
		if (a[i] <= pivot)
		{
			p++;
			swap(&a[i], &a[p]);
		}
	}

	swap(&a[p], &a[f]);

	return p;
}
