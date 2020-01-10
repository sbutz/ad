#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void mapsort(int *a, int n, double c);


int main()
{
	int i;
	int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 7};

	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");

	mapsort(a, 10, 1.25);

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

void mapsort(int *a, int n, double c)
{
	int *bin;
	int k, i, j, newPos, left, max, min;
	double d;

	k = n * c;
	bin = malloc(k * sizeof(int));

	for (i = 0; i < k; i++)
		bin[i] = -1;

	d = ((double) max - min) / (k - 1);

	for (i = 0; i < n; i++)
	{
		newPos = ((double) a[i] - min) / d;

		if (bin[newPos] != -1 && bin[newPos] < a[i])
			left = 1;
		else
			left = 0;

		while (bin[newPos] != -1)
		{
			if (left == 1)
			{
				if (a[i] > bin[newPos])
					swap(&a[i], &bin[newPos]);

				if (newPos > 0)
					newPos--;
				else
					left = 0;
			}
			else
			{
				if (a[i] <= bin[newPos])
					swap(&a[i], &bin[newPos]);

				if (newPos+1 < k)
					newPos++;
				else
					left = 1;
			}
		}
		bin[newPos] = a[i];
	}

	j = 0;
	for (i = 0; i < n; i++)
	{
		if (bin[i] != 0)
		{
			a[j] = bin[i];
			j++;
		}
	}

	free(bin);
}
