#include <iostream>

using namespace std;

int main() {
	int n;

	cout << "¬ведите длину катетов: " << endl;
	cin >> n;

	if (n > 2) {
		int spaces = n - 1;
		int stars = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < spaces; j++) {
				cout << " ";
			}
			spaces--;

			for (int j = 0; j < stars; j++) {
				cout << "*";
			}
			stars++;

			cout << endl;
		}
	} else {
		cout << "„исло должно быть больше 2";
	}

	return 0;
}

