#include <iostream>

using namespace std;

int main() {
	float a, b, *p1, *p2, sum = 0;
	
	cin >> a >> b;
	p1 = &a;
	p2 = &b;

	sum = *p1 + *p2;

	cout << sum << endl;

	return 0;
}