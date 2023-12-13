#include <iostream>

using namespace std;

int main() {
	int n;
	int revers = 0;

	cout << "¬ведите число: " << endl;
	cin >> n;

	while (n > 0) {
		revers = (revers * 10) + (n % 10);
		n /= 10;
	}

	cout << revers;

	return 0;
}