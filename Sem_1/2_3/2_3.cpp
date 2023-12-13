#include <iostream>

using namespace std;

int main() {
	int n, sum, temp;

	cout << "¬ведите число: " << endl;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		temp = 1;

		for (int j = i; j <= 2 * i; j++) {
			temp *= j;
		}

		sum += temp;
	}

	cout << "—умма: " << sum << endl;

	return 0;
}

