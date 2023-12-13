#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, x;
	float sum = 0;

	cout << "¬ведите N и X:  " << endl;
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		sum += pow(x, i) / tgamma(i + 1);
	}

	cout << "—умма: " << sum;

	return 0;
}