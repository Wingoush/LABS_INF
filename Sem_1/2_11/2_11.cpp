#include <iostream>

using namespace std;

int main() {
    int n, tmp;
    bool plusFirst = false;
    bool minusFirst = false;

    cout << "������� ����� ������������������: " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "������� �����: " << endl;
        cin >> tmp;

        if (!plusFirst && !minusFirst) {
            if (tmp > 0) {
                plusFirst = true; 
            } else if (tmp < 0) {
                minusFirst = true; 
            }
        }
    }

    if (plusFirst) {
        cout << "������� ����� ������������� �����";
    } else if (minusFirst) {
        cout << "������� ����� ������������� �����";
    } else {
        cout << "��� ���� ��������";
    }

    return 0;
}