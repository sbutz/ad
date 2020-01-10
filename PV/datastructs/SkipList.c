#include <stdio.h>
#include <stdlib.h>

#define H 8

typedef struct node {
	struct node **next;
	int value, height;
} node;

typedef struct {
	node *head, *tail;
} skip_list;

void node_init(node *n, int height, int value);
void node_destroy(node *n);

void skip_list_init(skip_list *l);
void skip_list_destroy(skip_list *l);
void skip_list_print(skip_list *l);
int skip_list_contains(skip_list *l, int value);
void skip_list_insert(skip_list *l, int value);
void skip_list_remove(skip_list *l, int value);

int main()
{
	skip_list l;

	skip_list_init(&l);


	skip_list_insert(&l, 5);
	skip_list_insert(&l, 1);
	skip_list_insert(&l, 13);
	skip_list_insert(&l, 7);

	skip_list_print(&l);

	skip_list_remove(&l, 5);
	skip_list_remove(&l, 1);

	skip_list_print(&l);


	skip_list_destroy(&l);

	return 0;
}

void node_init(node *n, int height, int value)
{
	int i;

	n->next = malloc(sizeof(node*) * height);

	for (i = 0; i < height; i++)
		n->next[i] = NULL;

	n->height = height;
	n->value = value;
}

void node_destroy(node *n)
{
	free(n->next);
	free(n);
}

void skip_list_init(skip_list *l)
{
	int i;

	l->head = malloc(sizeof(node));
	node_init(l->head, H, 0);

	l->tail = malloc(sizeof(node));
	node_init(l->tail, H, 0);

	for (i = 0; i < H; i++)
		l->head->next[i] = l->tail;

	//TODO: srand(time);
}

void skip_list_destroy(skip_list *l)
{
	node *ptr, *next;

	ptr = l->head;
	while (ptr != NULL)
	{
		next = ptr->next[0];
		node_destroy(ptr);
		ptr = next;
	}

	l->head = NULL;
	l->tail = NULL;
}

void skip_list_print(skip_list *l)
{
	int i;
	node *ptr;

	for (i = H-1; i >= 0; i--)
	{
		printf("Level %d: ", i);
		ptr = l->head->next[i];
		while (ptr != l->tail)
		{
			printf("%d ", ptr->value);
			ptr = ptr->next[i];
		}
		printf("\n");
	}
}

int skip_list_contains(skip_list *l, int value)
{
	node *ptr;
	int level;

	level = H-1;
	ptr = l->head;
	while (ptr != l->tail)
	{
		if (ptr->value == value && ptr != l->head)
			return 1;
		else if (ptr->next[level]->value > value)
			level--;
		else
			ptr = ptr->next[level];
	}

	return 0;
}

void skip_list_insert(skip_list *l, int value)
{
	int i, h, level;
	node *n, *ptr, *prev[H];

	for (i = 0; i < H; i++)
		prev[i] = l->head;

	level = H-1;
	ptr = l->head;
	while (ptr != l->tail && level >= 0)
	{
		if (ptr->next[level]->value >= value || ptr->next[level] == l->tail)
		{
			prev[level] = ptr;
			level--;
		}
		else
		{
			ptr = ptr->next[level];
		}
	}

	h = rand() % H;
	n = malloc(sizeof(node));
	node_init(n, h+1, value);

	for (i = 0; i <= h; i++)
	{
		n->next[i] = prev[i]->next[i];
		prev[i]->next[i] = n;
	}
}

void skip_list_remove(skip_list *l, int value)
{
	int i, level;
	node *ptr, *prev[H], *found;

	level = H-1;
	ptr = l->head;
	found = NULL;
	while (level >= 0)
	{
		if (ptr->next[level]->value == value && ptr->next[level] != l->tail)
		{
			found = ptr->next[level];
			prev[level] = ptr;
		}

		if (ptr->next[level] == l->tail || ptr->next[level]->value >= value)
			level--;
		else
			ptr = ptr->next[level];
	}

	if (found)
	{
		for (i = 0; i < found->height; i++)
			prev[i]->next[i] = found->next[i];
		node_destroy(found);
	}

}
