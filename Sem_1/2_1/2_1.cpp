#include <iostream>

using namespace std;

int main() {
	float summ;
	float a;
	int n;

	cout << "������� ����� ������������������: " << endl;
	cin >> n;

	for (n; n > 0; n--) {
		cout << "������� �����: " << endl;
		cin >> a;
		summ += a;
	}

	cout << "�����: " << summ << endl;

	return 0;
}