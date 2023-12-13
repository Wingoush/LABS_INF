#include <iostream>

using namespace std;

int main() {
    int n, tmp, max, min;

    cout << "¬ведите длину последовательности: " << endl;
    cin >> n;

    cout << "¬ведите первое число: " << endl;
    cin >> tmp;
    max = tmp;
    min = tmp;

    for (int i = 2; i <= n; i++) {
        cout << "¬ведите следующее число:" << endl;
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
        } else if (tmp < min) {
            min = tmp;
        }
    }

    cout << "—умма максимального и минимального элементов: " << (max + min) << endl;

	return 0;
}