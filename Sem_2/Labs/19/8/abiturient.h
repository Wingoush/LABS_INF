#pragma once
#include "person.h"

using namespace std;

class Abiturient : public Person{
public:
	Abiturient();
	Abiturient(string, int, int, string);
	Abiturient(const Abiturient&);
	~Abiturient();

	void Show();
	void Input();

	void setScore(int);
	void setSpeciality(string);

	Abiturient& operator = (const Abiturient&);
protected:
	int score;
	string speciality;
};