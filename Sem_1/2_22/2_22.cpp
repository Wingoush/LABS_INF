#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float n, a, max;
    int i = 1;
    int num = 1;

    cout << "������� ����� ������������������: " << endl;
    cin >> n;

    max = sin(n + 1 / n);

    while (i <= n) {
        a = sin(n + i / n);

        if (a > max) {
            max = a;
            num = i;
        }
        
        i++;
    }
    
    cout << "������������ �������: " << max << " // ����� ��������: " << num << endl;

	return 0;
}