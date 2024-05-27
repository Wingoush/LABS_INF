#include <iostream>
#include "Object.h"
#include "class.h"
#include "employee.h"
#include "Vector.h"

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
	Vector v(5);
	
	Person pers;
	cin >> pers;

	Employee empl;
	cin >> empl;

	Object* p = &pers;
	v.Add(p);

	p = &empl;
	v.Add(p);
	cout << v;

	return 0;
}
/*
Test

Type in person's name: Dante
Type in person's age: 35
Type in employee's name: Vergillius
Type in employee's age: 59
Type in employee's occupation: Guide
Type in employee's salary: 100

NAME: Dante
AGE: 35

NAME: Vergillius
AGE: 59
OCCUPATION: Guide
SALARY: 100
PAY: 140
*/