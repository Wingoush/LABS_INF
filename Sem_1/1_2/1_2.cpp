#include <iostream>

using namespace std;

int main() {
	float a, b;

	cout << "Введите числитель и знаменатель: " << endl;
	cin >> a >> b;

	if (b == 0) {
		cout << "Нельзя делить на 0" << endl;
	} else {
		cout << (a / b) << endl;
	}

	return 0;
}