#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float n, s, a;
    int i = 1;
    bool flag = false;

    cout << "¬ведите числа N и S: " << endl;
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
        cout << "Ёлемент найден, его номер: " << i << endl;
    } else {
        cout << "Ёлемент не найден" << endl;
    }

	return 0;
}