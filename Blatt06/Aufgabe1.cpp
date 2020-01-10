#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int *count_sort(int *a, int n, int k);
void heap_sort(int *a, int f, int l);
void heapify(int *a, int f, int l, int root);
void swap(int *a, int *b);
void map_sort(int *a, int n, double c);

int main()
{
	int i, j, n, k = 1000, l = 10000;
	int *a, *b;
	time_t start, end;
	

	for (i = 1; i < 8; i++)
	{
		srand(i);
		n = pow(10, i);
		cout << n << endl;
		a = new int[n];

		cout << "n=" << n << endl;

		for (j = 0; j < n; j++)
			a[j] = (rand() % (l-k + 1)) + k;
		time(&start);
		heap_sort(a, 0, n-1);
		time(&end);
		cout << "heap_sort: " << difftime(end, start) << "s" << endl;

		for (j = 0; j < n; j++)
			a[j] = (rand() % (l-k + 1)) + k;
		time(&start);
		map_sort(a, n, 1.25);
		time(&end);
		cout << "map_sort: " << difftime(end, start) << "s" << endl;

		for (j = 0; j < n; j++)
			a[j] = (rand() % (l-k + 1)) + k;
		time(&start);
		b = count_sort(a, n, k);
		time(&end);
		cout << "count_sort: " << difftime(end, start) << "s" << endl;

		cout << endl;

		delete[] b;
		delete[] a;
	}
}

int *count_sort(int *a, int n, int k)
{
	int i;
	int *b, *c;

	c = new int[k+1];
	for (i = 0; i < k+1; i++)
		c[i] = 0;

	for (i = 0; i < n; i++)
		c[a[i]]++;

	for (i = 1; i < k+1; i++)
		c[i] += c[i-1];

	b = new int[n];
	for (i = n-1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}

	delete[] c;

	return b;
}

void heap_sort(int *a, int f, int l)
{
	int i;

	for (i = f+(l-f-1)/2; i >= f; i--)
		heapify(a, f, l, i);

	for (i = l; i > f; i--)
	{
		swap(a[f], a[i]);
		heapify(a, f, i-1, f);
	}
}

void heapify(int *a, int f, int l, int root)
{
	int max, left=f+(root-f)*2+1, right=f+(root-f)*2+2;

	if (left <= l && a[left] > a[root])
		max = left;
	else
		max = root;

	if (right <= l && a[right] > a[max])
		max = right;

	if (max != root)
	{
		swap(a[root], a[max]);
		heapify(a, f, l, max);
	}
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void map_sort(int *a, int n, double c)
{
	assert(c >= 1);
	int new_n, min, max, i, pos, left, j;
	double dist;
	int *b;

	new_n = (int) ((double) n*c);
	b = new int[new_n];

	for (i = 0; i < new_n; i++)
		b[i] = -1;

	min = INT_MAX;
	max = INT_MIN;
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}

	dist = ((double) (max - min)) / (new_n - 1);

	for (i = 0; i < n; i++)
	{
		pos = (int) ((double) (a[i] - min) / dist);
		left = 0;
		if (b[pos] != -1 && a[i] <= b[pos])
			left = 1;

		while (b[pos] != -1)
		{
			if (left == 1)
			{
				if(a[i] > b[pos])
					swap(b[pos], a[i]);
				if(pos > 0)
					pos--;
				 else
					left = 0;
			}
			else
			{
				if (a[i] <= b[pos])
					swap(b[pos], a[i]);
				if(pos < new_n-1)
					pos++;
				else
					left = 1;
			}
		}

		b[pos] = a[i];
	}

	for (j = 0, i = 0; i < new_n; i++)
	{
		if(b[i] != -1)
			a[j++] = b[i];
	}

	delete[] b;
}
