#include <stdio.h>
#include <stdlib.h>

void countsort(int *a, int n, int min, int max);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	countsort(a, 10, 0, 50);

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

void countsort(int *a, int n, int min, int max)
{
	int *bin;
	int i, j, k;

	k = max - min;
	bin = malloc(k * sizeof(int));

	for (i = 0; i < k; i++)
		bin[i] = 0;

	for (i = 0; i < n; i++)
		bin[a[i]]++;

	j = 0;
	for (i = 0; i < n; i++)
	{
		while (bin[j] == 0) j++;
		a[i] = j;
		bin[j]--;
	}

	free(bin);
}
