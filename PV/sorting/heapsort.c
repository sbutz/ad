#include <stdio.h>

void swap(int *a, int *b);
void heapsort(int *a, int n);
void build_heap(int *a, int n);
void heapify(int *a, int n, int p);

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};
	//int a[] = {7, 12, 5, 3, 8, 10};

	for (i = 0; i < ARRAY_SIZE(a); i++)
		printf("%d ", a[i]);
	printf("\n");

	heapsort(a, ARRAY_SIZE(a));

	for (i = 0; i < ARRAY_SIZE(a); i++)
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

#define PARENT(x) (x-1)/2
#define LEFT_CHILD(x) x*2+1
#define RIGHT_CHILD(x) x*2+2

void heapsort(int *a, int n)
{
	int i;

	build_heap(a, n);

	for (i = n-1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
}

void build_heap(int *a, int n)
{
	int i;

	for (i = n-1; i >= 0; i--)
		heapify(a, n, i);
}

void heapify(int *a, int n, int p)
{
	int r, l, max;

	l = LEFT_CHILD(p);
	r = RIGHT_CHILD(p);

	if (l < n)
	{
		if (r < n && a[r] > a[l])
			max = r;
		else
			max = l;

		if (a[p] < a[max])
		{
			swap(&a[p], &a[max]);
			heapify(a, n, max);
		}
	}
}
