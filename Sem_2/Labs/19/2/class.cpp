#include <iostream>
#include "class.h"
#include <string>

using namespace std;

Abiturient::Abiturient() {
	name = "";
	speciality = "";
	score = 0;
	cout << "Empty constructor has been used." << endl;
}

Abiturient::Abiturient(string n, string spec, int EGE) {
	name = n;
	speciality = spec;
	score = EGE;
	cout << "Constructor with arguments has been used." << endl;
}

Abiturient::Abiturient(const Abiturient& a) {
	name = a.name;
	speciality = a.speciality;
	score = a.score;
	cout << "Copying constructor has been used." << endl;
}

Abiturient::~Abiturient() {

}

string Abiturient::getData() {
	return name + " | " + speciality + " | " + to_string(score);
}

void Abiturient::setData(string n, string spec, int EGE) {
	name = n;
	speciality = spec;
	score = EGE;
}