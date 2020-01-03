#include <iostream>

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

void cycles(int *vertices, int nodes);
void cycles_visit(int *vertices, char *colors, int nodes, int node);

int main()
{
	int size = 9;
	int vertices[] = {
		0, 3, 4, 7, 8, 11, 15, 16, 18,

		1, 2, 6,
		3,
		2, 3, 4,
		6,
		4, 5, 8,
		2, 3, 4, 7,
		7,
		3, 8,
		5,
	};

	cycles(vertices, size);

	return 0;
}

void cycles(int *vertices, int nodes)
{
	char *colors;
	int i;

	colors = new char[nodes];
	for (i = 0; i < nodes; i++)
		colors[i] = WHITE;

	for (i = 0; i < nodes; i++)
	{
		if (colors[i] == WHITE)
			cycles_visit(vertices, colors, nodes, i);
	}

	delete[] colors;
}

void cycles_visit(int *vertices, char *colors, int nodes, int node)
{
	int i;

	for (i = vertices[node]; i < vertices[node+1]; i++)
	{
		if (colors[vertices[i]] == WHITE)
			cycles_visit(vertices, colors, nodes, vertices[i]);
		else
			cout << "Zyklus";
	}
	colors[node] = BLACK;
}
