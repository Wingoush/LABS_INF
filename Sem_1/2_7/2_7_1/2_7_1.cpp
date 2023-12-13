#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, r;
    float d;

    cout << "¬ведите число * в квадрате: " << endl;
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
        cout << "„исло должно быть больше или равно 4 и его корень должен быть целым числом" << endl;
    }

    return 0;
}