#pragma once
#include <iostream>
#include <string>
#include "object.h"
#include "vector.h"
#include "person.h"
#include "abiturient.h"

using namespace std;

Vector::Vector(){
	start = nullptr;
	size = 0;
	cur = 0;
}
Vector::Vector(int n) {
	start = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector(){
	if (start != 0)delete[] start;
	start = 0;
}

void Vector::Add(){
	Object* p;

	cout << "1. Person" << endl;
	cout << "2. Abiturient" << endl;
	cout << "Input type to add (1-2): ";

	int choice;
	cin >> choice;

	if (choice == 1){
		Person* a = new Person;

		a->Input();
		p = a;

		if (cur < size){
			start[cur] = p;
			cur++;
			cout << "Added person into group." << endl;
		}
	} else if (choice == 2){
		Abiturient* b = new Abiturient;

		b->Input();
		p = b;

		if (cur < size){
			start[cur] = p;
			cur++;
			cout << "Added abiturient into group." << endl;
		}
	} else { return; }
}
void Vector::Show(){

	if (cur == 0) { cout << "Group is empty." << endl; }

	Object** p = start;

	for (int i = 0; i < cur; i++){
		(*p)->Show();
		p++;
	}
}
void Vector::Del() {
	if (cur == 0) { return; }
	cur--;
}

int Vector::operator ()(){
	return cur;
}

void Vector::HandleEvent(const TEvent& e){
	if (e.what == evMessage){
		Object** p = start;

		switch (e.command) {
			case groupShow:
				for (int i = 0; i < cur; i++) {
					(*p)->HandleEvent(e);
					p++;
				}
				break;
			case averageAge:
				double avAge = 0.0;
				for (int i = 0; i < cur; i++) {
					avAge += (*p)->HandleEvent(e);
					p++;
				}
				avAge /= (double)cur;
				cout << "Average age of group: " << avAge << endl;

		}
	}
}
