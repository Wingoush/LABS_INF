#pragma once
#include <iostream>

using namespace std;

class Money{
	int rub;
	int kop;
public:
	Money(){
		rub = 0;
		kop = 0;
	}
	Money(int r, int k){
		rub = r;
		kop = k;
	}
	Money(const Money& t){
		rub = t.rub;
		kop = t.kop;
	}
	~Money() {};	
	void setRub(int r){
		rub = r;
	}
	void setKop(int k){
		kop = k;
	}
	Money& operator=(const Money&); 

	bool operator==(const Money&);
	bool operator<(const Money&);
	bool operator>(const Money&);

	Money operator++(int);
	Money operator+(const Money&);

	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};