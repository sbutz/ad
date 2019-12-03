#ifndef HASH_H
#define HASH_H

#include <iostream>

using namespace std;

template<class T>
class Hash
{
	private:
		T* bins;
		int size;
		void add_linear(T value, int i);
		void add_cubic(T value, int i);
		void add_double_hashing(T value, int i);

	public:
		Hash(int size);
		~Hash();
		void add(T value);
		int getSize();
		T getValue(int i);
};

template<class T>
Hash<T>::Hash(int size)
{
	this->size = size;
	this->bins = new T[size]();
}

template<class T>
Hash<T>::~Hash()
{
	delete[] this->bins;
}

template<class T>
void Hash<T>::add(T value)
{
	this->add_double_hashing(value, 0);
}

template<class T>
void Hash<T>::add_linear(T value, int i)
{
	int p = (value + i) % this->size;
	if (this->bins[p])
		this->add_linear(value, i+1);
	else
		this->bins[p] = value;
}

template<class T>
void Hash<T>::add_cubic(T value, int i)
{
	int p = (value + i*1 + i*i*3) % this->size;
	if (this->bins[p])
		this->add_cubic(value, i+1);
	else
		this->bins[p] = value;
}

template<class T>
void Hash<T>::add_double_hashing(T value, int i)
{
	int p = (value + i*(1 + value%(this->size-1))) % this->size;
	if (this->bins[p])
		this->add_double_hashing(value, i+1);
	else
		this->bins[p] = value;
}

template<class T>
int Hash<T>::getSize()
{
	return this->size;
}

template<class T>
T Hash<T>::getValue(int i)
{
	return this->bins[i];
}


template<class T>
ostream& operator<<(ostream& out, Hash<T> &h)
{
	int i, size;

	for (size = h.getSize(), i = 0; i < size; i++)
		out << h.getValue(i) << " ";
	out << endl;

	return out;
}


#endif
