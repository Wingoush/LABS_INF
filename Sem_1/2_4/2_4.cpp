#include <iostream>

using namespace std;

int main() {
	int n;

	cout << "¬ведите длину основани€: " << endl;
	cin >> n;

	if ((n > 3) && (n % 2 != 0)) {
		int spaces = n / 2;
		int stars = 1;

		for (int i = 0; i < (n + 1) / 2; i++) {
			for (int j = 0; j < spaces; j++) {
				cout << " ";
			}
			spaces--;

			for (int k = 0; k < stars; k++) {
				cout << "*";
			}
			stars += 2;

			cout << endl;
		}
	} else {
		cout << "„исло должно быть нечЄтным и больше 3";
	}

	return 0;
}

