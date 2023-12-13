#include <iostream>

using namespace std;

int main() {
	float mult = 1;
	float a;
	int n;

	cout << "Введите длину последовательности: " << endl;
	cin >> n;

	for (n; n > 0; n--) {
		cout << "Введите число: " << endl;
		cin >> a;
		mult *= a;
	}

	cout << "Произведение: " << mult;

	return 0;
}