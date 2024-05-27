#include <iostream>
#include "class.h"

using namespace std;

int main() {
	Abiturient abit1;
	cout << abit1.getData() << endl << endl;

	Abiturient abit2("Pokryshkin Alexander Ivanovich", "CT", 240);
	cout << abit2.getData() << endl << endl;

	Abiturient abit3 = abit2;
	abit3.setData("Lenin Vladimir Ilyich", "P", 255);
	cout << abit3.getData() << endl << endl;

	Abiturient abit4(abit2);
	cout << abit4.getData() << endl << endl;

	return 0;
}
/*Test

Empty constructor has been used.
 |  | 0

Constructor with arguments has been used.
Pokryshkin Alexander Ivanovich | CT | 240

Copying constructor has been used.
Lenin Vladimir Ilyich | P | 255

Copying constructor has been used.
Pokryshkin Alexander Ivanovich | CT | 240
*/