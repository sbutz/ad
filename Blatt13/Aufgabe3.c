#include <stdio.h>
#include <stdlib.h>

#define V 6
#define INF 2147483647

int min(int a, int b);
int** floyd_warshall(int **w, int v);

int main()
{
	int g[V][V] = {
		{  0, INF, INF, INF,  -1, INF},
		{  1,   0, INF,   2, INF, INF},
		{INF,   2,   0, INF, INF,  -8},
		{ -4, INF, INF,   0,   3, INF},
		{INF,   7, INF, INF,   0, INF},
		{INF,   5,  10, INF, INF,   0}
	};
	int *W[V] = {&g[0][0], &g[1][0], &g[2][0], &g[3][0], &g[4][0], &g[5][0]};
	int i, j, **D;

	D = floyd_warshall((int **) W, V);

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			if (D[i][j] == INF)
				printf(" ∞ ");
			else
				printf("%2d ", D[i][j]);
		}
		printf("\n");

		free(D[i]);
	}
	free(D);
}

int min(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int** floyd_warshall(int **w, int v)
{
	int **d0, **d1, **prev, **next;
	int i, j, k;

	d0 = malloc(sizeof(int *) * v);
	d1 = malloc(sizeof(int *) * v);
	for (i = 0; i < v; i++)
	{
		d0[i] = malloc(sizeof(int) * v);
		d1[i] = malloc(sizeof(int) * v);
	}


	for (k = 0; k < v; k++)
	{
		if (k & 1)
		{
			prev = d1;
			next = d0;
		}
		else
		{
			if (k == 0)
				prev = w;
			else
				prev = d0;
			next = d1;
		}

		for (i = 0; i < v; i++)
		{
			for (j = 0; j < v; j++)
			{
				if (prev[i][k] != INF && prev[k][j] != INF)
					next[i][j] = min(prev[i][j], prev[i][k] + prev[k][j]);
				else
					next[i][j] = prev[i][j];
			}
		}

		for (i = 0; i < v; i++)
		{
			for (j = 0; j < v; j++)
			{
				if (next[i][j] == INF)
					printf(" ∞ ");
				else
					printf("%2d ", next[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	for (i = 0; i < v; i++)
		free(prev[i]);
	free(prev);

	return next;
}
