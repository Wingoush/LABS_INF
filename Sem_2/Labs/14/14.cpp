#include <iostream>
#include <ctime>

using namespace std;

void arrayPrint(int arr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
    return;
}

int* arrayCreate(const int SIZE) {
    int* arr = new int[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

int split(int arr[], int low, int high) {
    int pivot = arr[low];
    int num = 0;

    for (int i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) { num++; }
    }

    int pos = low + num;

    swap(arr[pos], arr[low]);

    int i = low, j = high;
    while (i < pos && j > pos) {
        while (arr[i] < pivot) { i++; }
        while (arr[j] > pivot) { j--; }

        if (i < pos && j > pos) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pos;
}

void sortHoare(int arr[], int low, int high) {
    if (low >= high) return;
    int pI = split(arr, low, high);
    sortHoare(arr, low, pI - 1);
    sortHoare(arr, pI + 1, high);

    return;
}

int menu() {
    int size;
    cout << "Type array size: ";
    cin >> size;
    int* arr = arrayCreate(size);

    cout << "Array: ";
    arrayPrint(arr, size);

    sortHoare(arr, 0, size - 1);

    cout << "Sorted array: ";
    arrayPrint(arr, size);

    delete[] arr;
    return 0;
}

int main() {
    menu();

    return 0;
}
/*
Tests:

Test 1: arraySize = 1
Type array size: 1
Array: [31]
Sorted array: [31]

Test 2: arraySize = 5
Type array size: 5
Array: [90] [33] [33] [48] [88]
Sorted array: [33] [33] [48] [88] [90]

Test 3: arraySize = 10
Type array size: 10
Array: [39] [19] [51] [50] [34] [11] [48] [60] [55] [16]
Sorted array: [11] [16] [19] [34] [39] [48] [50] [51] [55] [60]
*/