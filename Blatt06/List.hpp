#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>

#include "ListItem.hpp"

using namespace std;

template<class T>
class List
{
	private:
		void quick_sort(ListItem<T> *f, ListItem<T> *l);
		ListItem<T> *quick_sort_prepare_partition(ListItem<T> *f, ListItem<T> *l);
	public:
		ListItem<T> *first;
		ListItem<T> *tail;
		List<T>();
		~List<T>();
		void append(T value);
		void sort();
};

template<class T>
List<T>::List()
{
	first = NULL;
	tail = NULL;
}

template<class T>
List<T>::~List()
{
	ListItem<T> *p, *tmp;

	p = this->tail;
	while (p != NULL)
	{
		tmp = p;
		p = p->prev;
		delete tmp;
	}
	this->first = NULL;
	this->tail = NULL;
}

template<class T>
void List<T>::append(T value)
{
	if (this->tail == NULL)
	{
		this->tail = new ListItem<T>(value);
		this->first = this->tail;
	}
	else
	{
		this->tail->next = new ListItem<T>(value, this->tail, NULL);
		this->tail = this->tail->next;
	}
}

template<class T>
void List<T>::sort()
{
	this->quick_sort(this->first, this->tail);
}

template<class T>
void List<T>::quick_sort(ListItem<T> *f, ListItem<T> *l)
{
	ListItem<T> *p;

	if (f != NULL && f < l)
	{
		p = this->quick_sort_prepare_partition(f, l);
		this->quick_sort(f, p);
		this->quick_sort(p->next, l);
	}
}

template<class T>
ListItem<T> *List<T>::quick_sort_prepare_partition(ListItem<T> *f, ListItem<T> *l)
{
	ListItem<T> *a, *p;
	T pivot, tmp;

	a = f;
	p = NULL;
	pivot = f->value;
	while (a != NULL && a != l->next)
	{
		if (a->value <= pivot)
		{
			p = (p == NULL) ? f : p->next;

			//swap
			tmp = a->value;
			a->value = p->value;
			p->value = tmp;
		}
		a = a->next;
	}
	f->value = p->value;
	p->value = pivot;
	
	return p;
}

template<class T>
ostream& operator<<(ostream& out, const List<T> &l)
{
	ListItem<T> *ptr = l.first;

	while (ptr != NULL)
	{
		out << ptr->value << " ";
		ptr = ptr->next;
	}
	out << endl;

	return out;
}

#endif
