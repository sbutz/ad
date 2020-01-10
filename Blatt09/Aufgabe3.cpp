#include <iostream>

#include "Hash.hpp"

using namespace std;

int main()
{
	int values[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
	Hash<int> hash = Hash<int>(11);

	for(int i = 0; i < 9; i++)
		hash.add(values[i]);

	cout << hash;

	return 0;
}
