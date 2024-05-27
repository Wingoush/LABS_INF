#pragma once
#include <iostream>

using namespace std;

class Iterator{
	friend class Vector;
public:
	Iterator() { element = 0; }
	Iterator(const Iterator& iter) { element = iter.element; }

	bool operator == (const Iterator& iter) { return element == iter.element; }
	bool operator != (const Iterator& iter) { return element != iter.element; };
	void operator ++ () { ++element; }
	void operator -- () { --element; }
	int& operator * () const { return *element; }
private:
	int* element;
};

class Vector{
public:
	Vector(int s, int value = 0);
	Vector(const Vector& v);
	~Vector();
	Vector& operator = (const Vector& v);
	int& operator [] (int index);
	Vector operator + (const int value);
	Vector operator + (const Vector& v);

	Iterator first() { return start; }
	Iterator last() { return end; }

	friend istream& operator >> (istream& in, Vector& v);
	friend ostream& operator << (ostream& in, const Vector& v);

private:
	int size;
	int* data;
	Iterator start;
	Iterator end;
};