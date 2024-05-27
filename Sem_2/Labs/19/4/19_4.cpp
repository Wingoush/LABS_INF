#include <iostream>
#include "class.h"
#include "employee.h"

using namespace std;

void f1(Person& p) {
	p.setData("Gregor", 20);
	cout << p;
}

Person f2() {
	Employee e("Dante", 27, "Manager", 20000);
	return e;
}

int main() {
	Person p;
	cin >> p;
	cout << p;
	Person p2("Charon", 33);
	cout << p2;
	p = p2;
	cout << p;

	Employee e;
	cin >> e;
	cout << e;

	f1(e);
	p = f2();
	cout << p;

	return 0;
}
/*Test

Type in person's name: Sinclair
Type in person's age: 20
Sinclair | 20
Charon | 33
Charon | 33
Type in employee's name: Vergillius
Type in employee's age: 34
Type in employee's occupation: Guide
Type in employee's salary: 1000

NAME: Vergillius
AGE: 34
OCCUPATION: Guide
SALARY: 1000
PAY: 1400

Gregor | 20
Dante | 27
*/