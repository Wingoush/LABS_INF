#include <iostream>

using namespace std;

int main() {
	int n, tmp, *ptr = &tmp, max, min;

	cout << "¬ведите длину последовательности: ";
	cin >> n;
	cout << "¬ведите первое число: ";
	cin >> *ptr;
	max = *ptr;
	min = *ptr;

	for (int i = 2, i <= n, i++) {
		cin >> *ptr;

		if (*ptr > max) {
			max = *ptr;
		} else if (*ptr < min) {
			min = *ptr;
		}
	}
	
	cout << "max=" << max << endl;
	cout << "min=" << min << endl;

	return 0;
}