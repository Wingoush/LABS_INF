#include <iostream>
#include "class.h"

using namespace std;

Pair& Pair::operator=(const Pair& p) {
	if (&p == this) { return *this; }
	a = p.a; b = p.b;
}

Pair& Pair::operator--() {
	a--;
	Pair p(a, b);
	return p;
}

Pair& Pair::operator--(int) {
	b--;
	Pair p(a, b);
	return p;
}

bool Pair::operator < (const Pair& p) {
	return (a < p.a);
}

bool Pair:: operator > (const Pair& p) {
	return (b < p.b);
}

istream& operator >> (istream& in, Pair& p) {
	cout << "Type in integer number: "; cin >> p.a;
	cout << "Type in double number: "; cin >> p.b;
	return in;
}

ostream& operator << (ostream& out, Pair& p) {
	return out << p.a << " : " << p.b;
}
