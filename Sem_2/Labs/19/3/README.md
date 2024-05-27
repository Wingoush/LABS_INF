Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.3 - Классы и объекты. Перегрузка операций.

1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами, копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Перегрузить операции указанные в варианте.
8. Написать программу, в которой продемонстрировать создание объектов и работу всех перегруженных операций.

# UML - Диаграмма

# Код

### main.cpp

```cpp
#include <iostream>
#include "class.h"

using namespace std;

int main() {
	Pair pair;
	Pair pair2;

	cin >> pair;

	cout << pair << endl;
	pair--;
	cout << pair << endl;
	--pair;
	cout << pair << endl << endl;

	cin >> pair2;
	cout << pair2 << endl << endl;
	cout << "Comparing integer numbers: " << (pair < pair2) << endl;
	cout << "Comparing double numbers: " << (pair > pair2) << endl;

	return 0;
}
/*Test

Type in integer number: 12
Type in double number: 24.32
12 : 24.32
12 : 23.32
11 : 23.32

Type in integer number: 14
Type in double number: 20.444
14 : 20.444

Comparing integer numbers: 1
Comparing double numbers: 0
*/
```

### class.h

```cpp
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

```

### class.cpp

```cpp
#include <iostream>
#include "class.h"

using namespace std;

Pair& Pair::operator=(const Pair& p) {
	if (&p == this) { return *this; }
	a = p.a; b = p.b;
}

Pair& Pair::operator--() {
	a--;
	Pair p(a, b);
	return p;
}

Pair& Pair::operator--(int) {
	b--;
	Pair p(a, b);
	return p;
}

bool Pair::operator < (const Pair& p) {
	return (a < p.a);
}

bool Pair:: operator > (const Pair& p) {
	return (b < p.b);
}

istream& operator >> (istream& in, Pair& p) {
	cout << "Type in integer number: "; cin >> p.a;
	cout << "Type in double number: "; cin >> p.b;
	return in;
}

ostream& operator << (ostream& out, Pair& p) {
	return out << p.a << " : " << p.b;
}

```

# Тест

```cpp
Type in integer number: 12
Type in double number: 24.32
12 : 24.32
12 : 23.32
11 : 23.32

Type in integer number: 14
Type in double number: 20.444
14 : 20.444

Comparing integer numbers: 1
Comparing double numbers: 0
```

# Вопросы

1. **Для чего используются дружественные функции и классы?**
   
   Для предоставления доступа к закрытым параметрам другого класса

2. **Сформулировать правила описания и особенности дружественных функций.**
   
   Могут быть определены внутри класса или другого класса.
   
   Не важно, определены через private или public.
   
   Имеют доступ ко всем членам класса

3. **Каким образом можно перегрузить унарные операции?**
   
   Специальными методами класса: operator+, operator-, operator++ и т.д.

4. **Сколько операндов должна иметь унарная функция-операция, определяемая внутри класса?**
   
   До 1 операнда

5. **Сколько операндов должна иметь унарная функция-операция, определяемая вне класса?**
   
   Один

6. **Сколько операндов должна иметь бинарная функция-операция, определяемая внутри класса?**
   
   1-2 Операнда

7. **Сколько операндов должна иметь бинарная функция-операция, определяемая вне класса?**
   
   2 Операнда

8. **Чем отличается перегрузка префиксных и постфиксных унарных операций?**
   
   Постфиксная перегрузка делается с записыванием (int) после оператора.

9. **Каким образом можно перегрузить операцию присваивания?**
   
   operator =

10. **Что должна возвращать операция присваивания?**
    
    Ссылку на объект

11. **Каким образом можно перегрузить операции ввода-вывода?**
    
    operator << и operator >>

12. **В программе описан класс** **и определен объект этого класса.** **Выполняется операция.** **Каким образом, компилятор будет воспринимать вызов функции-операции?** 
    
    ```cpp
    class Student
    {
    	Student& operator++();
    
    };
    Student s;
    ++s;
    ```
    
    Применение перегруженного оператора ++ к объекту s через метод класса

13. **В программе описан класс** **и определен объект этого класса.** **Выполняется операция.** **Каким образом, компилятор будет воспринимать вызов функции-операции?**
    
    ```cpp
    class Student
    {
    	friend Student& operator ++( Student&);
    };
    Student s;
    ++s;
    ```
    
    Применение перегруженного оператора ++ к объекту s через дружественную функцию

14. **В программе описан класс** **и определен объект этого класса.** **Выполняется операция.** **Каким образом, компилятор будет воспринимать вызов функции-операции?**
    
    ```cpp
    class Student
    {
    	bool operator<(Student &P);
    };
    Student a,b;
    cout << a < b;
    ```
    
    Применение перегруженного сравнения < между a и b. Вернёт true если a больше, иначе false

15. **В программе описан класс** **и определен объект этого класса.** **Выполняется операция.** **Каким образом, компилятор будет воспринимать вызов функции-операции?**
    
    ```cpp
    class Student
    {
    	friend bool operator >(const Person&, Person&)
    };
    Student a,b;
    cout << a > b;
    ```
    
    Применение перегруженной дружественной функции > между a и b. Вернёт true или false
