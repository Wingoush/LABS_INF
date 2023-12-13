#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float n, s, a;
    int i = 1;
    bool flag = false;

    cout << "������� ����� N � S: " << endl;
    cin >> n >> s;

    while (i <= n && !flag) {
        a = sin(n + i / n);

        if (a == s) {
            flag = true;
        } else {
            i++;
        }
    }

    if (flag) {
        cout << "������� ������, ��� �����: " << i << endl;
    } else {
        cout << "������� �� ������" << endl;
    }

	return 0;
}