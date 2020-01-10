#include <iostream>
#include <stack>

using namespace std;

int ackermann_rec(unsigned int n, unsigned int m);
int ackermann_it(unsigned int n, unsigned int m);

int main() {
	unsigned int n = 2, m = 14;

	printf("ackermann_rec(%u, %u) = %d\n", n, m, ackermann_rec(n, m));
	printf("ackermann_it(%u, %u) = %d\n", n, m, ackermann_it(n, m));

	return 0;
}

int ackermann_rec(unsigned int n, unsigned int m) {
	if (n == 0) {
		return m+1;
	} else if (m == 0 && n >= 1) {
		return ackermann_rec(n-1, 1);
	} else {
		return ackermann_rec(n-1, ackermann_rec(n, m-1));
	}
}

int ackermann_it(unsigned int n, unsigned int m) {
	stack<int> s = stack<int>();

	s.push(n);
	while (!s.empty()) {
		if (n == 0) {
			n = s.top();
			s.pop();
			m = m+1;
		} else if (m == 0) {
			n = n-1;
			m = 1;
		} else {
			s.push(n-1);
			m = m-1;
		}
	}

	return m;
}
