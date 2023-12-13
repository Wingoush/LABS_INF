#include <iostream>

using namespace std;

int main(){
	int a, b, c, max;

	cout << "¬ведите 3 числа: " << endl;
	cin >> a >> b >> c;

	if (a > b) {
		max = a;
	} else {
		max = b;
	}

	if (c > max) {
		max = c;
	}

	cout << max << endl;

	return 0;
}