Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.5 - Наследование. Виртуальные функции. Полиморфизм.

1. Определить абстрактный класс.
2. Определить иерархию классов, в основе которой будет находиться абстрактный класс (см. лабораторную работу No4).
3. Определить класс Вектор, элементами которого будут указатели на объекты иерархии классов.
4. Перегрузить для класса Вектор операцию вывода объектов с помощью потоков.
5. В основной функции продемонстрировать перегруженные операции и полиморфизм Вектора.

# UML - Диаграмма
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/e94f5dcc-6e71-486c-8ba9-56e0304ef442)

# Код

### main.cpp

```cpp
#include <iostream>
#include "Object.h"
#include "class.h"
#include "employee.h"
#include "Vector.h"

using namespace std;

void f1(Person& p) {
	p.setData("Gregor", 20);
	cout << p;
}

Person f2() {
	Employee e("Dante", 27, "Manager", 20000);
	return e;
}

int main() {
	Vector v(5);
	
	Person pers;
	cin >> pers;

	Employee empl;
	cin >> empl;

	Object* p = &pers;
	v.Add(p);

	p = &empl;
	v.Add(p);
	cout << v;

	return 0;
}
/*
Test

Type in person's name: Dante
Type in person's age: 35
Type in employee's name: Vergillius
Type in employee's age: 59
Type in employee's occupation: Guide
Type in employee's salary: 100

NAME: Dante
AGE: 35

NAME: Vergillius
AGE: 59
OCCUPATION: Guide
SALARY: 100
PAY: 140
*/
```

### class.h

```cpp
#pragma once
#include "Object.h"
#include <string>
#include <iostream>

using namespace std;

class Person : public Object {
protected:
	string name;
	int age;
public:
	Person() { name = ""; age = 0; };
	Person(string n, int a) { name = n; age = a; };
	Person(const Person& p) { name = p.name; age = p.age; };
	void Show();
	virtual ~Person() {};
	string getData() { return name + " | " + to_string(age); };
	void setData(string n, int a) { name = n; age = a; };
	Person& operator = (const Person&);
	friend istream& operator >> (istream& in, Person& p);
	friend ostream& operator << (ostream& out, Person& p);
};

```

### class.cpp

```cpp
#include <iostream>
#include "class.h"

using namespace std;

Person& Person::operator=(const Person& p) {
	if (&p == this) { return *this; }
	name = p.name; age = p.age;
}

istream& operator >> (istream& in, Person& p) {
	cout << "Type in person's name: "; cin >> p.name;
	cout << "Type in person's age: "; cin >> p.age;
	return in;
}

ostream& operator << (ostream& out, Person& p) {
	return out << p.name << " | " << p.age << endl;
}

void Person::Show() {
	cout << "NAME: " << name << endl;
	cout << "AGE: " << age << endl;
	cout << endl;
}
```

### employee.h

```cpp
#pragma once
#include "class.h"

class Employee : public Person {
protected:
	string occupation;
	double salary;
	double bonus = 0.4;
	double pay;
public:
	Employee():Person() { salary = 0; };
	~Employee() {};
	Employee(string n, int a, string occ, double sal) :Person(n, a) { occupation = occ; salary = sal; }
	Employee(const Employee& e) { name = e.name; age = e.age; occupation = e.occupation; salary = e.salary; }
	void Show();
	string getOccupation() { return occupation; }
	int getSalary() { return salary; }
	void setOccupation(string occ) { occupation = occ; }
	void setSalary(double sal) { salary = sal; }

	Employee& operator = (const Employee& e);
	friend istream& operator >> (istream& in, Employee& e);
	friend ostream& operator << (ostream& out, Employee& e);

	double calcPay();
};


```

### employee.cpp

```cpp
#include "employee.h"

Employee& Employee::operator = (const Employee& e) {
	if (&e == this) { return *this; }

	name = e.name; age = e.age; occupation = e.occupation; salary = e.salary;
	return *this;
}

istream& operator >> (istream& in, Employee& e) {
	cout << "Type in employee's name: "; in >> e.name;
	cout << "Type in employee's age: "; in >> e.age;
	cout << "Type in employee's occupation: "; in >> e.occupation;
	cout << "Type in employee's salary: "; in >> e.salary;
	cout << endl;
	return in;
}

ostream& operator << (ostream& out, Employee& e) {
	out << "NAME: " << e.name << endl;
	out << "AGE: " << e.age << endl;
	out << "OCCUPATION: " << e.occupation << endl;
	out << "SALARY: " << e.salary << endl;
	out << "PAY: " << e.calcPay() << endl;
	out << "\n";
	return out;
}

double Employee::calcPay() {
	return salary + salary * bonus;	
}

void Employee::Show() {
	cout << "NAME: " << name << endl;
	cout << "AGE: " << age << endl;
	cout << "OCCUPATION: " << occupation << endl;
	cout << "SALARY: " << salary << endl;
	cout << "PAY: " << calcPay() << endl;
	cout << "\n";
}
```

### Vector.h

```cpp
#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Vector{
public:
	Vector();
	Vector(int);
	~Vector();
	void Add(Object*);
	friend ostream& operator << (ostream& out, const Vector&);
private:
	Object** beg;
	int size;
	int cur;
};


```

### Vector.cpp

```cpp
#include "Vector.h"

Vector::Vector() {
	beg = 0;
	size = 0;
	cur = 0;
}
Vector::~Vector() {
	if (beg != 0) { delete[] beg; }
	beg = 0;
}
Vector::Vector(int n) {
	beg = new Object* [n];
	cur = 0;
	size = n;
}

void Vector::Add(Object* p) {
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
}

ostream& operator << (ostream& out,const Vector& v) {
	if (v.size == 0) { out << "Empty." << endl; }
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++) {
		(*p)->Show();
		p++;
	}

	return out;
}
```

### Object.h

```cpp
#pragma once

class Object {
public:
	Object() {};
	~Object() {};
	virtual void Show() = 0;
};
```

# Тест

```cpp
Type in person's name: Dante
Type in person's age: 35
Type in employee's name: Vergillius
Type in employee's age: 59
Type in employee's occupation: Guide
Type in employee's salary: 100

NAME: Dante
AGE: 35

NAME: Vergillius
AGE: 59
OCCUPATION: Guide
SALARY: 100
PAY: 140
```

# Вопросы

1. **Какой метод называется чисто виртуальным? Чем он отличается от виртуального метода?**
   
   Метод, который объявлен в базовом классе, но не имеет в нём реализации. Нужен только для определения интерфейса, реализуется в производных классах

2. **Какой класс называется абстрактным?**
   
   Который содержит хотябы один чисто виртуальный метод

3. **Для чего предназначены абстрактные классы?**
   
   1. Определения интерфейса группы классов
   
   2. Предоставление базовой реализации методов производных классов
   
   3. Запрет инстанциирования себя

4. **Что такое полиморфные функции?**
   
   Функции, способные принимать аргументы разных типов и вести себя по-разному в зависимости от аргументов.

5. **Чем полиморфизм отличается от принципа подстановки?**
   
   Полиморфизм - способность разных объектов обрабатывать одинаковые операции
   
   Принцип подстановки - часть полиморфизма, производные классы могут безопасно использоваться вместо базовых

6. **Привести примеры иерархий с использованием абстрактных классов.**
   
   Абстрактный класс "Геометрическая фигура". Методы вычисления площади и периметра. Наследуются конкретные фигуры: круг, квадрат, треугольник и т.д.

7. **Привести примеры полиморфных функций.**
   
   "Вычислить площадь геометрической фигуры" - может работать на круги, треугольники, квадраты и т.д.

8. **В каких случаях используется механизм позднего связывания?**
   
   Когда вызов метода происходит на этапе выполнения программы, а не компиляции
