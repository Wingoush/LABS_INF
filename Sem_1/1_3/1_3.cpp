#include <iostream>

using namespace std;

int main() {
	float a;

	cout << "¬ведите число: " << endl;
	cin >> a;

	if (a < 5) {
		cout << a * 3;
	} else if (a > 7) {
		cout << a + 3;
	} else {
		cout << a / 10;
	}

	return 0;
}