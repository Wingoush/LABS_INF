#include <iostream>

using namespace std;

int main() {
	float summ;
	float a;
	int n;

	cout << "¬ведите длину последовательности: " << endl;
	cin >> n;

	for (n; n > 0; n--) {
		cout << "¬ведите число: " << endl;
		cin >> a;
		summ += a;
	}

	cout << "—умма: " << summ << endl;

	return 0;
}