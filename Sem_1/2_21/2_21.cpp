#include <iostream>

using namespace std;

int main() {
    int tmp, next;
    bool ordered = true;

    cout << "������� ��������� �����: " << endl;
    cin >> tmp;

    while (tmp != 0) {
        cout << "������� ��������� �����: " << endl;
        cin >> next;

        if (next != 0 && tmp > next) {
            ordered = false;
        }
        
        tmp = next;
    }

    if (ordered) {
        cout << "������������������ ����������� �� �����������" << endl;
    } else {
        cout << "������������������ �� ����������� �� �����������" << endl;
    }

	return 0;
}