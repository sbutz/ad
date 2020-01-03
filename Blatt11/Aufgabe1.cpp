#include <iostream>
#include <queue>

using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

void bfs(int **matrix, int size);
void dfs(int **matrix, int size);
void dfs_visit(int **matrix, char *colors, int size, int node);

int main()
{
	int m[9][9] = {
		{0, 1, 1, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0},
		{1, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0},
		{1, 0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 1, 1, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 1, 0, 0, 0}
	};

	int **matrix = new int*[9];
	for (int i = 0; i < 9; i++)
		matrix[i] = (int *)(&m[i][0]);

	bfs(matrix, 9);
	dfs(matrix, 9);

	return 0;
}

void bfs(int **matrix, int size)
{
	char *colors;
	int i, node;
	queue<int> queue;

	colors = new char[size];
	for (i = 0; i < size; i++)
		colors[i] = WHITE;

	queue.push(0);
	do
	{
		node = queue.front();
		queue.pop();

		cout << node << " ";

		for (i = 0; i < size; i++)
		{
			if (matrix[node][i] != 0 && colors[i] == WHITE)
			{
				colors[i] = GREY;
				queue.push(i);
			}
		}
		colors[node] = BLACK;
	}
	while (!queue.empty());

	cout << endl;

	delete[] colors;
}

void dfs(int **matrix, int size)
{
	char *colors;
	int i;

	colors = new char[size];
	for (i = 0; i < size; i++)
		colors[i] = WHITE;

	for (i = 0; i < size; i++)
	{
		if (colors[i] == WHITE)
			dfs_visit(matrix, colors, size, i);
	}

	cout << endl;

	delete[] colors;
}

void dfs_visit(int **matrix, char *colors, int size, int node)
{
	int i;

	cout << node << " ";
	colors[node] = GREY;

	for (i = 0; i < size; i++)
	{
		if (matrix[node][i] != 0 && colors[i] == WHITE)
			dfs_visit(matrix, colors, size, i);
	}

	colors[node] = BLACK;
}
