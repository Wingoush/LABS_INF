#include <iostream>

using namespace std;

int main() {
    int n, tmp;
    bool plusFirst = false;
    bool minusFirst = false;

    cout << "Введите длину последовательности: " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Введите число: " << endl;
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
        cout << "Сначала ввели положительное число";
    } else if (minusFirst) {
        cout << "Сначала ввели отрицательное число";
    } else {
        cout << "Все были нулевыми";
    }

    return 0;
}