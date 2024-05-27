Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.2 - Классы и объекты. Использование конструкторов.

1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Написать демонстрационную программу, в которой продемонстрировать все три случая вызова конструктора-копирования, вызов конструктора с параметрами и конструктора без параметров.

# UML - Диаграмма
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/19af00f5-2856-4d17-9fd8-7e9098bd9182)

# Код

### main.cpp

```cpp
#include <iostream>
#include "class.h"

using namespace std;

int main() {
	Abiturient abit1;
	cout << abit1.getData() << endl << endl;

	Abiturient abit2("Pokryshkin Alexander Ivanovich", "CT", 240);
	cout << abit2.getData() << endl << endl;

	Abiturient abit3 = abit2;
	abit3.setData("Lenin Vladimir Ilyich", "P", 255);
	cout << abit3.getData() << endl << endl;

	Abiturient abit4(abit2);
	cout << abit4.getData() << endl << endl;

	return 0;
}
/*Test

Empty constructor has been used.
 |  | 0

Constructor with arguments has been used.
Pokryshkin Alexander Ivanovich | CT | 240

Copying constructor has been used.
Lenin Vladimir Ilyich | P | 255

Copying constructor has been used.
Pokryshkin Alexander Ivanovich | CT | 240
*/
```

### class.h

```cpp
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Abiturient {
private:
	string name;
	string speciality;
	int score;
public:
	Abiturient();
	Abiturient(string, string, int);
	Abiturient(const Abiturient&);
	~Abiturient();
	string getData();
	void setData(string, string, int);
};

```

### class.cpp

```cpp
#include <iostream>
#include "class.h"
#include <string>

using namespace std;

Abiturient::Abiturient() {
	name = "";
	speciality = "";
	score = 0;
	cout << "Empty constructor has been used." << endl;
}

Abiturient::Abiturient(string n, string spec, int EGE) {
	name = n;
	speciality = spec;
	score = EGE;
	cout << "Constructor with arguments has been used." << endl;
}

Abiturient::Abiturient(const Abiturient& a) {
	name = a.name;
	speciality = a.speciality;
	score = a.score;
	cout << "Copying constructor has been used." << endl;
}

Abiturient::~Abiturient() {

}

string Abiturient::getData() {
	return name + " | " + speciality + " | " + to_string(score);
}

void Abiturient::setData(string n, string spec, int EGE) {
	name = n;
	speciality = spec;
	score = EGE;
}
```

# Тест

```cpp
Empty constructor has been used.
 |  | 0

Constructor with arguments has been used.
Pokryshkin Alexander Ivanovich | CT | 240

Copying constructor has been used.
Lenin Vladimir Ilyich | P | 255

Copying constructor has been used.
Pokryshkin Alexander Ivanovich | CT | 240
```

# Вопросы

1. **Для чего нужен конструктор?**
   
   Инициализация объектов при их создании.

2. **Сколько типов конструкторов существует в С++?**
   
   Без параметров, с параметрами, копирования

3. **Для чего используется деструктор? В каких случаях деструктор описывается явно?**
   
   Деструкторы освобождают ресурсы, занимаемые объектом. Расписывается явно если объект использует динамическую память или файлы.

4. **Для чего используется конструктор без параметров? Конструктор с параметрами? Конструктор копирования?**
   
   Без параметров: создание с значениями по умолчанию
   
   С параметрами: создание с желаемыми значениями
   
   Копирования: копирование значений другого объекта

5. **В каких случаях вызывается конструктор копирования?**
   
   При создании нового объекта на основе существующего

6. **Перечислите свойства конструкторов.**
   
   Инициализация  атрибутов, выполнение доп. действий при создании объекта

7. **Перечислите свойства деструкторов.**
   
   Освобождение памяти, выполнение доп. действий при уничтожении объекта

8. **К каким атрибутам имеют доступ методы класса?**
   
   Ко всем

9. **Что представляет собой указатель this?**
   
   Ссылка на текущий объект

10. **Какая разница между методами, определенными внутри класса и вне класса?**
    
    Внутри: имеют доступ к атрибутам и могут быть вызваны на объекте.
    
    Вне класса: могут быть вызвани только через объект и не имеют доступа к атрибутам

11. **Какое значение возвращает конструктор?**
    
    Никакое

12. **Какие методы создаются по умолчанию?**
    
    Конструктор без параметров, с параметрами, копирования

13. **Какое значение возвращает деструктор?**
    
    Никакое

14. **Дано описание класса:** **Какой метод отсутствует в описании класса?***
    
    ```cpp
    class Student
    {
    	string name;
    	int group;
    public:
    	student(string, int);
    	student(const student&)
    	~student();
    };
    ```
    
    Конструктор без параметров

15. **Какой метод будет вызван при выполнении следующих операторов:**
    
    ```cpp
    student* s;
    s = new student;
    ```
    
    Конструктор без параметров

16. **Какой метод будет вызван при выполнении следующих операторов:**
    
    ```cpp
    student s("Ivanov", 20);
    ```
    
    Конструктор с параметрами

17. **Какие методы будут вызваны при выполнении следующих операторов:**
    
    ```cpp
    student s1("Ivanov", 20);
    student s2 = s1;
    ```
    
    Конструктор с параметрами и конструктор копирования

18. **Какие методы будут вызваны при выполнении следующих операторов:**
    
    ```cpp
    student s1("Ivanov", 20);
    student s2;
    s2 = s1;
    ```
    
    Конструкторы с параметрами, без параметров и копирования

19. **Какой конструктор будет использоваться при передаче параметра в функцию print()?**
    
    ```cpp
    void print(student a)
    {
    	a.show();
    }
    ```
    
    Конструктор  копирования

20. **Класс описан следующим образом:** **Каким образом можно присвоить новое значение атрибуту name объекта p?**
    
    ```cpp
    class Student
    {
    string name;
    int age;
    public:
    void set_name(string);
    void set_age(int );
    …..
    };
    Student p;
    ```
    
    p.set_name("имя");
    
    
