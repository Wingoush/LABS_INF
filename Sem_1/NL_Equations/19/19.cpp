#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//	sqrt(1 - 0.4 * x^2) - arcsin(x) = 0 || [0;1]

	float x, M;
	double L = 1;

	x = 1;
	M = 0;

	double eps = 0.000001;

	while (abs(x - M) > eps) {
		M = x;
		x = L * (sqrt(1 - 0.4 * pow(M, 2)) - asin(M)) + M;
	}

	cout << "Корень методом итераций: " << x << endl;

	return 0;
}