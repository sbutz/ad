#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <cassert>

using namespace std;

/*
	Platzkomplexitaet: O(n)
	Zeitkomplexitaet:
		Insert, ExtractMin, DecreaseKey: O(log(n)
		GetMin: O(1)
*/

template<typename T>
class Node
{
	public:
		T value;
		int key;
		Node(T value, int key);
};

template<typename T>
Node<T>::Node(T value, int key)
: value(value), key(key)
{
}

template<typename T>
class MinHeap
{
	private:
		static int PARENT(int i);
		static int LEFT(int i);
		static int RIGHT(int i);

		vector<Node<T>> nodes;
		void swap(int a, int b);
		void heapifyDown(int i);
		void heapifyUp(int i);

	public:
		MinHeap();
		~MinHeap();
		T extractMin();
		void decreaseKey(int pos, int key);
		T getMin();
		void insert(T value, int key);
};

template<typename T>
int MinHeap<T>::PARENT(int i)
{
	return (i-1)/2;
}

template<typename T>
int MinHeap<T>::LEFT(int i)
{
	return i*2 + 1;
}

template<typename T>
int MinHeap<T>::RIGHT(int i)
{
	return i*2 + 2;
}

template<typename T>
void MinHeap<T>::swap(int a, int b)
{
	Node<T> tmp = this->nodes.at(a);
	this->nodes.at(a) = this->nodes.at(b);
	this->nodes.at(b) = tmp;
}


template<typename T>
MinHeap<T>::MinHeap()
{
}

template<typename T>
MinHeap<T>::~MinHeap()
{
}

template<typename T>
void MinHeap<T>::heapifyDown(int i)
{
	int size, r, l, s;

	size = this->nodes.size();
	while (i < size)
	{
		r = RIGHT(i);
		l = LEFT(i);

		if (r < size && this->nodes[r].key < this->nodes[i].key)
			s = (this->nodes[r].key < this->nodes[l].key) ? r : l;
		else if (l < size && this->nodes[l].key < this->nodes[i].key)
			s = l;
		else
			break;

		swap(s, i);
		i = s;
	}
}

template<typename T>
void MinHeap<T>::heapifyUp(int i)
{
	assert(i < this->nodes.size());

	int parent;

	while (i != 0)
	{
		parent = PARENT(i);
		if (this->nodes[parent].key < this->nodes[i].key)
			break;

		swap(i, parent);
		i = parent;
	}
}

template<typename T>
void MinHeap<T>::decreaseKey(int pos, int key)
{
	assert(this->nodes.size() > pos);
	assert(this->nodes[pos].key > key);

	this->nodes[pos].key = key;

	this->heapifyUp(pos);
}

template<typename T>
T MinHeap<T>::getMin()
{
	assert(!this->nodes.empty());

	return this->nodes[0].value;
}

template<typename T>
T MinHeap<T>::extractMin()
{
	assert(!this->nodes.empty());

	T pop;

	swap(0, this->nodes.size()-1);

	pop = this->nodes.back().value;
	this->nodes.pop_back();

	this->heapifyDown(0);

	return pop;
}

template<typename T>
void MinHeap<T>::insert(T value, int key)
{
	this->nodes.push_back(Node<T>(value, key));
	this->heapifyUp(this->nodes.size()-1);
}


#endif
