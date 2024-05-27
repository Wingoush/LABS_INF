Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.4 - Простое наследование. Принцип подстановки.

1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Определить производный класс.
8. Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций.
9. Реализовать функции, получающие и возвращающие объект базового класса. Продемонстрировать принцип подстановки.

# UML - Диаграмма

# Код

### main.cpp

```cpp
#include <iostream>
#include "class.h"
#include "employee.h"

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
	Person p;
	cin >> p;
	cout << p;
	Person p2("Charon", 33);
	cout << p2;
	p = p2;
	cout << p;

	Employee e;
	cin >> e;
	cout << e;

	f1(e);
	p = f2();
	cout << p;

	return 0;
}
/*Test

Type in person's name: Sinclair
Type in person's age: 20
Sinclair | 20
Charon | 33
Charon | 33
Type in employee's name: Vergillius
Type in employee's age: 34
Type in employee's occupation: Guide
Type in employee's salary: 1000

NAME: Vergillius
AGE: 34
OCCUPATION: Guide
SALARY: 1000
PAY: 1400

Gregor | 20
Dante | 27
*/
```

### class.h

```cpp
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
	string name;
	int age;
public:
	Person() { name = ""; age = 0; };
	Person(string n, int a) { name = n; age = a; };
	Person(const Person& p) { name = p.name; age = p.age; };
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
```

# Тест

```cpp
Type in person's name: Sinclair
Type in person's age: 20
Sinclair | 20
Charon | 33
Charon | 33
Type in employee's name: Vergillius
Type in employee's age: 34
Type in employee's occupation: Guide
Type in employee's salary: 1000

NAME: Vergillius
AGE: 34
OCCUPATION: Guide
SALARY: 1000
PAY: 1400

Gregor | 20
Dante | 27
```

# Вопросы

1. **Для чего используется механизм наследования?**
   
   Для создания новых классов на основе уже существующих

2. **Каким образом наследуются компоненты класса, описанные со спецификатором public?**
   
   Наследуются также со спецификатором public

3. **Каким образом наследуются компоненты класса, описанные со спецификатором private?**
   
   Не наследуются

4. **Каким образом наследуются компоненты класса, описанные со спецификатором protected?**
   
   Наследуются со спецификатором protected

5. **Каким образом описывается производный класс?**
   
   Derived : public base {...};

6. **Наследуются ли конструкторы?**
   
   Да, но не вызываются автоматически

7. Наследуются ли деструкторы?**
   
   Да, но не вызываются автоматически

8. **В каком порядке конструируются объекты производных классов?**
   
   Конструктор базового, инициализации производного, конструктор производного

9. **В каком порядке уничтожаются объекты производных классов?**
   
   Деструктор производного, деструктор базового

10. **Что представляют собой виртуальные функции и механизм позднего связывания?**
    
    Виртуальные функции - возможность динамического связывания.
    
    Механизм позднего связывания - обеспечивает вызов правильной функции

11. Могут ли быть виртуальными конструкторы? Деструкторы?**
    
    Конструкторы нет, деструкторы да

12. **Наследуется ли спецификатор virtual?**
    
    Нет

13. **Какое отношение устанавливает между классами открытое наследование?**
    
    отношение <u>является</u>

14. **Какое отношение устанавливает между классами закрытое наследование?**
    
    отношение <u>реализует</u>

15. **В чем заключается принцип подстановки?**
    
    Производный класс может использоваться везде, где используется базовый

16. **Имеется иерархия классов:**
    
    ```c
    class Student
    {    int age;
    public:
        string name;    ...};
    class Employee : public Student
    {
    protected:
        string post;    ...};
    class Teacher : public Employee
    {    protected: int stage;    ...};Teacher x;
    ```
    
    **Какие компонентные данные будет иметь объект х?**
    
    public name;
    
    protected post;
    
    protected stage;

17. **Для классов Student, Employee и Teacher написать конструкторы без параметров.**
    
    ```cpp
    class Student{
    public:
        Student(){ age = 0; name = " "; }
    };
    
    class Employee : public Student{
    public:
        Employee() : Student() { post = " "; }
    };
    
    class Teacher : public Employee{
    public:
        Teacher() : Employee() { stage = 0; }
    };
    ```

18. **Для классов Student, Employee и Teacher написать конструкторы с параметрами.**
    
    ```cpp
    class Student{
    public:
        Student(int a, string n){
    		age = a;
    		name = n;
    	}
    };
    
    class Employee : public Student{
    public:
        Employee(string n, string p) : Student(a, n){
    		post = p;
    	}
    };
    
    class Teacher : public Employee{
    public:
        Teacher(string n, string p, int s) : Employee(n, p){
    		stage = s;
    	}
    };
    ```

19. **Для классов Student, Employee и Teacher написать конструкторы копирования.**
    
    ```cpp
    class Student{
    public:
        Student(const Student& S){
    		age = S.age;
    		name = S.name;
    	}
    };
    
    class Employee : public Student{
    public:
        Employee(const Employee& E){
    		name = E.name;
    		post = E.post;
    	}
    };
    
    class Teacher : public Employee{
    public:
        Teacher(const Teacher& T){
    		name = T.name;
    		post = T.post;
    		stage = T.stage;
    	}
    };
    ```

20. **Для классов Student, Employee и Teacher определить операцию присваивания.**
    
    ```cpp
    Student operator=(const Student& S){
    	if (&S==this) {return *this;}
    
    	age = S.age;
    	name = S.name;
    
    	return *this;
    }
    
    Employee operator=(const Employee& E){
    	if (&S==this) {return *this;}
    
    	name = E.name;
    	post = E.post;
    
    	return *this;
    }
    
    Teacher operator=(const Teacher& T){
    	if (&S==this) {return *this;}
    
    	name = T.name;
    	post = T.post;
    	stage = T.stage;
    
    	return *this;
    }
    ```
