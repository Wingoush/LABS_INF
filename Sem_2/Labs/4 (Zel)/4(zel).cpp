#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    const int arr_len = 100;
    int real_arr_len, tmp, k, mx;
    int arr[arr_len];
    bool flag1 = false;
    bool flag2 = false;

    while ( !flag1 ) {
        cout << "Type array length (1-" << arr_len << "): ";
        cin >> tmp;
        if (tmp <= arr_len && tmp >= 1) {
            real_arr_len = tmp;
            flag1 = true;
        } else {
            cout << "Error.\n";
        }
    }

    srand(time(0));
    for (int fill = 0; fill < real_arr_len; fill++) {
        arr[fill] = rand() % 100;
        static int tmp_mx = arr[fill];
        if (tmp_mx < arr[fill]) { tmp_mx = arr[fill]; }
        mx = tmp_mx;
    }

    while ( !flag2 ) {
        cout << "Type the K number (must be in array range): ";
        cin >> tmp;
        if (tmp <= real_arr_len && tmp > 0) {
            k = tmp;
            flag2 = true;
        } else {
            cout << "Error.\n";
        }
    }

    for (int counter = 0; counter < real_arr_len; counter++) {
        cout << " [" << arr[counter % real_arr_len] << "] ";
    }

    cout << endl << "1. ";

    for (int counter = k; counter < real_arr_len + k; counter++) {
        cout << " [" << arr[(counter - 1) % real_arr_len] << "] ";
    }

    cout << endl << "2. ";

    for (int counter = 0; counter < real_arr_len; counter++) {
        if (arr[counter] == mx) {
            for (int counter2 = counter; counter2 < (real_arr_len); counter2++) {
                arr[counter2] = arr[(counter2 + 1) % real_arr_len];
            }
            real_arr_len--;
        }
    }

    for (int counter = 0; counter < real_arr_len; counter++) {
        cout << " [" << arr[counter % real_arr_len] << "] ";
    }

    cout << endl << "3. ";

    for (int counter = real_arr_len + k; counter > k; counter--) {
        cout << " [" << arr[(counter - 1) % real_arr_len] << "] ";
    }

    /*
    Примеры работы программы:

    Тест 1:
    Входные данные: arr_len = 10, k = 4
    Выходные данные:
    [24]  [40]  [73]  [75]  [62]  [3]  [80]  [96]  [26]  [75]
    1.  [75]  [62]  [3]  [80]  [96]  [26]  [75]  [24]  [40]  [73]
    2.  [24]  [40]  [73]  [75]  [62]  [3]  [80]  [26]  [75]
    3.  [75]  [73]  [40]  [24]  [75]  [26]  [80]  [3]  [62]

    Тест 2:
    Входные данные: arr_len = 4, k = 4
    Выходные данные:
    [58]  [41]  [8]  [30]
    1.  [30]  [58]  [41]  [8]
    2.  [41]  [8]  [30]
    3.  [41]  [30]  [8]

    Тест 3:
    Входные данные: arr_len = 7, k = 1
    Выходные данные:
    [14]  [76]  [20]  [21]  [55]  [34]  [76]
    1.  [14]  [76]  [20]  [21]  [55]  [34]  [76]
    2.  [14]  [20]  [21]  [55]  [34]
    3.  [14]  [34]  [55]  [21]  [20]
    */

    return 0;
}