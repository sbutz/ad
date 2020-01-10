#include <iostream>

#include "AvlTree.hpp"

int main()
{
	AvlTree<int> tree = AvlTree<int>();
	tree.add(5);
	tree.add(6);
	tree.add(9);
	tree.add(12);
	tree.add(13);

	tree.print();

	return 0;
}
