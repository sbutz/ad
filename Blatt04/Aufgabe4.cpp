#include <iostream>
#include <cmath>
#include <ctime>

#include "Matrix.hpp"

using namespace std;

int main()
{
	time_t start, end;
	int n = pow(2, 10);
	

	Matrix m1 = Matrix(n, n, 1);
	Matrix m2 = Matrix(n, n, 2);

	start = time(NULL);
	Matrix m3 = m1 * m2;
	end = time(NULL);
	cout << "Standard Methode: " << difftime(end, start) << endl;


	start = time(NULL);
	Matrix m4 = m1.mul(m2);
	end = time(NULL);
	cout << "Standard Methode: " << difftime(end, start) << endl;

	return 0;
}
