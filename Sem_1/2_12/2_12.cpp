#include <iostream>

using namespace std;

int main() {
    int n, tmp, max, min;

    cout << "������� ����� ������������������: " << endl;
    cin >> n;

    cout << "������� ������ �����: " << endl;
    cin >> tmp;
    max = tmp;
    min = tmp;

    for (int i = 2; i <= n; i++) {
        cout << "������� ��������� �����:" << endl;
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
        } else if (tmp < min) {
            min = tmp;
        }
    }

    cout << "����� ������������� � ������������ ���������: " << (max + min) << endl;

	return 0;
}