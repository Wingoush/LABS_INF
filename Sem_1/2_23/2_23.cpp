#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float n, a, max;
    int i = 1;
    int count = 1;

    cout << "Введите длину последовательности: " << endl;
    cin >> n;

    max = sin(n + 1 / n);

    while (i <= n) {
        a = sin(n + i / n);

        if (a > max) {
            max = a;
            count = 1;
        } else if (a == max) {
            count++;
        }

        i++;
    }

    cout << "Максимальный элемент: " << max << endl;
    cout << "Число элементов с максимальным значением: " << count << endl;

	return 0;
}