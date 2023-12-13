#include <iostream>

using namespace std;

int main() {
	int n;
	int sum = 0;

	cout << "¬ведите число: " << endl;
	cin >> n;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	cout << "—умма: " << sum << endl;

	return 0;
}