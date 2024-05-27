#pragma once
#include "money.h"
#include <iostream>

using namespace std;

Money& Money::operator = (const Money& t){
	if (&t == this) { return *this; }

	rub = t.rub;
	kop = t.kop;
	
	return *this;
}
bool Money::operator == (const Money& t){
	if ((kop == t.kop) && (rub == t.rub)) { return true; }
	else { return false; }
}
bool Money::operator < (const Money& m){
	int allKopecks1 = rub * 100 + kop;
	int allKopecks2 = m.rub * 100 + m.kop;
	
	if (allKopecks1 < allKopecks2) { return true; }
	else { return false; }
}
bool Money::operator > (const Money& m){
	int allKopecks1 = rub * 100 + kop;
	int allKopecks2 = m.rub * 100 + m.kop;
	
	if (allKopecks1 > allKopecks2) return true;
	else return false;
}

Money Money::operator ++ (int){
	int temp = rub;
	temp++;
	Money t(temp, kop);
	
	return t;
}

Money Money::operator + (const Money& t){
	Money summa;
	summa.rub = rub + t.rub + (kop + t.kop) / 100;
	summa.kop = (kop + t.kop) % 100;
	return summa;
}

istream& operator >> (istream& in, Money& t){
	cout << "Input rub: "; in >> t.rub;
	cout << "Input kop: "; in >> t.kop;

	if (abs(t.kop) >= 100){
		int buf = t.kop / 100;
		t.rub += buf;
		t.kop = t.kop % 100;
	}
	
	return in;
}
ostream& operator << (ostream& out, const Money& t){
	int boof = t.kop;
	if (t.kop < 0){
		boof = -t.kop;
	}
	if ((t.rub == 0) && (t.kop < 0)){
		if (boof >= 10){
			return (out << "-" << t.rub << "," << boof);
		}else{
			return (out << "-" << t.rub << "," << 0 << boof);
		}
	}else if (boof >= 10){
		return (out << t.rub << "," << boof);
	}else{
		return (out << t.rub << "," << 0 << boof);
	}
}
