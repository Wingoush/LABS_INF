#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, r;
    float d;

    cout << "������� ����� * � ��������: " << endl;
    cin >> n;

    d = sqrt(n);
    r = d;

    if ((n >= 4) && (d - r == 0)) {

        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= d; j++) {
                cout << "* ";
            }

            cout << endl;
        }

        cout << endl;
    } else {
        cout << "����� ������ ���� ������ ��� ����� 4 � ��� ������ ������ ���� ����� ������" << endl;
    }

    return 0;
}