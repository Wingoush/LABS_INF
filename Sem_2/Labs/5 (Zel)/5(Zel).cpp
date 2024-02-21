#include <iostream>
#include <ctime>

using namespace std;

void array_fill(int* arr, int l) {
	srand(time(0));
	for (int i = 0; i < l; i++) {
		arr[i] = rand() % 100;
	}
}


int main() {
	const int arr_len = 100;
	int l, tmp;
	int arr[arr_len];
	int arr2[arr_len][arr_len];
	bool flag = false;

	while (!flag) {
		cout << "Type array length (1-" << arr_len << "): ";
		cin >> tmp;
		if (tmp <= arr_len && tmp >= 1) {
			l = tmp;
			flag = true;
		} else {
			cout << "Error.\n";
		}
	}

	array_fill(arr, l);

	for (int i = 0; i < l; i++) {
		cout << "[" << arr[i] << "] ";
	}
	cout << endl << endl;

	for (int i = 0; i < l; i++) {
		arr2[0][i] = arr[i] * (2 - l % 2);
	}

	for (int i = 0; i < l; i++) {
		for (int j = 1; j < l; j++) {
			arr2[j][i] = arr[i] * (1 - (2 * (j % 2)));
		}
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cout << "[" << arr2[i][j] << "] ";
		}
		cout << endl;
	}

	return 0;

	/*
	������� ������ ���������:

	���� 1:
	������� ������: l = 1
	�������� ������:
		[94]

		[94]

	���� 2:
	������� ������: l = 4
	�������� ������:
		[37] [48] [29] [76]

		[74] [96] [58] [152]
		[-37] [-48] [-29] [-76]
		[37] [48] [29] [76]
		[-37] [-48] [-29] [-76]

	���� 3:
	������� ������: l = 3
	�������� ������:
		[14] [38] [22]

		[14] [38] [22]
		[-14] [-38] [-22]
		[14] [38] [22]
	*/
}