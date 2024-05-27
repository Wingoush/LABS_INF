#pragma once
#include "class.h"

class Employee : public Person {
protected:
	string occupation;
	double salary;
	double bonus = 0.4;
	double pay;
public:
	Employee():Person() { salary = 0; };
	~Employee() {};
	Employee(string n, int a, string occ, double sal) :Person(n, a) { occupation = occ; salary = sal; }
	Employee(const Employee& e) { name = e.name; age = e.age; occupation = e.occupation; salary = e.salary; }
	void Show();
	string getOccupation() { return occupation; }
	int getSalary() { return salary; }
	void setOccupation(string occ) { occupation = occ; }
	void setSalary(double sal) { salary = sal; }

	Employee& operator = (const Employee& e);
	friend istream& operator >> (istream& in, Employee& e);
	friend ostream& operator << (ostream& out, Employee& e);

	double calcPay();
};

