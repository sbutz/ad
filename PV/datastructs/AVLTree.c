#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *left, *right;
	int height, value;
} node;

typedef struct {
	node *root;
} avl_tree;

void node_init(node *n, int value);
void node_destroy(node **n);
void node_print_inorder(node *n);
int node_get_height(node *n);
void node_update_height(node *n);
void node_check_rotation_left(node **n);
void node_check_rotation_right(node **n);
void node_rotate_left(node **n);
void node_rotate_right(node **n);
void node_double_rotate_left(node **n);
void node_double_rotate_right(node **n);
void node_insert(node **n, int value);
void node_remove(node **n, int value);

void avl_tree_init(avl_tree *t);
void avl_tree_destroy(avl_tree *t);
void avl_tree_print_inorder(avl_tree *t);
int avl_tree_contains(avl_tree *t, int value);
void avl_tree_insert(avl_tree *t, int value);
void avl_tree_remove(avl_tree *t, int value);

int max(int a, int b);

int main()
{
	avl_tree t;

	avl_tree_init(&t);
	avl_tree_insert(&t, 7);
	avl_tree_insert(&t, 3);
	avl_tree_insert(&t, 1);
	avl_tree_insert(&t, 4);
	avl_tree_insert(&t, 5);

	avl_tree_remove(&t, 5);

	avl_tree_print_inorder(&t);

	avl_tree_destroy(&t);

	return 0;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void node_init(node *n, int value)
{
	n->left = NULL;
	n->right = NULL;
	n->value = value;
	n->height = 0;
}

void node_destroy(node **n)
{
	if (*n != NULL)
	{
		node_destroy(&(*n)->left);
		node_destroy(&(*n)->right);
		free(*n);
		*n = NULL;
	}
}

void node_print_inorder(node *n)
{
	if (n != NULL)
	{
		node_print_inorder(n->left);
		printf("%d ", n->value);
		node_print_inorder(n->right);
	}
}

int node_get_height(node *n)
{
	return n == NULL ? -1 : n->height;
}

void node_update_height(node *n)
{
	n->height = max(node_get_height(n->left), node_get_height(n->right)) + 1;
}

void node_rotate_left(node **n)
{
	node *tmp;

	tmp = (*n)->right;
	(*n)->right = tmp->left;
	tmp->left = *n;
	*n = tmp;

	node_update_height((*n)->left);
	node_update_height(*n);
}

void node_rotate_right(node **n)
{
	node *tmp;

	tmp = (*n)->left;
	(*n)->left = tmp->right;
	tmp->right = *n;
	*n = tmp;

	node_update_height((*n)->right);
	node_update_height(*n);
}

void node_double_rotate_left(node **n)
{
	node_rotate_right(&(*n)->right);
	node_rotate_left(n);
}

void node_double_rotate_right(node **n)
{
	node_rotate_left(&(*n)->left);
	node_rotate_right(n);
}

void node_check_rotation_left(node **n)
{
	node *right;

	right = (*n)->right;
	if (right != NULL)
	{
		if (node_get_height(right) - node_get_height((*n)->left) > 1)
		{
			if (node_get_height(right->right) > node_get_height(right->left))
				node_rotate_left(n);
			else
				node_double_rotate_left(n);
		}
		else
		{
			node_update_height(*n);
		}
	}
	else
	{
		node_update_height(*n);
	}
}

void node_check_rotation_right(node **n)
{
	node *left;

	left = (*n)->left;
	if (left != NULL)
	{
		if (node_get_height(left) - node_get_height((*n)->right) > 1)
		{
			if (node_get_height(left->left) > node_get_height(left->right))
				node_rotate_right(n);
			else
				node_double_rotate_right(n);
		}
		else
		{
			node_update_height(*n);
		}
	}
	else
	{
		node_update_height(*n);
	}
}

void node_insert(node **n, int value)
{
	if ((*n)->value > value)
	{
		if ((*n)->left == NULL)
		{
			(*n)->left = malloc(sizeof(node));
			node_init((*n)->left, value);
			node_update_height(*n);
		}
		else
		{
			node_insert(&(*n)->left, value);
			node_check_rotation_right(n);
		}
	}
	else
	{
		if ((*n)->right == NULL)
		{
			(*n)->right = malloc(sizeof(node));
			node_init((*n)->right, value);
			node_update_height(*n);
		}
		else
		{
			node_insert(&(*n)->right, value);
			node_check_rotation_left(n);
		}
	}
}

void node_remove(node **n, int value)
{
	node *tmp;

	if (*n != NULL)
	{
		if ((*n)->value == value)
		{
			if ((*n)->right != NULL)
			{
				if ((*n)->left != NULL)
				{
					tmp = (*n)->right;
					while (tmp->left != NULL)
						tmp = tmp->left;

					(*n)->value = tmp->value;
					node_remove(&(*n)->right, tmp->value);
				}
				else
				{
					tmp = *n;
					*n = (*n)->right;
					free(tmp);
				}
			}
			else if ((*n)->left != NULL)
			{
				tmp = *n;
				*n = (*n)->left;
				free(tmp);
			}
			else
			{
				node_destroy(n);
			}
		}
		else if ((*n)->value > value)
		{
			node_remove(&(*n)->left, value);
			node_check_rotation_right(n);
		}
		else
		{
			node_remove(&(*n)->right, value);
			node_check_rotation_left(n);
		}
	}
}

void avl_tree_init(avl_tree *t)
{
	t->root = NULL;
}

void avl_tree_destroy(avl_tree *t)
{
	node_destroy(&t->root);
}

void avl_tree_print_inorder(avl_tree *t)
{
	if (t->root != NULL)
	{
		node_print_inorder(t->root);
		printf("\n");
	}
	else
	{
		printf("Tree empty.\n");
	}
}

int avl_tree_contains(avl_tree *t, int value)
{
	node *n;

	n = t->root;
	while (n != NULL)
	{
		if (n->value == value)
			return 1;
		else if (n->value > value)
			n = n->left;
		else
			n = n->right;
	}
	return 0;
}

void avl_tree_insert(avl_tree *t, int value)
{
	if (t->root == NULL)
	{
		t->root = malloc(sizeof(node));
		node_init(t->root, value);
	}
	else
	{
		node_insert(&t->root, value);
	}
}

void avl_tree_remove(avl_tree *t, int value)
{
	node_remove(&t->root, value);
}
