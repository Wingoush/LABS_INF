Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.7 - Шаблоны классов

Класс-контейнер типа vector с элементами типа int. 

Реализовать операции:

- [] - доступ по индексу

- +вектор - сложение элементов векторов a[i] + b[i]

- +число - добавляет константу ко всем элементам вектора

Класс Time для работы с интервалами. Два поля - минуты (int) и секунды (int). При выводе минуты отделяются от секунд двоеточием.

---

1. Определить шаблон класса-контейнера (см. лабораторную работу No6).

2. Реализовать конструкторы, деструктор, операции ввода-вывода, операцию присваивания.

3. Перегрузить операции, указанные в варианте.

4. Инстанцировать шаблон для стандартных типов данных (int, float, double).

5. Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы стандартных типов данных.

6. Реализовать пользовательский класс (см. лабораторную работу No3).

7. Перегрузить для пользовательского класса операции ввода-вывода.

8. Перегрузить операции необходимые для выполнения операций контейнерного класса.

9. Инстанцировать шаблон для пользовательского класса.

10. Написать тестирующую программу, иллюстрирующую выполнение операций для контейнера, содержащего элементы пользовательского класса.

# UML - Диаграмма

# Код

### main.cpp

```cpp
#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

int main(){
	Vector<int> v(5, 0);
	cout << "Vector v: " << v << endl;
	cin >> v;
	cout << "Vector v: " << v << endl << endl;

	Vector<int> v2(10, 1);
	cout << "Vector v2: " << v2 << endl;
	v2 = v + 24;
	cout << "Vector v2, =v1 + 24: " << v2 << endl;

	cout << "Vector v2, 3rd element: " << v2[2] << endl << endl;
	Vector<int> v3(4, 5);
	cout << "Vector v3: " << v3 << endl;
	v3 = v3+v2;
	cout << "Vector v3, +v2: " << v3 << endl << endl;

	Time t;
	cout << "Time t: " << t << endl;
	cin >> t;
	cout << "Time t: " << t << endl;

	Time k;
	cout << "Input additional time: " << endl; cin >> k;
	Time p;
	p = t+k;
	cout << "Time t, +additional time: " << p << endl << endl;

	Vector<Time> t2(2, t); cin >> t2; cout << "Time t2, parametrized: " << t2 << endl;
	Vector<Time> t3(2, t); cin >> t3; cout << "Time t3, parametrized: " << t3 << endl;
	t3 = t2;
	cout << "Time t3, =t2: " << t3 << endl;
	cout << "Time t3, 2rd element: " << t3[1] << endl;

	return 0;
}
/*
Test:

Vector v: [0] [0] [0] [0] [0]
Input 1 element: 1
Input 2 element: 2
Input 3 element: 3
Input 4 element: 4
Input 5 element: 5
Vector v: [1] [2] [3] [4] [5]

Vector v2: [1] [1] [1] [1] [1] [1] [1] [1] [1] [1]
Vector v2, =v1 + 24: [25] [26] [27] [28] [29]
Vector v2, 3rd element: 27

Vector v3: [5] [5] [5] [5]
Vector v3, +v2: [30] [31] [32] [33]

Time t: 0 : 0
Input minutes: 50
Input seconds: 55
Time t: 50 : 55
Input additional time:
Input minutes: 10
Input seconds: 5
Time t, +additional time: 61 : 0

Input 1 element: Input minutes: 50
Input seconds: 51
Input 2 element: Input minutes: 40
Input seconds: 41
Time t2, parametrized: [50 : 51] [40 : 41]
Input 1 element: Input minutes: 30
Input seconds: 31
Input 2 element: Input minutes: 20
Input seconds: 21
Time t3, parametrized: [30 : 31] [20 : 21]
Time t3, =t2: [50 : 51] [40 : 41]
Time t3, 2rd element: 40 : 41
*/
```

### Vector.h

```cpp
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
```

### Time.h

```cpp
#pragma once
#include <iostream>

using namespace std;

class Time{
public:
	Time(void);
	Time(int, int);
	Time(const Time&);;
	Time& operator = (const Time&);
	Time operator+ (Time k);

	friend ostream& operator << (ostream& out, const Time&);
	friend istream& operator >> (istream& in, Time&);

public:
	virtual ~Time(void) {};

private:
	int min, sec;
};
```

### Time.cpp

```cpp
#include "Time.h"

Time::Time(void) {
	min = sec = 0;
}

Time::Time(int m, int s) {
	min = m; sec = s;
}

Time::Time(const Time& t) {
	min = t.min;
	sec = t.sec;
}

Time& Time::operator = (const Time& t) {
	min = t.min;
	sec = t.sec;
	return  *this;
}

ostream& operator << (ostream& out, const Time& t) {
	out << t.min << " : " << t.sec;
	return out;
}

istream& operator >> (istream& in, Time& t) {
	cout << "Input minutes: "; in >> t.min;
	cout << "Input seconds: "; in >> t.sec;
	return in;
}

Time Time::operator + (Time k) {
	int t = min * 60 + sec;
	int kt = k.min * 60 + k.sec;
	t += kt;
	Time temp(t / 60, t % 60);

	return temp;
}
```

# Тест

```cpp
Vector v: [0] [0] [0] [0] [0]
Input 1 element: 1
Input 2 element: 2
Input 3 element: 3
Input 4 element: 4
Input 5 element: 5
Vector v: [1] [2] [3] [4] [5]

Vector v2: [1] [1] [1] [1] [1] [1] [1] [1] [1] [1]
Vector v2, =v1 + 24: [25] [26] [27] [28] [29]
Vector v2, 3rd element: 27

Vector v3: [5] [5] [5] [5]
Vector v3, +v2: [30] [31] [32] [33]

Time t: 0 : 0
Input minutes: 50
Input seconds: 55
Time t: 50 : 55
Input additional time:
Input minutes: 10
Input seconds: 5
Time t, +additional time: 61 : 0

Input 1 element: Input minutes: 50
Input seconds: 51
Input 2 element: Input minutes: 40
Input seconds: 41
Time t2, parametrized: [50 : 51] [40 : 41]
Input 1 element: Input minutes: 30
Input seconds: 31
Input 2 element: Input minutes: 20
Input seconds: 21
Time t3, parametrized: [30 : 31] [20 : 21]
Time t3, =t2: [50 : 51] [40 : 41]
Time t3, 2rd element: 40 : 41
```

# Вопросы

1. **В чем смысл использования шаблонов?**
   
   Для снижения сложности кода и увеличения его гибкости.

2. **Каковы синтаксис/семантика шаблонов функций?**
   
   Шаблоны начинаются с <u>template</u>, после чего идут <u>< ></u>, в которых указан параметр шаблона. Семантика позволяет создать независимые от типов функции.

3. **Каковы синтаксис/семантика шаблонов классов?**
   
   Шаблоны позволяют создать класс с объектами неизвестного типа. Создаются с помощью <u>template<параметры></u>.

4. **Что такое параметры шаблона функции?**
   
   Поле, которое заменяется на конкретный тип при инстанциировании шаблона.

5. **Перечислите основные свойства параметров шаблона функции.**
   
   Уникальность имён, неопускание идентефикаторов в прототипе, возможность наличия пустого списка параметров, требование одного типа для всех экзепляров.

6. **Как записывать параметр шаблона?**
   
   template <class NAME>

7. **Можно ли перегружать параметризованные функции?**
   
   Да

8. **Перечислите основные свойства параметризованных классов.**
   
   Описывают семейство классов с 1+ неопределённым формальным параметром. Каждый класс отличается значением параметров.

9. **Все ли компонентные функции параметризованного класса являются параметризованными?**
   
   Нет

10. **Являются ли дружественные функции, описанные в параметризованном классе, параметризованными?**
    
    Не обязательно

11. **Могут ли шаблоны классов содержать виртуальные компонентные функции?**
    
    Да

12. **Как определяются компонентные функции параметризованных классов вне определения шаблона класса?**
    
    Вне определения шаблона с указанием списка параметров

13. **Что такое инстанцирование шаблона?**
    
    Создание экземпляра шаблона заменой параметра на конкретный тип данных.

14. **На каком этапе происходит генерирование определения класса по шаблону?**
    
    Компиляция
