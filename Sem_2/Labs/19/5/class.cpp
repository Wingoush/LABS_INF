#include <iostream>
#include "class.h"

using namespace std;

Person& Person::operator=(const Person& p) {
	if (&p == this) { return *this; }
	name = p.name; age = p.age;
}

istream& operator >> (istream& in, Person& p) {
	cout << "Type in person's name: "; cin >> p.name;
	cout << "Type in person's age: "; cin >> p.age;
	return in;
}

ostream& operator << (ostream& out, Person& p) {
	return out << p.name << " | " << p.age << endl;
}

void Person::Show() {
	cout << "NAME: " << name << endl;
	cout << "AGE: " << age << endl;
	cout << endl;
}