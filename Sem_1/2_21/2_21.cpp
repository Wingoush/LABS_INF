#include <iostream>

using namespace std;

int main() {
    int tmp, next;
    bool ordered = true;

    cout << "¬ведите начальное число: " << endl;
    cin >> tmp;

    while (tmp != 0) {
        cout << "¬ведите следующее число: " << endl;
        cin >> next;

        if (next != 0 && tmp > next) {
            ordered = false;
        }
        
        tmp = next;
    }

    if (ordered) {
        cout << "ѕоследовательность упор€дочена по возрастанию" << endl;
    } else {
        cout << "ѕоследовательность не упор€дочена по возрастанию" << endl;
    }

	return 0;
}