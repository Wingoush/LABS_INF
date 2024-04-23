Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 14 - Сортировка Хоара

# Блок-Схема

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-23-13-30-38-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-23-13-30-52-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-23-13-31-05-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-23-13-31-13-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-23-13-31-23-image.png)

# Код

```cpp
#include <iostream>
#include <ctime>

using namespace std;

void arrayPrint(int arr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << arr[i] << "] ";
    }

    cout << endl;
}

int* arrayCreate(const int SIZE) {
    int* arr = new int[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

void sortShell(int arr[], int n) {
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int tmp = arr[i];
            int j;

            for (j = i; j >= h && arr[j - h] > tmp; j -= h) {
                arr[j] = arr[j - h];
            }

            arr[j] = tmp;
        }
    }
}

int sortMenu() {
    int arraySize;
    cout << "Type array size: ";
    cin >> arraySize;
    int* arr = arrayCreate(arraySize);

    cout << "Array: ";
    arrayPrint(arr, arraySize);

    sortShell(arr, arraySize);
    cout << "Sorted array: ";
    arrayPrint(arr, arraySize);

    delete[] arr;
    return 0;
}

int main() {
    sortMenu();

    return 0;
}
/*
Tests:

Test 1: arraySize = 10
Type array size: 10
Array: [27] [5] [70] [52] [48] [78] [90] [21] [63] [38]
Sorted array: [5] [21] [27] [38] [48] [52] [63] [70] [78] [90]

Test 2: arraySize = 1
Type array size: 1
Array: [9]
Sorted array: [9]

Test 3: arraySize = 7
Type array size: 7
Array: [7] [75] [59] [47] [26] [72] [67]
Sorted array: [7] [26] [47] [59] [67] [72] [75]
*/
```

# Тесты

## Тест 1, arraySize = 1

```cpp
Type array size: 1
Array: [31]
Sorted array: [31]
```

## Тест 2, arraySize = 5

```cpp
Type array size: 5
Array: [90] [33] [33] [48] [88]
Sorted array: [33] [33] [48] [88] [90]
```

## Тест 3, arraySize = 10

```cpp
Type array size: 10
Array: [39] [19] [51] [50] [34] [11] [48] [60] [55] [16]
Sorted array: [11] [16] [19] [34] [39] [48] [50] [51] [55] [60]
```
