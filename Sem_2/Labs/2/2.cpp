#include <iostream>

using namespace std;

int main() {
	const int arraySize = 5;
	int array[arraySize][arraySize];
	int tmp;

	for (int a = 0; a < arraySize; a++) {
		tmp = 1;

		for (int b = a; b < arraySize; b++) {
			array[b][a] = tmp++;
		}

		for (int c = 0; c < a; c++) {
			array[c][a] = 0;
		}
	}

	for (int a = 0; a < arraySize; a++) {
		for (int b = 0; b < arraySize; b++) {
			cout << array[a][b] << " ";
		}

		cout << endl;
	}

	return 0;
}
	/*
		�������� ������:

		���� 1: arraySize = 8

		1 0 0 0 0 0 0 0
		2 1 0 0 0 0 0 0
		3 2 1 0 0 0 0 0
		4 3 2 1 0 0 0 0
		5 4 3 2 1 0 0 0
		6 5 4 3 2 1 0 0
		7 6 5 4 3 2 1 0
		8 7 6 5 4 3 2 1

		���� 2: arraySize = 4

		1 0 0 0
		2 1 0 0
		3 2 1 0
		4 3 2 1

		���� 3: arraySize = 5

		1 0 0 0 0
		2 1 0 0 0
		3 2 1 0 0
		4 3 2 1 0
		5 4 3 2 1
	*/