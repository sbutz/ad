#include <iostream>

#include "List.hpp"

using namespace std;

/*
 * Laufzeit der Sort-Methode ist gleich der Laufzeit des Standard Quicksort
 * Algorithmus. Der Speicherbedarf ist der der Liste.
 */

int main()
{
	List<int> list;

	list.append(5);
	list.append(1);
	list.append(3);
	list.append(2);
	list.append(4);

	cout << list;

	list.sort();
	cout << list;

	return 0;
}
