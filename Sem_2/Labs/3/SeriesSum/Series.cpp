#include <iostream>
#include <cmath>

using namespace std;

double fact(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

double func(int x, int n, int iteration) {
	if (iteration > n) { return 0; }
	double result = (pow((-1), iteration) * (pow((2 * x), (2 * iteration)) / fact(2 * iteration))) + func(x, n, iteration + 1);
	return result;
}

int main() {
	int x, n;
	cout << "Type 'x' and 'n': " << endl;
	cin >> x >> n;
	cout << "Function result: " << func(x, n, 1);

	return 0;
}
/*
Tests:

Test 1:
Type 'x' and 'n':
1
1
Function result: -2


Test 2:
Type 'x' and 'n':
2
7
Function result: -1.86065


Test 3:
Type 'x' and 'n':
6
2
Function result: 792
*/