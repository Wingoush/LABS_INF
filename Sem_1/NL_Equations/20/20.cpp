#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//	f(x) = sqrt(1 - 0.4 * x^2) - arcsin(x) = 0  ||  [1;0]

	float x, m;

	x = 1;
	m = 1;

	double eps = 0.000001;

	while (abs(x - m) > eps) {
		m = x;

		x = m - (sqrt(1 - 0.4 * pow(m, 2)) - asin(m)) / ((-0.8 * m) / ((2 * pow(1 - 0.4 * pow(m, 2), 2)) - (1 / sqrt(1 - pow(m, 2)))));
	}

	cout << "Корень методом Ньютона: " << x << endl;

	return 0;
}