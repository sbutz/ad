#include <stdio.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

int better_naive_search(char *text, int n, char *pattern, int m);
int naive_search(char *text, int n, char *pattern, int m);

int main()
{
	int matches;
	char text[] = "ALGORITHMEN UND DATENSTRUKTURENDATEN";
	char pattern[] = "DATEN";

	matches = better_naive_search(text, ARRAY_SIZE(text), pattern,
		ARRAY_SIZE(pattern)-1);
	printf("Matches: %d\n", matches);

	return 0;
}

int naive_search(char *text, int n, char *pattern, int m)
{
	int count, i, j, match;

	count = 0;
	for (i = 0; i <= n-m; i++)
	{
		match = 1;
		for (j = 0; j < m; j++)
		{
			if (text[i+j] != pattern[j])
			{
				match = 0;
				break;
			}
		}
		if (match)
			count++;
	}

	return count;
}

int better_naive_search(char *text, int n, char *pattern, int m)
{
	int count, i, j, match;

	count = 0;
	for (i = 0; i < n-m+1; i++)
	{
		match = 1;
		for (j = 0; j < m; j++)
		{
			if (text[i+j] != pattern[j])
			{
				match = 0;
				break;
			}
		}
		if (match)
			count++;
		i+=j;
	}

	return count;
}
