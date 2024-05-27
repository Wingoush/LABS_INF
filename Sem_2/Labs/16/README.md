Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 16 - Линейный, Бинарный и Интерполяционный поиски

# Блок-Схема
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/04029334-2931-420f-bcce-477e6dcf2434)

# Код

```cpp
#include <iostream>

using namespace std;

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

void sortCounting(int arr[], const int SIZE) {
    int* output = new int[SIZE];
    int* count;
    int max = arr[0];

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > max) { max = arr[i]; }
    }

    count = new int[max + 1];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < SIZE; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = SIZE - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = output[i];
    }

    delete[] count, output;
    return;
}

void searchLinear(const int SIZE, int arr[], int key) {
    int* ans = new int[SIZE];
    int h = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == key) {
            ans[h++] = i;
        }
    }
    for (int i = 0; i < h; i++) {
        cout << "Found [" << key << "] at index: " << ans[i] << endl;
    }

    return;
}
void searchBinary(int N, int arr[], int key) {
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            cout << "Found [" << key << "] at index: " << mid << endl;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}
void searchInterpolation(const int N, int arr[], int key) {
    int low = 0;
    int high = N - 1;
    int mid;
    int keyIndex = -1;

    while (arr[low] < key && arr[high] > key) {
        if (arr[high] == arr[low]) {
            break;
        }
        mid = (low + (key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[mid] < key) {
            low = mid + 1;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            keyIndex = mid;
            break;
        }
    }
    if (arr[low] == key) {
        keyIndex = low;
    }
    else if (arr[high] == key) {
        keyIndex = high;
    }

    cout << "Found [" << key << "] at index: " << keyIndex << endl;

    return;
}

int main() {
    int arraySize, key, searchMethod;

    cout << "Type in array size: ";
    cin >> arraySize;
    int* arr = arrayCreate(arraySize);

    sortCounting(arr, arraySize);

    cout << "Generated array (sorted): ";
    arrayPrint(arr, arraySize);

    cout << "Type in key to search: ";
    cin >> key;

    cout << "\n"
        "1 - Linear search \n"
        "2 - Binary search \n"
        "3 - Interpolation search \n"
        "Select desired search method: ";
    cin >> searchMethod;

    switch (searchMethod) {
    case 1:
        searchLinear(arraySize, arr, key);
        break;
    case 2:
        searchBinary(arraySize, arr, key);
        break;
    case 3:
        searchInterpolation(arraySize, arr, key);
        break;
    }

    return 0;
}
/*
Tests

Test 1:
Type in array size: 8
Generated array (sorted): [8] [18] [19] [35] [36] [37] [97] [98]
Type in key to search: 8

1 - Linear search
2 - Binary search
3 - Interpolation search
Select desired search method: 1
Found [8] at index: 0

Test 2:
Type in array size: 6
Generated array (sorted): [12] [53] [58] [63] [72] [95]
Type in key to search: 95

1 - Linear search
2 - Binary search
3 - Interpolation search
Select desired search method: 2
Found [95] at index: 5

Test 3:
Type in array size: 12
Generated array (sorted): [17] [41] [49] [52] [53] [58] [70] [70] [72] [73] [75] [91]
Type in key to search: 53

1 - Linear search
2 - Binary search
3 - Interpolation search
Select desired search method: 3
Found [53] at index: 4
*/
```

# Тесты

## Тест 1

```cpp
Type in array size: 8
Generated array (sorted): [8] [18] [19] [35] [36] [37] [97] [98]
Type in key to search: 8

1 - Linear search
2 - Binary search
3 - Interpolation search
Select desired search method: 1
Found [8] at index: 0
```

## Тест 2

```cpp
Type in array size: 6
Generated array (sorted): [12] [53] [58] [63] [72] [95]
Type in key to search: 95

1 - Linear search
2 - Binary search
3 - Interpolation search
Select desired search method: 2
Found [95] at index: 5
```

## Тест 3

```cpp
Type in array size: 12
Generated array (sorted): [17] [41] [49] [52] [53] [58] [70] [70] [72] [73] [75] [91]
Type in key to search: 53

1 - Linear search
2 - Binary search
3 - Interpolation search
Select desired search method: 3
Found [53] at index: 4
```
