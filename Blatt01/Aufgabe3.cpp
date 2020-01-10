#include <iostream>
#include <chrono>

class Matrix {
	protected:
		int **value;
		int m, n;

	public:
		Matrix(int m, int n, int val);
		static Matrix input();
		int getM() const;
		int getN() const;
		int getValueAt(int m, int n) const;
		void setValueAt(int m, int n, int val);
};

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

Matrix Matrix::input() {
	int i, j, m, n, val;

	std::cout << "Geben Sie die Hoehe ein: ";
	std::cin >> m;
	std::cout << "Geben Sie die Breite ein: ";
	std::cin >> n;
	Matrix matrix = Matrix(m, n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			std::cout << "Geben Sie einen Wert ein: ";
			std::cin >> val;
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

Matrix operator+(const Matrix &m1, const Matrix &m2) {
	int i, j, m, n;
	unsigned long long counter;
	m = m1.getM();
	n = m1.getN();
	Matrix matrix = Matrix(m, n);

	std::chrono::steady_clock::time_point begin =
		std::chrono::steady_clock::now();
	for (counter = 0, i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			matrix.setValueAt(i, j, m1.getValueAt(i, j) + m2.getValueAt(i, j));
			counter++;
		}
	}
	std::chrono::steady_clock::time_point end =
		std::chrono::steady_clock::now();
	std::cout << "Time difference = "
		<< std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count()
		<< "[µs]" << std::endl;
	std::cout << "Counter = " << counter << '\n';

	return matrix;
}

Matrix operator*(const Matrix &m1, const Matrix &m2) {
	int i, j, k, m, n, r, val;
	unsigned long long counter;
	m = m1.getM();
	n = m2.getN();
	r = m1.getN();
	Matrix matrix = Matrix(m, n);

	counter = 0;
	std::chrono::steady_clock::time_point begin =
		std::chrono::steady_clock::now();
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			val = 0;
			for (k = 0; k < r; k++) {
				val += m1.getValueAt(i, k) * m2.getValueAt(k, j);
				counter++;
			}
			matrix.setValueAt(i, j, val);
		}
	}
	std::chrono::steady_clock::time_point end =
		std::chrono::steady_clock::now();
	std::cout << "Time difference = "
		<< std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count()
		<< "[µs]" << std::endl;
	std::cout << "Counter = " << counter << '\n';

	return matrix;
}

std::ostream& operator<<(std::ostream& out, const Matrix matrix) {
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

int main() {
	int n;
	n = 20000;
	Matrix m1 = Matrix(n, n, 1);
	Matrix m2 = Matrix(n, n, 2);
	m1 + m2;

	/*
	Quadratisches Wachstum
	Groesse fuer t Zeit: n = ca. (t in ms * (1 / Zeit fuer 1x1))^(1/2)
	Zeit fuer 1x1 Matrix: ca. 1/100000 ms
	Fuer 1 min: n = ca. 77500
	Fuer 2 min: n = ca. 110000
	Fuer 5 min: n = ca. 173000
	Fuer 10 min: n = ca. 245000
	*/

	n = 2000;
	m1 = Matrix(n, n, 1);
	m2 = Matrix(n, n, 1);
	m1 * m2;

	/*
	Kubisches Wachstum!
	Groesse fuer t Zeit: n = ca. (t in ms * (1 / Zeit fuer 1x1))^(1/3)
	Zeit fuer 1x1 Matrix: ca. 1/125000 ms
	Fuer 1 min: n = ca. 2000
	Fuer 2 min: n = ca. 2500
	Fuer 5 min: n = ca. 3350
	Fuer 10 min: n = ca. 4200
	*/

	return 0;
}
