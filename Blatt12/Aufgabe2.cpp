#include <iostream>

#include "MinHeap.hpp"

using namespace std;

int main(void)
{
	MinHeap<int> heap = MinHeap<int>();

	heap.insert(0, 3);
	heap.insert(1, 1);
	heap.insert(2, 6);
	heap.insert(3, 5);
	heap.insert(4, 2);
	heap.insert(5, 4);

	heap.decreaseKey(5, 0);

	cout << heap.extractMin() << " " << heap.extractMin() << endl;
	cout << heap.extractMin() << " " << heap.extractMin() << endl;
	cout << heap.extractMin() << " " << heap.extractMin() << endl;

	return 0;
}
