#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//	f(x) = sqrt(1 - 0.4 * x^2) - arcsin(x) = 0  ||  [0;1]

	float a, b, c;
	float fA, fB, fC;

	double eps = 0.000001;

	a = 0;
	b = 1;

	while (b - a > eps) {
		c = (a + b) / 2;

		fA = (sqrt(1 - (0.4 * pow(a, 2))) - asin(a));
		fB = (sqrt(1 - (0.4 * pow(b, 2))) - asin(b));
		fC = (sqrt(1 - (0.4 * pow(c, 2))) - asin(c));

		if (fA * fC < 0) {
			b = c;
		} else if (fC * fB < 0) {
			a = c;
		} else {
			cout << "Что-то неверно" << endl;
		}
	}

	cout << "Корни методом половинного деления: " << a << " ; " << b << endl;

	return 0;
}