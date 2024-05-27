#include "header.h"
#include <iostream>

using namespace std;

int main() {
	Calculations mult;
	mult.Init();

	int a;
	float b;
	double k;

	cout << "Type in integer part: ";
	cin >> a; mult.SetNumber(a);

	cout << "Type in float part: ";
	cin >> b; mult.SetNumber(b);

	cout << "Type in multiplier: ";
	cin >> k;
	cout << "Result: " << mult.Multiply(k);

	return 0;
}
/*Tests

Test 1:
Type in integer part: 13
Type in float part: 60.32
Type in multiplier: 2
Result: 26.64

Test 2:
Type in integer part: 100
Type in float part: 0.4
Type in multiplier: 0.5
Result: 50.2

Test 3:
Type in integer part: 66
Type in float part: 12512.0
Type in multiplier: 0.3
Result: 19.8
*/