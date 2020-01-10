#include <iostream>
#include <cmath>

using namespace std;

void insertion_sort_rec(int *a, int f, int l);
void merge_sort_it(int *a, int n);
void merge(int *a, int f, int l, int m);
void swap(int *a, int *b);

int main()
{
	int i, n = 10;
	int a[] = { -5, 13, -32, 7, -3, 17, 23, 12, -35, 19 };
	//int a[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	//insertion_sort_rec(a, 1, 9);
	merge_sort_it(a, n);

	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

void insertion_sort_rec(int *a, int f, int l)
{
	int i, key;

	if (f < l)
	{
		key = a[f];
		i = f-1;
		while (i >= 0 && a[i] > key)
		{
			a[i+1] = a[i];
			i = i-1;
		}
		a[i+1] = key;
		insertion_sort_rec(a, f+1, l);
	}
}

void merge_sort_it(int *a, int n)
{
	int i, j, frame_size, f, l, m;
	int h = log2(n) + 1;

	for (i = 0; i < h; i++)
	{
		frame_size = pow(2, i);
		for (j = 0; j < n; j += 2*frame_size)
		{
			f = j;
			l = j + 2*frame_size - 1 < n ? j + 2*frame_size - 1 : n - 1;
			m = f + frame_size;
			merge(a, f, l, m);
		}
	}
}

void merge(int *a, int f, int l, int m)
{
	int i, len = l-f+1;
	int f1 = f, l1 = m-1;
	int f2 = m, l2 = l;
	int *new_a = new int[len]();

	for (i = 0; i < len; i++)
	{
		if (f1 <= l1 && (f2 > l2 || f2 <= l2 && a[f1] <= a[f2]))
			new_a[i] = a[f1++];
		else
			new_a[i] = a[f2++];
	}

	for (i = 0; i < len; i++)
	{
		a[f+i] = new_a[i];
	}

	delete new_a;
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
