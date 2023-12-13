#include <iostream>

using namespace std;

int main() {
    int n, s, k;
    bool flag = false;

    cout << "¬ведите число и искомую цифру: " << endl;
    cin >> n >> s;

    while (n > 0 && !flag) {
        k = n % 10;
        
        if (k == s) {
            flag = true;

            cout << "÷ифра найдена" << endl;
        } else {
            n /= 10;
        }
    }

    if (!flag) {
        cout << "÷ифра не найдена" << endl;
    }

	return 0;
}