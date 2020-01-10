#include <iostream>
#include <cstdlib>

#define N 10
#define S 10

using namespace std;

int test(int *a, int size, int s);
int bisect(int *a, int f, int l, int s);
void merge_sort(int *a, int f, int l);
void merge(int *a, int f, int l, int m);

int main()
{
	int array[N];
	int i;

	srand(0);
	for (i = 0; i < N; i++)
	{
		array[i] = rand() % S;
		cout << array[i] << " ";
	}
	cout << endl;

	cout << test(array, N, 16) << endl;

	return 0;
}

int test(int *a, int size, int s)
{
	int i;

	merge_sort(a, 0, size-1);
	for (i = 0; i < size; i++) {
		if (bisect(a, i+1, size-1, s-a[i]))
			return 1;
	}

	return 0;
}

// Array muss sortiert sein
int bisect(int *a, int f, int l, int s)
{
	int m = (f+l+1)/2;
	
	if (a[m] == s)
		return 1;
	else if (f < l)
		return a[m] > s ? bisect(a, 0, m-1, s) : bisect(a, m, l, s);
	else
		return 0;
}

void merge_sort(int *a, int f, int l)
{
	int m;

	if (f < l) {
		m = (f+l+1)/2;
		merge_sort(a, f, m-1);
		merge_sort(a, m, l);
		merge(a, f, l, m);
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
