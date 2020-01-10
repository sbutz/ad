#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergesort_it(int *a, int f, int l);
void merge(int *a, int f, int l, int m);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	mergesort_it(a, 0, 10-1);

	printf("\n");
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void mergesort_it(int *a, int f, int l)
{

	int i, j, h, n, len;

	n = l-f+1;
	h = ceil(log2(n));

	for (i = 0; i < h; i++)
	{
		j = 0;
		len = pow(2, i);
		while (j + 2*len <= n)
		{
			merge(a, j, j+2*len-1, j+len-1);
			j += 2*len;
		}
		if (j + len < n)
			merge(a, j, n-1, j+len-1);
	}
}

void merge(int *a, int f, int l, int m)
{
	int i, f1, f2, l1, l2;
	int *new_a;

	new_a = malloc((l-f) * sizeof(int));
	f1 = f;
	l1 = m;
	f2 = m+1;
	l2 = l;

	for (i = f; i <= l; i++)
	{
		if (f1 <= l1 && (a[f1] < a[f2] || f2 > l2))
		{
			new_a[i-f] = a[f1];
			f1++;
		}
		else {
			new_a[i-f] = a[f2];
			f2++;
		}
	}


	for (i = f; i <= l; i++)
	{
		a[i] = new_a[i-f];
	}

	free(new_a);
}
