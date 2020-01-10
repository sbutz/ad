#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <iostream>

using namespace std;

template<class T>
class Node
{
	public:
		T value;
		int height;
		Node<T> **next;

		Node(T value, int height);
		~Node();
};

template<class T>
Node<T>::Node(T value, int height)
: value(value), height(height)
{
	this->next = new Node<T>*[height];
}

template<class T>
Node<T>::~Node()
{
	delete[] this->next;
}


template<class T>
class SkipList
{
	private:
		int height;
		Node<T> *head;
		Node<T> *tail;
		int randHeight();
	public:
		SkipList(int height);
		~SkipList();
		bool contains(T value);
		void insert(T value);
		void print();
		void remove(T value);
};


template<class T>
SkipList<T>::SkipList(int height)
: height(height)
{
	int i;

	this->head = new Node<T>(T(), height);
	this->tail = new Node<T>(T(), height);

	for (i = 0; i < height; i++)
	{
		this->head->next[i] = this->tail;
		this->tail->next[i] = nullptr;
	}

	srand(1);
}

template<class T>
SkipList<T>::~SkipList()
{
	Node<T> *ptr, *tmp;

	ptr = this->head;
	while (ptr != nullptr)
	{
		tmp = ptr->next[0];
		delete ptr;
		ptr = tmp;
	}
}

template<class T>
bool SkipList<T>::contains(T value)
{
	Node<T> *ptr;
	int level = this->height-1;

	ptr = this->head->next[level];
	while (level >= 0)
	{
		if (ptr->value == value && ptr != this->tail)
			return true;
		
		if (ptr == this->tail || ptr->next[level]->value > value)
			level--;
		else
			ptr = ptr->next[level];
	}

	return false;
}

template<class T>
int SkipList<T>::randHeight()
{
	int h = 0;
	while (rand()%2 && h < this->height)
		h++;

	return h;
}

template<class T>
void SkipList<T>::insert(T value)
{
	int h, level, i, len;
	Node<T> *ptr, *newNode;
	Node<T> **pos;

	h = this->randHeight();
	len = h > 0 ? h : 1;

	level = this->height-1;
	ptr = this->head;
	pos = new Node<T>*[len];
	while (level >= 0)
	{
		if (ptr->value == value && ptr != this->head && ptr != this->tail)
		{
			delete[] pos;
			return;
		}
		
		if (ptr->next[level] == this->tail || ptr->next[level]->value > value)
		{
			if (level < len)
				pos[level] = ptr;
			level--;
		}
		else
		{
			ptr = ptr->next[level];
		}
	}

	newNode = new Node<T>(value, len);
	for (i = 0; i < len; i++)
	{
		newNode->next[i] = pos[i]->next[i];
		pos[i]->next[i] = newNode;
	}

	delete[] pos;
}

template<class T>
void SkipList<T>::print()
{
	Node<T> *ptr;

	ptr = this->head->next[0];
	while (ptr != this->tail)
	{
		cout << ptr->value << " ";
		ptr = ptr->next[0];
	}
	cout << endl;
}

template<class T>
void SkipList<T>::remove(T value)
{
	int level, i;
	Node<T> *ptr, *tmp;
	Node<T> **pos;

	tmp = nullptr;
	level = this->height-1;
	ptr = this->head;
	pos = new Node<T>*[this->height];
	while (level >= 0)
	{
		if (ptr->next[level]->value == value && ptr->next[level] != this->tail)
		{
			tmp = ptr->next[level];
			pos[level] = ptr;
		}

		if (ptr->next[level] == this->tail || ptr->next[level]->value >= value)
			level--;
		else
			ptr = ptr->next[level];
	}

	if (tmp)
	{
		for (i = 0; i < tmp->height; i++)
			pos[i]->next[i] = tmp->next[i];
		delete tmp;
	}

	delete[] pos;
}

#endif
