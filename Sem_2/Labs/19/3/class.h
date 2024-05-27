#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pair {
private:
	int a;
	double b;
public:
	Pair() { a = 0; b = 0.0; };
	Pair(int i, double d) { a = i; b = d; };
	Pair(const Pair& p) { a = p.a; b = p.b; };
	~Pair() {};
	string getData() { return to_string(a) + " : " + to_string(b); };
	void setData(int i, double d) { a = i; b = d; };
	Pair& operator -- ();
	Pair& operator -- (int);
	Pair& operator = (const Pair&);
	bool operator < (const Pair&);
	bool operator > (const Pair&);

	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, Pair& p);
};
