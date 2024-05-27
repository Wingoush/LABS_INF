#include <iostream>
#include "class.h"

using namespace std;

int main() {
	Pair pair;
	Pair pair2;

	cin >> pair;

	cout << pair << endl;
	pair--;
	cout << pair << endl;
	--pair;
	cout << pair << endl << endl;

	cin >> pair2;
	cout << pair2 << endl << endl;
	cout << "Comparing integer numbers: " << (pair < pair2) << endl;
	cout << "Comparing double numbers: " << (pair > pair2) << endl;

	return 0;
}
/*Test

Type in integer number: 12
Type in double number: 24.32
12 : 24.32
12 : 23.32
11 : 23.32

Type in integer number: 14
Type in double number: 20.444
14 : 20.444

Comparing integer numbers: 1
Comparing double numbers: 0
*/