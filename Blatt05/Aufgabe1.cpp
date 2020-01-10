#include <iostream>

using namespace std;

void merge_sort(int *a, int f, int l);
void merge(int *a, int f, int l, int m);
void heap_sort(int *a, int f, int l);
void heapify(int *a, int f, int l, int root);
void swap(int *a, int *b);
void printa(int *a, int f, int l);

#define DEBUG

int main()
{
	int array[] = { -5, 13, -32, 7, -3, 17, 23, 12, -35, 19 };

	printa(array, 0, 9);
	//merge_sort(array, 0, 9);
	heap_sort(array, 0, 9);
	printa(array, 0, 9);

	return 0;
}

void merge_sort(int *a, int f, int l)
{
	int m;


	if (f < l) {
		printa(a, f, l);
		m = (f+l+1)/2;
		merge_sort(a, f, m-1);
		merge_sort(a, m, l);
		merge(a, f, l, m);
		printa(a, f, l);
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
		a[f+i] = new_a[i];

	delete new_a;
}

void heap_sort(int *a, int f, int l)
{
	int i;

	for (i = f+(l-f-1)/2; i >= f; i--)
		heapify(a, f, l, i);

	for (i = l; i > f; i--)
	{
		printa(a, f, l);
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

void printa(int *a, int f, int l)
{
	while (f < l)
		cout << a[f++] << " ";
	cout << endl;
}
