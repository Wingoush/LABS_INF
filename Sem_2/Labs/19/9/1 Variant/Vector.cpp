#include "Vector.h"

Vector::Vector(int s) {
	if (s > MAX_SIZE) { throw 1; }
	size = s;
	data = new int[s];
	for (int i = 0; i < size; i++) { data[i] = 0; }
}

Vector::Vector(const Vector& v) {
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++) { data[i] = v.data[i]; }
}

Vector::~Vector() {
	if (data != 0) { delete[] data; }
}

Vector::Vector(int s, int* mas) {
	if (s > MAX_SIZE) { throw 1; }
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++) { data[i] = mas[i]; }
}

const Vector& Vector::operator = (const Vector& v) {
	if (this == &v) { return *this; }
	if (data != 0) { delete[] data; }
	
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++) { data[i] = v.data[i]; }
	
	return *this;
}

ostream& operator << (ostream& out, const Vector& v) {
	if (v.size == 0) { out << "Vector is empty."; } else {
		for (int i = 0; i < v.size; i++) { out << "[" << v.data[i] << "] "; }
	}
	return out;
}

istream& operator >> (istream& in, Vector& v) {
	for (int i = 0; i < v.size; i++) {
		cout << "Input " << i + 1 << " element: ";
		in >> v.data[i];
	}
	return in;
}

int Vector::operator [](int i) {
	if (i < 0) { throw 2; }
	if (i >= size) { throw 2; }
	return data[i];
}

Vector Vector::operator ++ (int) {
	if (size + 1 >= MAX_SIZE) { throw 1; }

	Vector temp(size, data);
	delete[] data;
	size++;
	data = new int[size];

	for (int i = 0; i < temp.size; i++) { data[i] = temp.data[i]; }
	cout << "Input element to add in the end: "; cin >> data[size - 1];

	return *this;
}

Vector Vector::operator ++ () {
	if (size + 1 >= MAX_SIZE) { throw 1; }

	Vector temp(size, data);
	delete[] data;
	size++;
	data = new int[size];

	cout << "Input element to add in the beginning: "; cin >> data[0];
	for (int i = 1; i < size; i++) { data[i] = temp.data[i - 1]; }

	return *this;
}