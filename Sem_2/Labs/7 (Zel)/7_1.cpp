#include <iostream>
#include <ctime>
#include <string>

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

int count(int* arr, int size) {
	int even = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) { even++; }
	}

	return even;
}

int count(string str) {
	int words = 0;

	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == ' ' && str[i + 1] == 'a') { words++; }
	}

	return words;
}

int main() {
	cout << ""
		"1. String \n"
		"2. Array of integers \n"
		"Select type of data: ";

	int dataType;
	cin >> dataType;
	cin.ignore();

	if (dataType == 1) {
		cout << "Type the string: ";
		string data;
		getline(cin, data);
		data = ' ' + data;
		cout << "Words, starting with 'a': " << count(data) << endl;
	}
	else {
		cout << "Type the array size: ";
		int arraySize;
		cin >> arraySize;

		int* arr = arrayCreate(arraySize);
		cout << "Array: ";
		arrayPrint(arr, arraySize);
		cout << "Even numbers: " << count(arr, arraySize);
	}


	return 0;
}
/*
Tests:

Test 1: Data type - String
1. String
2. Array of integers
Select type of data: 1
Type the string: abracadabra one two 2 ahaha under
Words, starting with 'a': 2

Test 2: Data type - String
1. String
2. Array of integers
Select type of data: 1
Type the string: And un acara
Words, starting with 'a': 1

Test 3: Data type - int array
1. String
2. Array of integers
Select type of data: 2
Type the array size: 10
Array: [68] [1] [26] [59] [78] [34] [93] [45] [52] [81]
Even numbers: 5
*/