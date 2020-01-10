#include <iostream>

using namespace std;

class Matrix {
	protected:
		int **value;
		int m, n;

	public:
		Matrix(int m, int n, int val);
		Matrix(const Matrix &m);
		static Matrix input();
		int getM() const;
		int getN() const;
		int getValueAt(int m, int n) const;
		void setValueAt(int m, int n, int val);
		Matrix mul(const Matrix &m);
};

Matrix operator+(const Matrix &m1, const Matrix &m2);
Matrix operator-(const Matrix &m1, const Matrix &m2);
Matrix operator*(const Matrix &m1, const Matrix &m2);

ostream& operator<<(ostream& out, const Matrix matrix);
