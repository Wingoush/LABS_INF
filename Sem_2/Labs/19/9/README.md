Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.9 - Обработка исключительных ситуаций.

1. Реализовать класс, перегрузить для него операции, указанные в варианте.
2. Определить исключительные ситуации.
3. Предусмотреть генерацию исключительных ситуаций.

# UML - Диаграмма

# Код

## 1 Вариант

### main.cpp

```cpp
#include <iostream>
#include "Vector.h"

using namespace std;

int main(){
	try {
		Vector x(2);
		Vector y(2);

		cout << "Vector x: " << x << endl;
		cout << "Index of the number from vector x to get: "; int indx; cin >> indx;
		cout << "Element with " << indx << " index: " << x[indx] << endl;

		y++;
		cout << "Vector y: " << y << endl;
		++y;
		cout << "Vector y: " << y << endl;
		y++;
		cout << "Vector y: " << y << endl;

	}
	catch (int code) {
		switch (code) {
		case 1: cout << "Size of the vector is too large (Max 4)."; break;
		case 2: cout << "Index outside of the vector's range."; break;
		}
	}
	return 0;
}
/*
Tests:

Test 1:
Vector x: [0] [0]
Index of the number from vector x to get: 2
Index outside of the vector's range.

Test 2:
Vector x: [0] [0]
Index of the number from vector x to get: 1
Element with 1 index: 0
Input element to add in the end: 5
Vector y: [0] [0] [5]
Input element to add in the beginning: 1
Vector y: [1] [0] [0] [5]
Size of the vector is too large (Max 4).
*/

```

### vector.h

```cpp
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


```

### vector.cpp

```cpp
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
```

## 3 Вариант

### main.cpp

```cpp
#include <iostream>
#include "Vector.h"
#include "Error.h"

using namespace std;

int main(){
	try {
		Vector x(2);
		Vector y(2);

		cout << "Vector x: " << x << endl;
		cout << "Index of the number from vector x to get: "; int indx; cin >> indx;
		cout << "Element with " << indx << " index: " << x[indx] << endl;

		y++;
		cout << "Vector y: " << y << endl;
		++y;
		cout << "Vector y: " << y << endl;
		y++;
		cout << "Vector y: " << y << endl;

	}
	catch (Error& e) {
		e.what();
	}
	return 0;
}
/*
Tests:

Test 1:
Vector x: [0] [0]
Index of the number from vector x to get: 2
Index Error.

Test 2:
Vector x: [0] [0]
Index of the number from vector x to get: 1
Element with 1 index: 0
Input element to add in the end: 5
Vector y: [0] [0] [5]
Input element to add in the beginning: 1
Vector y: [1] [0] [0] [5]
Size Error.
*/
```

### vector.h

```cpp
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


```

### vector.cpp

```cpp
#include "Vector.h"
#include "Error.h"
#include <iostream>

Vector::Vector(int s) {
	if (s > MAX_SIZE) { throw SizeError(); }
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
	if (s > MAX_SIZE) { throw SizeError(); }
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
	if (i < 0) { throw IndexError(); }
	if (i >= size) { throw IndexError(); }
	return data[i];
}

Vector Vector::operator ++ (int) {
	if (size + 1 >= MAX_SIZE) { throw SizeError(); }

	Vector temp(size, data);
	delete[] data;
	size++;
	data = new int[size];

	for (int i = 0; i < temp.size; i++) { data[i] = temp.data[i]; }
	cout << "Input element to add in the end: "; cin >> data[size - 1];

	return *this;
}

Vector Vector::operator ++ () {
	if (size + 1 >= MAX_SIZE) { throw SizeError(); }

	Vector temp(size, data);
	delete[] data;
	size++;
	data = new int[size];

	cout << "Input element to add in the beginning: "; cin >> data[0];
	for (int i = 1; i < size; i++) { data[i] = temp.data[i - 1]; }

	return *this;
}
```

### error.h

```cpp
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Error {
public:
	virtual void what() {};
};

class IndexError : public Error {
protected:
	string msg;
public:
	IndexError() { msg = "Index Error.\n"; }
	virtual void what() { cout << msg; }
};

class SizeError : public Error {
protected:
	string msg;
public:
	SizeError() { msg = "Size Error.\n"; }
	virtual void what() { cout << msg; }
};
```

# Тесты

## 1 Вариант

```cpp
Test 1:
Vector x: [0] [0]
Index of the number from vector x to get: 2
Index outside of the vector's range.

Test 2:
Vector x: [0] [0]
Index of the number from vector x to get: 1
Element with 1 index: 0
Input element to add in the end: 5
Vector y: [0] [0] [5]
Input element to add in the beginning: 1
Vector y: [1] [0] [0] [5]
Size of the vector is too large (Max 4).
```

## 3 Вариант

```cpp
Test 1:
Vector x: [0] [0]
Index of the number from vector x to get: 2
Index Error.

Test 2:
Vector x: [0] [0]
Index of the number from vector x to get: 1
Element with 1 index: 0
Input element to add in the end: 5
Vector y: [0] [0] [5]
Input element to add in the beginning: 1
Vector y: [1] [0] [0] [5]
Size Error.
```

# 
