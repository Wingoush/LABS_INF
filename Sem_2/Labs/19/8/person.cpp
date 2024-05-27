#pragma once
#include <iostream>
#include <string>
#include "person.h"
#include "event.h"

using namespace std;

Person::Person(){
	name = "";
	age = 0;
}
Person::Person(string N, int A) {
	name = N;
	age = A;
}
Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}
Person::~Person() {}

void Person::setName(string N){
	name = N;
}
void Person::setAge(int A){
	age = A;
}

Person& Person::operator=(const Person& p){
	if (&p == this) { return *this; }

	name = p.name;
	age = p.age;

	return *this;
}

int Person::HandleEvent(const TEvent& e){
	if (e.what == evMessage){
		switch (e.command){
		case averageAge: return age; break;
		}
	}
}
void Person::Show(){
	cout << "Name: " << name;
	cout << "\nAge: " << age;
	cout << endl << "---------------------------" << endl;
}
void Person::Input(){
	cout << "Input name: "; cin >> name;
	cout << "Input age: "; cin >> age;
	cout << endl;
}