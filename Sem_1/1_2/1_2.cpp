#include <iostream>

using namespace std;

int main() {
	float a, b;

	cout << "������� ��������� � �����������: " << endl;
	cin >> a >> b;

	if (b == 0) {
		cout << "������ ������ �� 0" << endl;
	} else {
		cout << (a / b) << endl;
	}

	return 0;
}