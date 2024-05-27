Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.8 - Программа, управляемая событиями.

1. Определить иерархию пользовательских классов (см. лабораторную работу No5). Во главе иерархии должен стоять абстрактный класс с чисто виртуальными методами для ввода и вывода информации об атрибутах объектов.
2. Реализовать конструкторы, деструктор, операцию присваивания, селекторы и модификаторы.
3. Определить класс-группу на основе структуры, указанной в варианте.
4. Для группы реализовать конструкторы, деструктор, методы для добавления и удаления элементов в группу, метод для просмотра группы, перегрузить операцию для получения информации о размере группы.
5. Определить класс Диалог – наследника группы, в котором реализовать методы для обработки событий.
6. Добавить методы для обработки событий группой и объектами пользовательских классов.
7. Написать тестирующую программу.
8. Нарисовать диаграмму классов и диаграмму объектов.

# UML - Диаграмма
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/f4ddbdcd-29de-4eb9-9c47-7e9bf5826a7c)

# Код

### main.cpp

```cpp
#include <iostream>
#include <string>
#include "dialog.h"
#include "event.h"
#include "vector.h"
#include "object.h"

int main(){
	Dialog D;
	D.Execute();
	return 0;
}
/*
Test:

>m3
Created a group of size 3.
>s
===========================
Group is empty.
===========================
>+
1. Person
2. Abiturient
Input type to add (1-2): 1
Input name: Dante
Input age: 11

Added person into group.
>+
1. Person
2. Abiturient
Input type to add (1-2): 2

Input name: Vergillius
input age: 20
Input score: 180
Input speciality: KT
Added abiturient into group.
>+
1. Person
2. Abiturient
Input type to add (1-2): 1
Input name: Charon
Input age: 29

Added person into group.
>s
===========================
Name: Dante
Age: 11
---------------------------
Name: Vergillius
Age: 20
Score: 180
Speciality: KT
---------------------------
Name: Charon
Age: 29
---------------------------
===========================
>z
Average age of group: 20
>-
Removed last element from group.
>z
Average age of group: 15.5
*/
```

### person.h

```cpp
#pragma once
#include "object.h"
#include "event.h"

using namespace std;

class Person : public Object{
public:
	Person();
	Person(string, int);
	Person(const Person&);
	virtual ~Person();

	void Show();
	void Input();

	string getName() { return name; }
	int getAge() { return age; }

	void setName(string);
	void setAge(int);

	Person& operator=(const Person&);

	virtual int HandleEvent(const TEvent& e);
protected:
	string name;
	int age;
};
```

### person.cpp

```cpp
#pragma once
#include <iostream>
#include <string>
#include "person.h"
#include "event.h"

using namespace std;

Person::Person(){
	name = "";
	age = 0;
}
Person::Person(string N, int A) {
	name = N;
	age = A;
}
Person::Person(const Person& person) {
	name = person.name;
	age = person.age;
}
Person::~Person() {}

void Person::setName(string N){
	name = N;
}
void Person::setAge(int A){
	age = A;
}

Person& Person::operator=(const Person& p){
	if (&p == this) { return *this; }

	name = p.name;
	age = p.age;

	return *this;
}

int Person::HandleEvent(const TEvent& e){
	if (e.what == evMessage){
		switch (e.command){
		case averageAge: return age; break;
		}
	}
}
void Person::Show(){
	cout << "Name: " << name;
	cout << "\nAge: " << age;
	cout << endl << "---------------------------" << endl;
}
void Person::Input(){
	cout << "Input name: "; cin >> name;
	cout << "Input age: "; cin >> age;
	cout << endl;
}
```

### abiturient.h

```cpp
#pragma once
#include "person.h"

using namespace std;

class Abiturient : public Person{
public:
	Abiturient();
	Abiturient(string, int, int, string);
	Abiturient(const Abiturient&);
	~Abiturient();

	void Show();
	void Input();

	void setScore(int);
	void setSpeciality(string);

	Abiturient& operator = (const Abiturient&);
protected:
	int score;
	string speciality;
};
```

### abiturient.cpp

```cpp
#pragma once
#include <iostream>
#include <string>
#include "abiturient.h"

using namespace std;

Abiturient::Abiturient() : Person(){
	score = 0;
	speciality = "";
}
Abiturient::Abiturient(string N, int A, double S, string spec) : Person(N, A) {
	score = S;
	speciality = spec;
}
Abiturient::Abiturient(const Abiturient& a) {
	name = a.name;
	age = a.age;
	score = a.score;
	speciality = a.speciality;
}
Abiturient::~Abiturient() {}

void Abiturient::setScore(int S){
	score = S;
}
void Abiturient::setSpeciality(string spec){
	speciality = spec;
}	

Abiturient& Abiturient::operator = (const Abiturient& a){
	if (&a == this) { return *this; }

	name = a.name;
	age = a.age;
	score = a.score;
	speciality = a.speciality;

	return *this;
}

void Abiturient::Show(){
	cout << "Name: " << name;
	cout << "\nAge: " << age;
	cout << "\nScore: " << score;
	cout << "\nSpeciality: " << speciality;
	cout << "\n" << "---------------------------" << endl;
}
void Abiturient::Input(){
	cout << "\nInput name: "; cin >> name;
	cout << "input age: "; cin >> age;
	cout << "Input score: "; cin >> score;
	cout << "Input speciality: "; cin >> speciality;
}
```

### Vector.h

```cpp
#pragma once
#include "event.h"
#include "object.h"

class Vector{
public:
	Vector();
	Vector(int);
	~Vector();

	void Add();
	void Del();
	void Show();

	int operator()();

	virtual void HandleEvent(const TEvent& e);
protected:
	Object** start;
	int size;
	int cur;
};
```

### Vector.cpp

```cpp
#pragma once
#include <iostream>
#include <string>
#include "object.h"
#include "vector.h"
#include "person.h"
#include "abiturient.h"

using namespace std;

Vector::Vector(){
	start = nullptr;
	size = 0;
	cur = 0;
}
Vector::Vector(int n) {
	start = new Object * [n];
	cur = 0;
	size = n;
}
Vector::~Vector(){
	if (start != 0)delete[] start;
	start = 0;
}

void Vector::Add(){
	Object* p;

	cout << "1. Person" << endl;
	cout << "2. Abiturient" << endl;
	cout << "Input type to add (1-2): ";

	int choice;
	cin >> choice;

	if (choice == 1){
		Person* a = new Person;

		a->Input();
		p = a;

		if (cur < size){
			start[cur] = p;
			cur++;
			cout << "Added person into group." << endl;
		}
	} else if (choice == 2){
		Abiturient* b = new Abiturient;

		b->Input();
		p = b;

		if (cur < size){
			start[cur] = p;
			cur++;
			cout << "Added abiturient into group." << endl;
		}
	} else { return; }
}
void Vector::Show(){

	if (cur == 0) { cout << "Group is empty." << endl; }

	Object** p = start;

	for (int i = 0; i < cur; i++){
		(*p)->Show();
		p++;
	}
}
void Vector::Del() {
	if (cur == 0) { return; }
	cur--;
}

int Vector::operator ()(){
	return cur;
}

void Vector::HandleEvent(const TEvent& e){
	if (e.what == evMessage){
		Object** p = start;

		switch (e.command) {
			case groupShow:
				for (int i = 0; i < cur; i++) {
					(*p)->HandleEvent(e);
					p++;
				}
				break;
			case averageAge:
				double avAge = 0.0;
				for (int i = 0; i < cur; i++) {
					avAge += (*p)->HandleEvent(e);
					p++;
				}
				avAge /= (double)cur;
				cout << "Average age of group: " << avAge << endl;

		}
	}
}

```

### Event.h

```cpp
#pragma once

const int emptyEvent = 0;
const int evMessage = 100;
const int groupAdd = 1;
const int groupRemove = 2;
const int groupShow = 3;
const int groupCreate = 4; 
const int averageAge = 5;
const int programEnd = 101;

struct TEvent{
	int what;
	union{
		int command;
		struct{
			int message;
			int value;
		};
	};
};
```

### Object.h

```cpp
#pragma once
#include "event.h"

using namespace std;

class Object{
public:
	Object();
	virtual ~Object();

	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual int HandleEvent(const TEvent& e) = 0;
};
```

### Object.cpp

```cpp
#pragma once
#include "object.h"

using namespace std;

Object::Object() {}
Object::~Object() {}
```

### Dialog.h

```cpp
#pragma once
#include "event.h"
#include "vector.h"

class Dialog : public Vector{
public:
	Dialog();
	virtual ~Dialog();

	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);

	int Valid();
	void EndExec();
protected:
	int EndState;
};
```

### Dialog.cpp

```cpp
#pragma once
#include <iostream>
#include <string>
#include "dialog.h"
#include "event.h"
#include "vector.h"
#include "object.h"

using namespace std;

Dialog::Dialog() : Vector() { EndState = 0; }
Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event){
	string OpInt = "+-s/qmz";
	string str;
	string param;
	char code;

	cout << ">";
	cin >> str; code = str[0];

	if (OpInt.find(code) < INT64_MAX) {
		event.what = evMessage;

		switch (code){
		case 'm': event.command = groupCreate; break;
		case '+': event.command = groupAdd; break;
		case '-': event.command = groupRemove; break;
		case 's': event.command = groupShow; break;
		case 'q': event.command = programEnd; break;
		case 'z': event.command = averageAge; break;
		}

		if (str.length() > 1){
			param = str.substr(1, str.length() - 1);
			int A = atoi(param.c_str());
			event.value = A;
		}

	} else { event.what = emptyEvent; }
}

int Dialog::Execute(){
	TEvent event;

	do{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());

	return EndState;
}

int Dialog::Valid(){
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event){
	event.what = emptyEvent;
}
void Dialog::EndExec(){
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event){
	if (event.what == evMessage){
		switch (event.command) {
		case groupCreate: {
			size = event.value;

			if (event.value <= 0) {
				cout << "Error: group size is less than 0." << endl;
				break;
			}

			start = new Object * [size];
			cout << "Created a group of size " << event.value << ".\n";
			cur = 0;
			ClearEvent(event);
			break;
		}

		case groupAdd: {
			Add();
			ClearEvent(event);
			break;
		}

		case groupRemove: {
			Del();
			cout << "Removed last element from group." << endl;
			ClearEvent(event);
			break;
		}

		case groupShow: {
			cout << "===========================" << endl;
			Show();
			cout << "===========================" << endl;
			ClearEvent(event);
			break;
		}

		case programEnd: {
			EndExec();
			ClearEvent(event);
			break;
		}

		case averageAge: {
			Vector::HandleEvent(event);
			ClearEvent(event);
			break;
		}

		default:{
				ClearEvent(event);
				break;
			}
		}
	};
}
```

# Тест

```cpp
>m3
Created a group of size 3.
>s
===========================
Group is empty.
===========================
>+
1. Person
2. Abiturient
Input type to add (1-2): 1
Input name: Dante
Input age: 11

Added person into group.
>+
1. Person
2. Abiturient
Input type to add (1-2): 2

Input name: Vergillius
input age: 20
Input score: 180
Input speciality: KT
Added abiturient into group.
>+
1. Person
2. Abiturient
Input type to add (1-2): 1
Input name: Charon
Input age: 29

Added person into group.
>s
===========================
Name: Dante
Age: 11
---------------------------
Name: Vergillius
Age: 20
Score: 180
Speciality: KT
---------------------------
Name: Charon
Age: 29
---------------------------
===========================
>z
Average age of group: 20
>-
Removed last element from group.
>z
Average age of group: 15.5
```

# Вопросы

1. **Что такое класс-группа? Привести примеры таких классов.**
   
   Совокупность связанных классов с общими характеристиками или производные от одного базового класса. Пример: "геометрические фигуры": круг, квадрат, треугольник

2. **Привести пример описания класса-группы Список (List).**
   
   ```cзз
   class List{
   public:
       List(); // Конструктор по умолчанию
       List(const List& other); // Конструктор копирования
       ~List(); // Деструктор
       void add(int value); // Метод добавления элемента
       bool isEmpty() const; // Метод проверки на пустоту
       void print() const; // Метод для просмотра элементов
   private:
       struct Node{
           int data;
           Node* next;
           Node(int data, Node* next = nullptr) : data(data), next(next) {}
       };
       Node* head; // Указатель на начало списка
   };
   ```

3. **Привести пример конструктора (с параметром, без параметров, копирования) для класса-группы Список.**
   
   ```cpp
   // Конструктор без параметров
   List::List() : head(nullptr) {}
   
   // Конструктор с параметром
   List::List(int initialValue){
       head = new Node(initialValue);
   }
   
   // Конструктор копирования
   List::List(const List& other) : head(nullptr){
       Node* current = other.head;
       while (current != nullptr){
           add(current->data);
           current = current->next;
       }
   }
   ```

4. **Привести пример деструктора для класса-группы Список.**
   
   ```cpp
   List::~List(){
       Node* current = head;
       while (current != nullptr)    {
           Node* next = current->next;
           delete current;
           current = next;
       }
   }
   ```

5. **Привести пример метода для просмотра элементов для класса-группы Список.**
   
   ```cpp
   void List::print(){
       Node* current = head;
       while (current != nullptr){
           std::cout << current->data << " ";
           current = current->next;
       }
   
       std::cout << std::endl;
   }
   ```

6. **Какой вид иерархии дает группа?**
   
   Группа - базовый класс, другие классы наследуют свойства и методы.

7. **Почему во главе иерархии классов, содержащихся в группе объектов должен находиться абстрактный класс?**
   
   Он определяет общие свойства и методы всех других классов

8. **Что такое событие? Для чего используются события?**
   
   Исполнение какого-либо кода при выполнении определённых условий.
   
   Используются для реагирования на действия пользователя.

9. **Какие характеристики должно иметь событие-сообщение?**
   
   Уникальный идентификатор события, текстовое сообщение о произошедшем, модель событий принимающая событие, данные события

10. **Привести пример структуры, описывающей событие.**
    
    ```cpp
    struct Event{
        int eventId; // Уникальный идентификатор события
        std::string message; // Текстовое сообщение о событии
        .......
    	// Дополнительные поля
    	.......
    };
    ```

11. **Задана структура события**
    
    ```c
    struct TEvent{
    	int what;
    	union{
    		MouseEventType mouse;
    		KeyDownEvent keyDown;
    		MessageEvent message;
    	}
    };
    ```
    
    **Какие значения, и в каких случаях присваиваются полю what?**
    
    Событие MouseEventType -> присваивается mouse;
    
    Событие KeyDownEvent -> присваивается keyDown;
    
    Событие MessageEvent -> присваивается message;

12. **Задана структура события**
    
    ```c
    struct TEvent{
    	int what; // тип события
    	union{
    		int command; // код комманды
    		struct // параметры команды{
    			int message;
    			int a;
    		};
    	};
    };
    ```
    
    **Какие значения, и в каких случаях присваиваются полю command?**
    
    Значения присваиваются в зависимости от введённой команды

13. **Задана структура события**
    
    ```c
    struct TEvent{
    	int what; // тип события
    	union{
    		int command; // код комманды
    		struct // параметры команды{
    			int message;
    			int a;
    		};
    	};
    };
    ```
    
    **Для чего используются поля a и message?**
    
    Для хранения дополнительных параметров команды

14. **Какие методы необходимы для организации обработки сообщений?**
    
    Получения события, выполнения, очистки.

15. **Какой вид имеет главный цикл обработки событий-сообщений?**
    
    do{...}while(valid)

16. **Какую функцию выполняет метод ClearEvent()? Каким образом?**
    
    СБрасывает текущее событие путём сброса кодов и сообщений

17. **Какую функцию выполняет метод HandleEvent()? Каким образом?**
    
    Обрабатывает события. В метод передаётся событие с кодом, от него выполняются нужные действия.

18. **Какую функцию выполняет метод GetEvent()?**
    
    Получение события из сообщения

19. **Для чего используется поле EndState? Какой класс (объект) содержит это поле?**
    
    Указывает на состояние класса Dialog и содержится в нём.

20. **Для чего используется функция Valid()?**
    
    Для непрекращающегося выполнения программы, пока это не перестанет быть нужным.
