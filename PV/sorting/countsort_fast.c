#include <stdio.h>
#include <stdlib.h>

void countsort_fast(int *a, int n, int k);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	countsort_fast(a, 10, 50);

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void countsort_fast(int *a, int n, int k)
{
	int *bin, *copy;
	int i, j;

	bin = malloc(k * sizeof(int));
	copy = malloc(n * sizeof(int));

	for (i = 0; i < k; i++)
		bin[i] = 0;

	for (i = 0; i < n; i++)
	{
		bin[a[i]]++;
		copy[i] = a[i];
	}

	for (i = 1; i < k; i++)
	{
		bin[i] += bin[i-1];
	}

	for (i = n-1; i >= 0; i--)
	{
		a[bin[copy[i]-1]] = copy[i];
		bin[copy[i]]--;
	}

	free(copy);
	free(bin);
}
