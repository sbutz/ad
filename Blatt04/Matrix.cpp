#include <cmath>
#include <cassert>

#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int m, int n, int val = 0) {
	int i, j;

	this->m = m;
	this->n = n;
	this->value = new int*[m];
	for (i = 0; i < m; i++) {
		this->value[i] = new int[n];
		for (j = 0; j < n; j++) {
			this->value[i][j] = val;
		}
	}
}

Matrix::Matrix(const Matrix &m) {
	int i, j;

	this->m = m.getM();
	this->n = m.getN();
	this->value = new int*[this->m];
	for (i = 0; i < this->m; i++) {
		this->value[i] = new int[this->n];
		for (j = 0; j < this->n; j++) {
			this->value[i][j] = m.getValueAt(i, j);
		}
	}
}

Matrix Matrix::input() {
	int i, j, m, n, val;

	cout << "Geben Sie die Hoehe ein: ";
	cin >> m;
	cout << "Geben Sie die Breite ein: ";
	cin >> n;
	Matrix matrix = Matrix(m, n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout << "Geben Sie einen Wert ein: ";
			cin >> val;
			matrix.setValueAt(i, j, val);
		}
	}

	return matrix;
}

int Matrix::getM() const {
	return this->m;
}

int Matrix::getN() const {
	return this->n;
}

int Matrix::getValueAt(int m, int n) const {
	return this->value[m][n];
}

void Matrix::setValueAt(int m, int n, int val) {
	this->value[m][n] = val;
}

Matrix Matrix::mul(const Matrix &m) {
	//TODO: use derived class (cubic -> cubic_exp2)
	assert(this->m == this->n);
	assert(m.getM() == m.getN());
	assert(this->m == m.getM());
	assert(log2(this->m) == floor(log2(this->m)));

	if (this->m == 1) {
		Matrix o = Matrix(1, 1, this->getValueAt(0, 0) * m.getValueAt(0,0));
		return o;
	} else {
		int i, j, len;
		len = this->n/2;

		Matrix m1 = Matrix(len, len, 0);
		Matrix m2 = Matrix(len, len, 0);
		Matrix m3 = Matrix(len, len, 0);
		Matrix m4 = Matrix(len, len, 0);

		Matrix n1 = Matrix(len, len, 0);
		Matrix n2 = Matrix(len, len, 0);
		Matrix n3 = Matrix(len, len, 0);
		Matrix n4 = Matrix(len, len, 0);

		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				m1.setValueAt(i, j, this->getValueAt(i, j));
				m2.setValueAt(i, j, this->getValueAt(i + len, j));
				m3.setValueAt(i, j, this->getValueAt(i, j + len));
				m4.setValueAt(i, j, this->getValueAt(i + len, j + len));
				n1.setValueAt(i, j, m.getValueAt(i, j));
				n2.setValueAt(i, j, m.getValueAt(i + len, j));
				n3.setValueAt(i, j, m.getValueAt(i, j + len));
				n4.setValueAt(i, j, m.getValueAt(i + len, j + len));
			}
		}

		Matrix h1 = (m1 + m4).mul(n1 + n4);
		Matrix h2 = (m3 + m4).mul(n1);
		Matrix h3 = m1.mul(n2-n4);
		Matrix h4 = m4.mul(n3-n1);
		Matrix h5 = (m1 + m2).mul(n4);
		Matrix h6 = (m3 - m1).mul(n1 + n2);
		Matrix h7 = (m2 - m4).mul(n3 + n4);

		Matrix o1 = h1 + h4 - h5 + h7;
		Matrix o2 = h3 + h5;
		Matrix o3 = h2 + h4;
		Matrix o4 = h1 - h2 + h3 + h6;

		Matrix o = Matrix(this->m, this->m, 0);
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				
				o.setValueAt(i, j, o1.getValueAt(i, j));
				o.setValueAt(i+len, j, o2.getValueAt(i, j));
				o.setValueAt(i, j+len, o3.getValueAt(i, j));
				o.setValueAt(i+len, j+len, o4.getValueAt(i, j));
			}
		}
		
		return o;
	}

}

Matrix operator+(const Matrix &m1, const Matrix &m2) {
	int i, j, m, n;
	m = m1.getM();
	n = m1.getN();
	Matrix matrix = Matrix(m, n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			matrix.setValueAt(i, j, m1.getValueAt(i, j) + m2.getValueAt(i, j));
		}
	}

	return matrix;
}

Matrix operator-(const Matrix &m1, const Matrix &m2) {
	int i, j, m, n;
	m = m1.getM();
	n = m1.getN();
	Matrix matrix = Matrix(m, n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			matrix.setValueAt(i, j, m1.getValueAt(i, j) - m2.getValueAt(i, j));
		}
	}

	return matrix;
}

Matrix operator*(const Matrix &m1, const Matrix &m2) {
	assert(m1.getN() == m2.getM());

	int i, j, k, m, n, r, val;
	m = m1.getM();
	n = m2.getN();
	r = m1.getN();
	Matrix matrix = Matrix(m, n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			val = 0;
			for (k = 0; k < r; k++) {
				val += m1.getValueAt(i, k) * m2.getValueAt(k, j);
			}
			matrix.setValueAt(i, j, val);
		}
	}

	return matrix;
}

ostream& operator<<(ostream& out, const Matrix matrix) {
	int i, j, m, n;
	for (m = matrix.getM(), n = matrix.getN(), i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			out << matrix.getValueAt(i, j);
			out << ' ';
		}
		out << '\n';
	}
	return out;
}
