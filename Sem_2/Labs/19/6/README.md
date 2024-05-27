Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.6 - АТД. Контейнеры

Класс-контейнер типа vector с элементами типа int. 

Реализовать операции:

- [] - доступ по индексу

- +вектор - сложение элементов векторов a[i] + b[i]

- +число - добавляет константу ко всем элементам вектора

- --  -  переход к предыдущему элементу (с помощью класса-итератора)
1. Определить класс-контейнер.

2. Реализовать конструкторы, деструктор, операции ввода-вывода, операцию присваивания.

3. Перегрузить операции, указанные в варианте.

4. Реализовать класс-итератор. Реализовать с его помощью операции последовательного доступа.

5. Написать тестирующую программу, иллюстрирующую выполнение операций.

# UML - Диаграмма
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/5204c533-c8ce-4197-8013-efc3fd59274c)

# Код

### main.cpp

```cpp
#include <iostream>
#include "Vector.h"

using namespace std;

int main(){
    Vector v(5);
    cout << "Vector v: " << v << endl;
    cin >> v;
    cout << "Vector v: " << v << endl;

    v[3] = 9999;
    cout << endl <<  "Vector v, 4 element changed to 9999: " << v << endl << endl;

    Vector v2(6, 40);
    cout << "Vector v2: " << v2 << endl;
    Vector v3(8);
    cout << "Vector v3: " << v3 << endl;
    v3 = v2 + 60;
    cout << "Vector v3, =v2 and +60: " << v3 << endl;

    Iterator iter;
    iter = v.last(); --iter;
    cout << endl <<  "Vector v, last element: " << *iter << endl;
    --iter;
    cout << "Vector v, pre-last element: " << *iter << endl;

    cout << endl << "Vector v, print through iterator: ";
    for (iter = v.first(); iter != v.last(); ++iter) {
        cout << "[" << *iter << "] ";
    }

    return 0;
}
/*
Test

Vector v: [0] [0] [0] [0] [0]
Input 1 element: 10
Input 2 element: 20
Input 3 element: 30
Input 4 element: 40
Input 5 element: 50
Vector v: [10] [20] [30] [40] [50]

Vector v, 4 element changed to 9999: [10] [20] [30] [9999] [50]

Vector v2: [40] [40] [40] [40] [40] [40]
Vector v3: [0] [0] [0] [0] [0] [0] [0] [0]
Vector v3, =v2 and +60: [100] [100] [100] [100] [100] [100]

Vector v, last element: 50
Vector v, pre-last element: 9999

Vector v, print through iterator: [10] [20] [30] [9999] [50]
*/
```

### Vector.h

```cpp
#pragma once
#include <iostream>

using namespace std;

class Iterator{
    friend class Vector;
public:
    Iterator() { element = 0; }
    Iterator(const Iterator& iter) { element = iter.element; }

    bool operator == (const Iterator& iter) { return element == iter.element; }
    bool operator != (const Iterator& iter) { return element != iter.element; };
    void operator ++ () { ++element; }
    void operator -- () { --element; }
    int& operator * () const { return *element; }
private:
    int* element;
};

class Vector{
public:
    Vector(int s, int value = 0);
    Vector(const Vector& v);
    ~Vector();
    Vector& operator = (const Vector& v);
    int& operator [] (int index);
    Vector operator + (const int value);
    Vector operator + (const Vector& v);

    Iterator first() { return start; }
    Iterator last() { return end; }

    friend istream& operator >> (istream& in, Vector& v);
    friend ostream& operator << (ostream& in, const Vector& v);

private:
    int size;
    int* data;
    Iterator start;
    Iterator end;
};
```

### Vector.cpp

```cpp
#include "Vector.h"

Vector::Vector(int s, int k) {
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++) { data[i] = k; }

    start.element = &data[0];
    end.element = &data[size];
}
Vector::Vector(const Vector& v) {
    size = v.size;
    data = new int[size];
    for (int i = 0; i < size; i++) { data[i] = v.data[i]; }

    start = v.start;
    end = v.end;
}
Vector::~Vector() {
    delete[] data;
    data = 0;
}
Vector& Vector::operator = (const Vector& v) {
    if (this == &v) { return  *this; }

    size = v.size;
    if (data != 0) { delete[] data; }
    data = new int[size];

    for (int i = 0; i < size; i++) { data[i] = v.data[i]; }

    start = v.start;
    end = v.end;

    return *this;
}
int& Vector::operator [] (int index){
    if (index < size) {
        return data[index];
    }else{
        cout << endl << "Error: invalid index.";
        return data[0];
    }
}
Vector Vector::operator + (const int k){
    Vector temp(size);

    for (int i = 0; i < size; ++i){
        temp.data[i] = data[i] + k;
    }

    return temp;
}
Vector Vector::operator + (const Vector& v) {
    Vector temp(size);

    for (int i = 0; i < size; ++i) {
        if (i <= v.size) {
            temp.data[i] = data[i] + v.data[i];
        }else {
            temp.data[i] = data[i];
        }
    }

    return temp;
}

ostream& operator << (ostream& out, const Vector& v) {
    for (int i = 0; i < v.size; ++i) {
        out << "[" << v.data[i] << "] ";
    }

    return out;
}
istream& operator >> (istream& in, Vector& v) {
    for (int i = 0; i < v.size; ++i) {
        cout << "Input " << i+1 << " element: ";
        in >> v.data[i];
    }

    return in;
}
```

# Тест

```cpp
Vector v: [0] [0] [0] [0] [0]
Input 1 element: 10
Input 2 element: 20
Input 3 element: 30
Input 4 element: 40
Input 5 element: 50
Vector v: [10] [20] [30] [40] [50]

Vector v, 4 element changed to 9999: [10] [20] [30] [9999] [50]

Vector v2: [40] [40] [40] [40] [40] [40]
Vector v3: [0] [0] [0] [0] [0] [0] [0] [0]
Vector v3, =v2 and +60: [100] [100] [100] [100] [100] [100]

Vector v, last element: 50
Vector v, pre-last element: 9999

Vector v, print through iterator: [10] [20] [30] [9999] [50]
```

# Вопросы

1. **Что такое абстрактный тип данных? Привести примеры АТД.**
   
   АТД - модель типа данных, где тип данных определяется поведением с точки зрения пользователя, возможных значений, операций над данными и их поведения. Примеры: Stack, Queue, List.

2. **Привести примеры абстракции через параметризацию**
   
   Шаблон класса. В нём тип данных - параметр.

3. **Привести примеры абстракции через спецификацию**
   
   Интерфейс списка. Он может быть реализован массивом или связным списком.

4. **Что такое контейнер? Привести примеры**
   
   Контейнер - тип данных, позволяющий хранить в себе однотипные данные других типов. Примеры: Vector, List, Stack, Queue.

5. **Какие группы операций выделяют в контейнерах?**
   
   Добавление, удаление, поиск, доступ к элементам. Объединение контейнеров и специальные операции (зависят от вида контейнера).

6. **Какие виды доступа к элементам контейнера существуют? Привести примеры**
   
   Виды доступа: последовательный, прямой, ассоциативный.
   
   Примеры: Прямой - поиск по индексу. Ассоциативный - словарь переводов. Последовательный - список.

7. **Что такое итератор?**
   
   Объект, позволяющий перебирать элементы контейнера и предоставляя к ним доступ.

8. **Каким образом может быть реализован итератор?**
   
   Объект с методами для перемещения в контейнере.

9. **Каким образом можно организовать объединение контейнеров?**
   
   С помощью создания нового контейнера и вставке в него содержимого двух изначальный контейнеров.

10. **Какой доступ к элементам предоставляет контейнер, состоящий из элементов «ключ-значение»?**
    
    Ассоциативный

11. **Как называется контейнер, в котором вставка и удаление элементов выполняется на одном конце контейнера?**
    
    Стек

12. **Какой из объектов (a,b,c,d) является контейнером?**
    
    - a. int mas = 10;
    - b. int mas;
    - c. struct {char name[30]; int age;} mas;
    - d. int mas[100].
    
    D

13. **Какой из объектов (a,b,c,d) не является контейнером?**
    
    - a. int a[] = {1,2,3,4,5};
    - b. int mas[30];
    - c. struct {char name[30]; int age;} mas[30];
    - d. int mas.
    
    D

14. **Контейнер реализован как динамический массив, в нем определена операция доступ по индексу. Каким будет доступ к элементам контейнера?**
    
    Прямой

15. **Контейнер реализован как линейный список. Каким будет доступ к элементам контейнера?**
    
    Последовательный
    
    
