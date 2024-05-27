#include <iostream>
#include <ctime>

using namespace std;

int mas[255];
int storage;

int* arrayCreate(const int SIZE) {
    int* arr = new int[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}
void arrayPrint(int arr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << arr[i] << "] ";
    }

    cout << endl;

    return;
}

void merge(int c[], int d[], int l, int m, int r) {
    int i = l, j = m + 1, k = r;

    while ((i <= m) && (j <= r)) {
        if (c[i] <= c[j]) {
            d[l++] = c[i++];
        } else {
            d[l++] = c[j++];
        }
    }
    if (i > m) {
        for (int q = j; q <= r; q++) {
            d[l++] = c[q];
        }
    } else {
        for (int p = i; p <= m; p++) {
            d[l++] = c[p];
        }
    }

    return;
}
void naturalSortPass(int x[], int y[], int s, int n) {
    int i = 0;

    while (i <= storage - 2 * s) {
        int r = ((i + 2 * s) < storage) ? mas[i + 2 * s] : n;

        merge(x, y, mas[i], mas[i + s] - 1, r - 1);
        i = i + 2 * s;
    }
    if (i + s < storage) {
        merge(x, y, mas[i], mas[i + s] - 1, n - 1);
    } else  if (i < storage) {
        for (int j = mas[i]; j <= n - 1; j++) {
            y[j] = x[j];
        }
    }

    return;
}
void getbpoint(int a[], int b[], int n, int& m) {
    int j = 0;
    b[j++] = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            b[j++] = i + 1;
        }
    }
    m = j;

    return;
}
void naturalSort(int a[], int n) {
    int* b = new int[n];
    int s = 1;

    while (s < storage) {
        naturalSortPass(a, b, s, n);
        s += s;
        naturalSortPass(b, a, s, n);
        s += s;
    }

    return;
}
void multiphaseSort(int arr[], const int n) {
    bool swapped = true;
    int gap = n;

    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }

    return;
}


int main() {
    int arraySize;
    bool sortingMethod;

    cout << "Type in array size: ";
    cin >> arraySize;
    int* arr = arrayCreate(arraySize);

    cout << "Created array (unsorted): ";
    arrayPrint(arr, arraySize);

    cout << "\n"
        "0 - Natural Sort\n"
        "1 - Multiphase sort\n"
        "Select desired sorting method (Invalid selection will result in Natural Sort): ";
    cin >> sortingMethod;

    if (sortingMethod) {
        multiphaseSort(arr, arraySize);
    } else {
        getbpoint(arr, mas, arraySize, storage);
        naturalSort(arr, arraySize);
    }

    cout << "Sorted array: ";
    arrayPrint(arr, arraySize);

    return 0;
}
/*Tests
* Test 1:
* Type in array size: 30
Created array (unsorted): [53] [93] [11] [62] [96] [40] [84] [87] [61] [94] [89] [67] [18] [30] [32] [73] [64] [84] [63] [35] [29] [2] [51] [87] [30] [81] [87] [10] [46] [26]

0 - Natural Sort
1 - Multiphase sort
Select desired sorting method (Invalid selection will result in Natural Sort): 0
Sorted array: [2] [10] [11] [18] [26] [29] [30] [30] [32] [35] [40] [46] [51] [53] [61] [62] [63] [64] [67] [73] [81] [84] [84] [87] [87] [87] [89] [93] [94] [96]


Test 2:
Type in array size: 30
Created array (unsorted): [97] [71] [2] [72] [85] [8] [59] [59] [75] [23] [81] [5] [89] [72] [47] [85] [8] [93] [78] [12] [23] [35] [75] [17] [1] [47] [91] [44] [84] [33]

0 - Natural Sort
1 - Multiphase sort
Select desired sorting method (Invalid selection will result in Natural Sort): 1
Sorted array: [1] [2] [5] [8] [8] [12] [17] [23] [23] [33] [35] [44] [47] [47] [59] [59] [71] [72] [72] [75] [75] [78] [81] [84] [85] [85] [89] [91] [93] [97]


Test 3:
Type in array size: 30
Created array (unsorted): [69] [60] [98] [77] [30] [60] [97] [95] [82] [38] [27] [74] [24] [44] [55] [7] [80] [32] [86] [67] [89] [36] [21] [98] [87] [65] [27] [61] [53] [53]

0 - Natural Sort
1 - Multiphase sort
Select desired sorting method (Invalid selection will result in Natural Sort): 404
Sorted array: [7] [21] [24] [27] [27] [30] [32] [36] [38] [44] [53] [53] [55] [60] [60] [61] [65] [67] [69] [74] [77] [80] [82] [86] [87] [89] [95] [97] [98] [98]
*/