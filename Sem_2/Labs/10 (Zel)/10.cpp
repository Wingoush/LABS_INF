#include <iostream>
#include <string>

using namespace std;

int arraySize;

void arrayPrint(string arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << " [" << arr[i] << "] ";
	}

	cout << endl;
}

string* arrayCreate(const int SIZE) {
	string* arr = new string[SIZE];

	return arr;
}

void arrayFill(string arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Type " << i + 1 << " string: ";
		getline(cin, arr[i]);
	}

	return;
}

string* deleteSame(string arr[], int size) {
	int sizeChange = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[j] == arr[i] && arr[j] != "") {
				arr[j] = "";
				sizeChange++;
			}
		}
	}

	string* arrNew = arrayCreate(size - sizeChange);
	int arrayIndex = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] != "") { arrNew[arrayIndex] = arr[i]; arrayIndex++; }
	}


	arraySize = size - sizeChange;
	return arrNew;
}

string* deleteLast(string arr[], int size, int removeCount) {
	if (removeCount > size) {
		arraySize = 0;
		return arrayCreate(0);
	}

	string* arrNew = arrayCreate(size - removeCount);
	for (int i = 0; i < size - removeCount; i++) { arrNew[i] = arr[i]; }

	arraySize = size - removeCount;
	return arrNew;

}

int main() {
	int trimCount;

	cout << "Type in array length: ";
	cin >> arraySize;
	cin.ignore();

	string* arrayDefault = arrayCreate(arraySize);
	arrayFill(arrayDefault, arraySize);
	cout << "Array: "; arrayPrint(arrayDefault, arraySize);

	string* arrayNoClones = deleteSame(arrayDefault, arraySize);
	cout << "Array (No clones): "; arrayPrint(arrayNoClones, arraySize);

	cout << "Type the amount of last elements to trim: ";
	cin >> trimCount;

	string* arrayTrimmed = deleteLast(arrayNoClones, arraySize, trimCount);
	cout << "Array (No clones and trimmed): "; arrayPrint(arrayTrimmed, arraySize);

	delete[] arrayDefault;
	delete[] arrayNoClones;
	delete[] arrayTrimmed;

	return 0;
}
/*
Tests:

Test 1:
Type in array length: 4
Type 1 string: one
Type 2 string: two
Type 3 string: three
Type 4 string: four
Array:  [one]  [two]  [three]  [four]
Array (No clones):  [one]  [two]  [three]  [four]
Type the amount of last elements to trim: 2
Array (No clones and trimmed):  [one]  [two]

Test 2:
Type in array length: 5
Type 1 string: one
Type 2 string: two
Type 3 string: three
Type 4 string: two
Type 5 string: three
Array:  [one]  [two]  [three]  [two]  [three]
Array (No clones):  [one]  [two]  [three]
Type the amount of last elements to trim: 0
Array (No clones and trimmed):  [one]  [two]  [three]

Test 3:
Type in array length: 5
Type 1 string: one
Type 2 string: two
Type 3 string: three
Type 4 string: two
Type 5 string: one
Array:  [one]  [two]  [three]  [two]  [one]
Array (No clones):  [one]  [two]  [three]
Type the amount of last elements to trim: 10
Array (No clones and trimmed):
*/