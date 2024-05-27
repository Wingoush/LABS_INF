#pragma once
#include <iostream>
#include <string>
#include "abiturient.h"

using namespace std;

Abiturient::Abiturient() : Person(){
	score = 0;
	speciality = "";
}
Abiturient::Abiturient(string N, int A, double S, string spec) : Person(N, A) {
	score = S;
	speciality = spec;
}
Abiturient::Abiturient(const Abiturient& a) {
	name = a.name;
	age = a.age;
	score = a.score;
	speciality = a.speciality;
}
Abiturient::~Abiturient() {}

void Abiturient::setScore(int S){
	score = S;
}
void Abiturient::setSpeciality(string spec){
	speciality = spec;
}	

Abiturient& Abiturient::operator = (const Abiturient& a){
	if (&a == this) { return *this; }

	name = a.name;
	age = a.age;
	score = a.score;
	speciality = a.speciality;

	return *this;
}

void Abiturient::Show(){
	cout << "Name: " << name;
	cout << "\nAge: " << age;
	cout << "\nScore: " << score;
	cout << "\nSpeciality: " << speciality;
	cout << "\n" << "---------------------------" << endl;
}
void Abiturient::Input(){
	cout << "\nInput name: "; cin >> name;
	cout << "input age: "; cin >> age;
	cout << "Input score: "; cin >> score;
	cout << "Input speciality: "; cin >> speciality;
}