#include <iostream>

using namespace std;

int main() {
	const int arraySize = 3;
	int array[arraySize][arraySize];
	int digit = 0;

	for (int a = 0; a < arraySize; a++) {
		for (int b = 0; b < arraySize; b++) {
			if ((a + b) % 2 == 1) {
				array[a][b] = 0;
			} else {
				array[a][b] = ((digit < 9) ? ++digit : (digit = 1));
			}

			cout << array[a][b] << " ";
		}
		cout << endl;
	}

	return 0;
}
	/*
		Тестовые данные:

		Тест 1: arraySize = 8

		1 0 2 0 3 0 4 0
		0 5 0 6 0 7 0 8
		9 0 1 0 2 0 3 0
		0 4 0 5 0 6 0 7
		8 0 9 0 1 0 2 0
		0 3 0 4 0 5 0 6
		7 0 8 0 9 0 1 0
		0 2 0 3 0 4 0 5

		Тест 2: arraySize = 4

		1 0 2 0
		0 3 0 4
		5 0 6 0
		0 7 0 8

		Тест 3: arraySize = 3

		1 0 2
		0 3 0
		4 0 5
	*/
