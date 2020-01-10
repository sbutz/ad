#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

using namespace std;

template<class T>
class TreeNode {
	public:
		T value;
		int height;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T value);
		TreeNode(T value, int height, TreeNode<T> *left, TreeNode<T> *right);
};

template<class T>
class AvlTree {
	private:
		TreeNode<T> *root;
		void erase(TreeNode<T> *node);
		void insert(TreeNode<T>* &node, T value);
		void print_inorder(TreeNode<T> *node);

	public:
		AvlTree();
		~AvlTree();
		void add(T value);
		void print();
		
};

template<class T>
TreeNode<T>::TreeNode(T value)
: value(value), height(0), left(nullptr), right(nullptr)
{
}

template<class T>
TreeNode<T>::TreeNode(T value, int height, TreeNode<T> *left, TreeNode<T> *right)
: value(value), height(height), left(left), right(right)
{
}

template<class T>
AvlTree<T>::AvlTree()
: root(nullptr)
{
}

template<class T>
AvlTree<T>::~AvlTree()
{
	this->erase(this->root);
	this->root = nullptr;
}

template<class T>
void AvlTree<T>::add(T value)
{
	this->insert(this->root, value);
}

template<class T>
void AvlTree<T>::insert(TreeNode<T>* &node, T value)
{
	if (node == nullptr)
	{
		node = new TreeNode<T>(value);
	}
	else if (value <= node->value)
	{
		this->insert(node->left, value);
		//this->checkRotationRight(node);
	}
	else
	{
		this->insert(node->right, value);
		//this->checkRotationLeft(node);
	}
}

template<class T>
void AvlTree<T>::erase(TreeNode<T> *node)
{
	if (node == nullptr)
		return;

	if (node->right != nullptr)
		this->erase(node->right);
	if (node->left != nullptr)
		this->erase(node->left);

	delete node;
}

template<class T>
void AvlTree<T>::print()
{
	this->print_inorder(this->root);
	cout << endl;
}

template<class T>
void AvlTree<T>::print_inorder(TreeNode<T> *node)
{
	if (node != nullptr)
	{
		this->print_inorder(node->left);
		cout << node->value << " ";
		this->print_inorder(node->right);
	}
}

#endif
