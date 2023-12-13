#include <iostream>

using namespace std;
int main() {
	int n;

	cout << "¬ведите длину грани: " << endl;
	cin >> n;


	for (int i = 1; i <= n / 2; i++) {
		cout << "  ";
	}
	for (int i = 1; i <= n; i++) {
		cout << "* ";
	}
	cout << endl;


	for (int i = 1; i <= n / 2 - 1; i++) {
		for (int j = n / 2 - 1; j >= i; j--) {
			cout << "  ";
		}

		cout << "* ";

		for (int j = 1; j <= n - 2; j++) {
			cout << "  ";
		}

		cout << "* ";

		for (int j = i; j > 1; j--) {
			cout << "  ";
		}

		cout << "*" << endl;
	}

	for (int i = 1; i <= n; i++) {
		cout << "* ";
	}

	for (int i = 1; i <= (n / 2) - 1; i++) {
		cout << "  ";
	}

	cout << "*" << endl;

	for (int i = 1; i <= (n - 1) / 2; i++) {
		cout << "* ";

		for (int j = 1; j <= n - 2; j++) {
			cout << "  ";
		}

		cout << "* ";

		for (int j = 1; j <= n / 2 - 1; j++) {
			cout << "  ";
		}

		cout << "*" << endl;
	}

	for (int i = 1; i < n / 2; i++) {
		cout << "* ";

		for (int j = 1; j <= n - 2; j++) {
			cout << "  ";
		}

		cout << "* ";

		for (int j = i; j < n / 2 - 1; j++) {
			cout << "  ";
		}

		cout << "*" << endl;
	}

	for (int i = 1; i <= n; i++) {
		cout << "* ";
	}

	return 0;
}