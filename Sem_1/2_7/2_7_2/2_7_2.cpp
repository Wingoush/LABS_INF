﻿#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Введите длину квадрата:  " << endl;
    cin >> n;

    if (n >= 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << "* ";
            }

            cout << endl;
        }

        cout << endl;
    } else {
        cout << "Число должно быть больше или равно 1" << endl;
    }

    return 0;
}