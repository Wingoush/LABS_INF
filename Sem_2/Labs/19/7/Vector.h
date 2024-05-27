#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector {
public:
	Vector(int s, T value = 0);
	Vector(const Vector<T>& v);
	~Vector();
	Vector& operator = (const Vector <T>& v);
	T& operator [] (int index);
	Vector operator + (const T value);
	Vector operator + (const Vector <T>& v);

	friend ostream& operator << <>(ostream& out, const Vector<T>& v);
	friend istream& operator >> <>(istream& in, const Vector<T>& v);

private:
	int size;
	T* data;
};

template <class T>
Vector<T>::Vector(int s, T k) {
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++) { data[i] = k; }
}

template <class T>
Vector<T>::Vector(const Vector& v) {
	size = v.size;
	data = new T[size];
	for (int i = 0; i < size; i++) { data[i] = v.data[i]; }
}

template <class T>
Vector<T>::~Vector() {
	delete[] data;
	data = 0;
}

template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v) {
	if (this == &v) { return *this; }

	size = v.size;
	if (data != 0) { delete[] data; }
	data = new T[size];

	for (int i = 0; i < size; i++) { data[i] = v.data[i]; }
	return *this;
}

template <class T>
T& Vector<T>::operator [] (int index) {
	if (index < size) {
		return data[index];
	}
	else {
		cout << "Error: invalid index.";
	}
}

template <class T>
Vector<T> Vector<T>::operator + (const T value) {
	Vector<T> temp(size, value);

	for (int i = 0; i < size; i++) { temp.data[i] = data[i] + value; }
	return temp;
}

template <class T>
Vector<T> Vector<T>::operator + (const Vector<T>& v) {
	Vector<T> temp(size, 0);

	for (int i = 0; i < size; i++) {
		if (i < v.size) {
			temp.data[i] = data[i] + v.data[i];
		}else {
			temp.data[i] = data[i];
		}
	}

	return temp;
}

template <class T>
ostream& operator << (ostream& out, const Vector<T>& v) {
	for (int i = 0; i < v.size; i++) { out << "[" << v.data[i] << "] "; }
	return out;
}

template <class T>
istream& operator >> (istream& in, const Vector<T>& v) {
	for (int i = 0; i < v.size; i++) { cout << "Input " << i+1 << " element: "; in >> v.data[i]; }
	return in;
}