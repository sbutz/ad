#include <iostream>

#include "SkipList.hpp"

using namespace std;

int main()
{
	SkipList<int> list = SkipList<int>(8);

	list.insert(5);
	list.insert(0);
	list.insert(2);
	list.insert(0);
	list.insert(2);
	list.insert(3);
	list.insert(10);
	list.insert(1);
	list.print();
	list.remove(10);
	list.remove(0);
	list.remove(2);
	list.print();

	return 0;
}
