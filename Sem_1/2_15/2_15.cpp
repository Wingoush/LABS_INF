#include <iostream>

using namespace std;

int main() {
    int n, s, k;
    bool flag = false;

    cout << "������� ����� � ������� �����: " << endl;
    cin >> n >> s;

    while (n > 0 && !flag) {
        k = n % 10;
        
        if (k == s) {
            flag = true;

            cout << "����� �������" << endl;
        } else {
            n /= 10;
        }
    }

    if (!flag) {
        cout << "����� �� �������" << endl;
    }

	return 0;
}