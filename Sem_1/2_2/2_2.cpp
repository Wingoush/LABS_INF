#include <iostream>

using namespace std;

int main() {
	float mult = 1;
	float a;
	int n;

	cout << "������� ����� ������������������: " << endl;
	cin >> n;

	for (n; n > 0; n--) {
		cout << "������� �����: " << endl;
		cin >> a;
		mult *= a;
	}

	cout << "������������: " << mult;

	return 0;
}