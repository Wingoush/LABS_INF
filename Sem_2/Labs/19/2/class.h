#pragma once
#include <string>
#include <iostream>

using namespace std;

class Abiturient {
private:
	string name;
	string speciality;
	int score;
public:
	Abiturient();
	Abiturient(string, string, int);
	Abiturient(const Abiturient&);
	~Abiturient();
	string getData();
	void setData(string, string, int);
};
