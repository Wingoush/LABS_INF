#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 5;
class Vector{
	int size;
	int* data;
public:
	Vector() { size = 0; data = 0; }
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector& v);
	~Vector();

	const Vector& operator = (const Vector& v);
	int operator [] (int i);
	Vector operator++();
	Vector operator++(int);

	friend ostream& operator << (ostream& out, const Vector& v);
	friend istream& operator >> (istream& in, Vector& v);
};

