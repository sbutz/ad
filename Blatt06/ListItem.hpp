#ifndef LIST_ITEM_H
#define LIST_ITEM_H

template<class T>
class ListItem
{
	public:
		ListItem<T>(T value);
		ListItem<T>(T value, ListItem<T> *prev, ListItem<T> *next);
		ListItem<T> *prev;
		ListItem<T> *next;
		T value;
};

template<class T>
ListItem<T>::ListItem(T value) : value(value), prev(NULL), next(NULL)
{
}

template<class T>
ListItem<T>::ListItem(T value, ListItem<T> *prev, ListItem<T> *next)
: value(value), prev(prev), next(next)
{
}

template<class T>
bool operator< (const ListItem<T> &l1, const ListItem<T> &l2)
{
	ListItem<T> *p;

	p = &l1->next;
	while (p != NULL)
	{
		if (p == &l2)
			return true;
		else
			p = p->next;
	}
	return false;
}

#endif
