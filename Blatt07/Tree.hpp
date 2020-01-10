#ifndef TREE_H
#define TREE_H

#include <cassert>
#include <iostream>

using namespace std;

template<class T>
class TreeNode
{
	public:
		T value;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode<T>(T value);
		TreeNode<T>(T value, TreeNode<T> *left, TreeNode<T> *right);
};

template<class T>
class Tree
{
	private:
		TreeNode<T> *remove_rec(TreeNode<T> *node, T value);

	public:
		TreeNode<T> *root;

		Tree<T>();
		~Tree<T>();
		void add(T value);
		void erase(TreeNode<T> *node);
		void print_inorder(TreeNode<T> *node);
		void remove_it(T value);
		void remove(T value);
};


template<class T>
TreeNode<T>::TreeNode(T value)
: value(value), left(nullptr), right(nullptr)
{
}

template<class T>
TreeNode<T>::TreeNode(T value, TreeNode<T> *left, TreeNode<T> *right)
: value(value), left(left), right(right)
{
}


template<class T>
Tree<T>::Tree()
: root(nullptr)
{
}

template<class T>
Tree<T>::~Tree()
{
	if (this->root != nullptr)
		this->erase(this->root);
}

template<class T>
void Tree<T>::add(T value)
{
	TreeNode<T> *ptr;

	if (this->root == nullptr)
	{
		this->root = new TreeNode<T>(value);
	}
	else
	{
		ptr = this->root;
		do {
			if (value < ptr->value)
			{
				if (ptr->left == nullptr)
				{
					ptr->left = new TreeNode<T>(value);
					break;
				}
				ptr = ptr->left;
			}
			else
			{
				if (ptr->right == nullptr)
				{
					ptr->right = new TreeNode<T>(value);
					break;
				}
				ptr = ptr->right;
			}
		} while (ptr != nullptr);
	}
}

template<class T>
void Tree<T>::erase(TreeNode<T> *node)
{
	assert(node != nullptr);

	if (node->right != nullptr)
		this->erase(node->right);
	if (node->left != nullptr)
		this->erase(node->left);
	delete node;
}

template<class T>
void Tree<T>::print_inorder(TreeNode<T> *node)
{
	if (node != nullptr)
	{
		this->print_inorder(node->left);
		cout << node->value << " ";
		this->print_inorder(node->right);
	}
}

template<class T>
void Tree<T>::remove_it(T value)
{
	TreeNode<T> *ptr, *prev, *next;

	ptr = this->root;
	prev = nullptr;

	while (ptr->value != value)
	{
		prev = ptr;
		ptr = (value < ptr->value) ? ptr->left : ptr->right;
	}

	if (ptr->left == nullptr || ptr->left == nullptr)
	{
		if (ptr->left == nullptr)
			next = ptr->right;
		else
			next = ptr->left;

		if (value < prev->value)
			prev->left = next;
		else
			prev->right = next;
		delete ptr;
	}
	else
	{
		next = ptr->right;
		prev = ptr;
		while (next->left != nullptr)
		{
			prev = next;
			next = next->left;
		}

		if (prev == ptr)
			ptr->right = next->right;
		else
			prev->left = next->right;

		ptr->value = next->value;
		delete next;
	}
}

template<class T>
void Tree<T>::remove(T value)
{
	this->root = remove_rec(this->root, value);
}

template<class T>
TreeNode<T> *Tree<T>::remove_rec(TreeNode<T> *node, T value)
{
	TreeNode<T> *ptr, *prev;

	if (node == nullptr)
		return nullptr;

	if (value == node->value)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			delete node;
			return nullptr;
		}
		else if (node->left == nullptr)
		{
			ptr = node->right;
			delete node;
			return ptr;
		}
		else if (node->right == nullptr)
		{
			ptr = node->left;
			delete node;
			return ptr;
		}
		else
		{
			prev = node;
			ptr = node->right;
			while (ptr->left != nullptr)
			{
				prev = ptr;
				ptr = ptr->left;
			}

			if (prev == node)
				prev->right = ptr->right;
			else
				prev->left = nullptr;
			node->value = ptr->value;
			delete ptr;
		}
		
	}
	else if (value < node->value)
	{
		node->left = this->remove_rec(node->left, value);
	}
	else
	{
		node->right = this->remove_rec(node->right, value);
	}
	return node;
}

#endif
