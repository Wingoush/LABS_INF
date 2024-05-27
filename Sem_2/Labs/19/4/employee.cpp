#include "employee.h"

Employee& Employee::operator = (const Employee& e) {
	if (&e == this) { return *this; }

	name = e.name; age = e.age; occupation = e.occupation; salary = e.salary;
	return *this;
}

istream& operator >> (istream& in, Employee& e) {
	cout << "Type in employee's name: "; in >> e.name;
	cout << "Type in employee's age: "; in >> e.age;
	cout << "Type in employee's occupation: "; in >> e.occupation;
	cout << "Type in employee's salary: "; in >> e.salary;
	cout << endl;
	return in;
}

ostream& operator << (ostream& out, Employee& e) {
	out << "NAME: " << e.name << endl;
	out << "AGE: " << e.age << endl;
	out << "OCCUPATION: " << e.occupation << endl;
	out << "SALARY: " << e.salary << endl;
	out << "PAY: " << e.calcPay() << endl;
	out << "\n";
	return out;
}

double Employee::calcPay() {
	return salary + salary * bonus;	
}