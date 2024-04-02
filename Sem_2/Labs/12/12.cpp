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

void sortBucket(int arr[], const int SIZE) {
    const int bucket_num = 10;
    const int bucket_size = 10;

    int buckets[bucket_num][bucket_size];
    int bucketsizes[bucket_num] = { 0 };

    for (int i = 0; i < SIZE; i++) {
        int bucketindex = arr[i] / bucket_size;
        buckets[bucketindex][bucketsizes[bucketindex]] = arr[i];
        bucketsizes[bucketindex]++;
    }

    for (int i = 0; i < bucket_num; i++) {
        for (int j = 0; j < bucketsizes[i]; j++) {
            int tmp = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > tmp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1] = tmp;
        }
    }
    int indx = 0;

    for (int i = 0; i < bucket_num; i++) {
        for (int j = 0; j < bucketsizes[i]; j++) {
            arr[indx++] = buckets[i][j];
        }
    }
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

    delete[] count;
}

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < n1) {
        arr[k++] = left[i++];
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void sortMerge(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        sortMerge(arr, start, mid);
        sortMerge(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int split(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return (i + 1);
}

void sortQuick(int arr[], int low, int high) {
    if (low < high) {
        int pi = split(arr, low, high);
        sortQuick(arr, low, pi - 1);
        sortQuick(arr, pi + 1, high);
    }
}

void sortMenu() {
    int arraySize;

    cout << "Type array size: ";
    cin >> arraySize;
    int* arr = arrayCreate(arraySize);

    cout << "Array: ";
    arrayPrint(arr, arraySize);

    cout << ""
        "1. Bucket sort\n"
        "2. Counting sort\n"
        "3. Merge sort\n"
        "4. Quick sort\n"
        "Select desired sorting method (1-4): ";
    int sortingMethod;
    cin >> sortingMethod;

    while (sortingMethod > 4 || sortingMethod < 1) {
        cout << "Select valid sorting method: ";
        cin >> sortingMethod;
    }

    switch (sortingMethod) {
    case 1:
        sortBucket(arr, arraySize);
        cout << "Selected bucket sort. Sorted array: ";
        break;
    case 2:
        sortCounting(arr, arraySize);
        cout << "Selected counting sort. Sorted array: ";
        break;
    case 3:
        sortMerge(arr, 0, arraySize - 1);
        cout << "Selected merge sort. Sorted array: ";
        break;
    case 4:
        sortQuick(arr, 0, arraySize - 1);
        cout << "Selected quick sort. Sorted array: ";
        break;
    }
    arrayPrint(arr, arraySize);

    delete[] arr;
    return;
}

int main() {
    sortMenu();

    return 0;
}

/*
Tests:

Test 1: arraySize = 10, Bucket sort
Type array size: 10
Array: [23] [78] [88] [15] [61] [52] [56] [65] [36] [67]
1. Bucket sort
2. Counting sort
3. Merge sort
4. Quick sort
Select desired sorting method (1-4): 1
Selected bucket sort. Sorted array: [15] [23] [36] [52] [56] [61] [65] [67] [78] [88]


Test 2: arraySize = 10, Counting sort
Type array size: 10
Array: [88] [70] [24] [62] [45] [50] [37] [56] [19] [10]
1. Bucket sort
2. Counting sort
3. Merge sort
4. Quick sort
Select desired sorting method (1-4): 2
Selected counting sort. Sorted array: [10] [19] [24] [37] [45] [50] [56] [62] [70] [88]

Test 3: arraySize = 10, Merge sort
Type array size: 10
Array: [54] [62] [27] [8] [60] [81] [50] [78] [71] [21]
1. Bucket sort
2. Counting sort
3. Merge sort
4. Quick sort
Select desired sorting method (1-4): 3
Selected merge sort. Sorted array: [8] [21] [27] [50] [54] [60] [62] [71] [78] [81]

Test 4:arraySize = 10, Quick sort
Type array size: 10
Array: [24] [85] [86] [45] [64] [97] [5] [21] [69] [83]
1. Bucket sort
2. Counting sort
3. Merge sort
4. Quick sort
Select desired sorting method (1-4): 4
Selected quick sort. Sorted array: [5] [21] [24] [45] [64] [69] [83] [85] [86] [97]
*/