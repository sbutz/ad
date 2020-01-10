#include <iostream>

#include "Tree.hpp"

int main()
{
	Tree<int> tree = Tree<int>();
	tree.add(5);
	tree.add(1);
	tree.add(3);
	tree.add(10);
	tree.add(8);
	tree.add(12);
	tree.add(7);
	tree.add(9);
	tree.add(13);

	tree.print_inorder(tree.root);
	cout << endl;
	tree.remove(1);
	tree.print_inorder(tree.root);

	return 0;
}
