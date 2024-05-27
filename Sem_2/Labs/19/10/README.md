Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.10 - Сохранение данных в файле с использованием потоков.

1. Создать пользовательский класс с минимальной функциональностью.
2. Написать функцию для создания объектов пользовательского класса (ввод исходной информации с клавиатуры) и сохранения их в потоке (файле).
3. Написать функцию для чтения и просмотра объектов из потока.
4. Написать функцию для удаления объектов из потока в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
5. Написать функцию для добавления объектов в поток в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
6. Написать функцию для изменения объектов в потоке в соответствии с заданием варианта. Для выполнения задания выполнить перегрузку необходимых операций.
7. Для вызова функций в основной программе предусмотреть меню.

# UML - Диаграмма
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/05f9ad5d-ed94-4190-9bcc-ec9946d01151)

# Код

### main.cpp

```cpp
#include "Time.h" 
#include <iostream> 
#include <fstream> 
#include <string> 
#include "file_work.h"

using namespace std;

int main(){
    Time p, p1, p2, timeTask;
    int k, c, seconds, k_elements;
    char file_name[30];
    int k1, k2;
    char file_name1[30], file_name2[30];

    do{
        cout << "1. Make file\n";
        cout << "2. Print file\n";
        cout << "3. Delete record from file\n";
        cout << "4. Add record to file\n";
        cout << "5. Change record in file\n";
        cout << "6. Add/Remove seconds to record in file\n";
        cout << "7. Remove target time from file\n";
        cout << "8. Lower target time from file by [1:30]\n";
        cout << "9. Add K times after specific time\n";
        cout << "0. Exit\n";

        cout << "\nInput your choice: ";
        cin >> c;

        switch (c){
            case 1:
                cout << "File name: ";
                cin >> file_name;

                k = make_file(file_name);
                if (k < 0) {cout << "Can't make file";}
                break;
            case 2:
                cout << "File name: ";
                cin >> file_name;

                k = print_file(file_name);
                if (k == 0) { cout << "Empty file\n"; }
                if (k < 0) { cout << "Can't read file\n"; }
                break;
            case 3:
                cout << "File name: ";
                cin >> file_name;
                int numberOfEntry;
                cout << "Number of entry: ";
                cin >> numberOfEntry;

                k = del_file(file_name, numberOfEntry);
                if (k < 0) { cout << "Can't read file"; }
                break;
            case 4:
                cout << "Eile name: ";
                cin >> file_name;
                cout << "Number of entry: ";
                cin >> numberOfEntry;
                cout << "New time: ";
                cin >> p1;

                k = add_file(file_name, numberOfEntry, p1);
                if (k < 0) { cout << "Can't read file"; }
                if (k == 0) { k = add_end(file_name, p1); }
                break;
            case 5:
                cout << "File name: ";
                cin >> file_name;
                cout << "Number of entry: ";
                cin >> numberOfEntry;
                cout << "New time:";
                cin >> p2;

                k = change_file(file_name, numberOfEntry, p2);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 6:
                cout << "File name: ";
                cin >> file_name;
                cout << "Number of entry: ";
                cin >> numberOfEntry;
                cout << "Seconds to add: ";
                cin >> seconds;

                k = change_file(file_name, numberOfEntry, seconds);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 7:
                cout << "File name: ";
                cin >> file_name;
                cout << "Time to delete: " << endl;
                cin >> timeTask;

                k = deleteTarget(file_name, timeTask);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 8:
                cout << "File name: ";
                cin >> file_name;
                cout << "Time to lower: " << endl;
                cin >> timeTask;

                k = changeTarget(file_name, timeTask);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 9:
                cout << "File name: ";
                cin >> file_name;
                cout << "Time to add after: " << endl;
                cin >> timeTask;
                cout << "How many elements to add: ";
                cin >> k_elements;

                k = addAfterTarget(file_name, k_elements, timeTask);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            }
    } while (c != 0);

    return 0;
}
/*
Test:

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 1
File name: f1
Amount of entries: 6
min: 10
sec: 30

min: 22
sec: 14

min: 43
sec: 22

min: 12
sec: 33

min: 78
sec: 22

min: 16
sec: 16


1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[10:30]
[22:14]
[43:22]
[12:33]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 7
File name: f1
Time to delete:
min: 12
sec: 33

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[10:30]
[22:14]
[43:22]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 8
File name: f1
Time to lower:
min: 10
sec: 30

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[9:0]
[22:14]
[43:22]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 9
File name: f1
Time to add after:
min: 22
sec: 14

How many elements to add: 2
min: 13
sec: 13

min: 14
sec: 14

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[9:0]
[22:14]
[13:13]
[14:14]
[43:22]
[78:22]
[16:16]

*/
```

### file_work.h

```cpp
#include "Time.h" 
#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;

int make_file(const char* f_sec){
    fstream stream(f_sec, ios::out | ios::trunc);

    if (!stream) { return -1; }

    int n;
    Time p;

    cout << "Amount of entries: "; cin >> n;

    for (int i = 0; i < n; i++){
        cin >> p;
        stream << p << "\n";
    }

    cout << endl;
    stream.close();
    return n;
}
int print_file(const char* f_sec){
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    Time p; int i = 0;

    while (stream >> p){
        cout << p;
        i++;
    }
    cout << endl;
    stream.close();
    return i;
}

int del_file(const char* f_sec, int k){
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    int i = 0; Time p;

    while (stream >> p){
        if (stream.eof())break;
        i++;
        if (i != k) temp << p;
    }

    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);

    return i;
}
int add_file(const char* f_sec, int k, Time pp){
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    Time p; int i = 0, l = 0;

    while (stream >> p){
        if (stream.eof()) { break; }
        i++;
        if (i == k){
            temp << pp;
            l++;
        }
        temp << p;
    }

    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);

    return l;
}

int add_end(const char* f_sec, Time pp){
    fstream stream(f_sec, ios::app);

    if (!stream) { return -1; }
    stream << pp;

    return 1;
}

int change_file(const char* f_sec, int k, Time pp){
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    Time p; int i = 0, l = 0;
    char x;

    while (stream >> p){
        if (stream.eof()) { break; }
        i++;
        if (i == k){
            cout << "Changing entry: " << p << ". Continue [y/n]?";
            cin >> x;

            if (x == 'n' || x == 'N') { break; }

            temp << pp;
            l++;
        } else { temp << p; }
    }

    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);

    return l;
}
int change_file(const char* f_sec, int k, int seconds) {
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    Time p; int i = 0, l = 0;

    while (stream >> p) {
        if (stream.eof()) { break; }
        i++;
        if (i == k) {
            temp << (p + seconds);
            l++;
        } else { temp << p; }
    }

    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);

    return l;
}

int deleteTarget(const char* f_sec, Time target) {
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    Time p;

    while (stream >> p) {
        if (stream.eof()) { break; }
        if (p.getTime() != target.getTime()) {
            temp << p;
        }
    }

    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);

    return 1;
}
int changeTarget(const char* f_sec, Time target) {
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    Time p;

    while (stream >> p) {
        if (stream.eof()) { break; }
        if (p.getTime() == target.getTime()) {
            temp << (p + (-90));
        }
        else { temp << p; }
    }

    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);

    return 1;
}
int addAfterTarget(const char* f_sec, int k, Time target){
    fstream temp("temp", ios::out);
    fstream stream(f_sec, ios::in);

    if (!stream) { return -1; }

    Time p;

    while (stream >> p) {
        if (stream.eof()) { break; }
        if (p.getTime() == target.getTime()) {
            temp << p;
            for (int i = 0; i < k; i++) {
                Time ptemp;
                cin >> ptemp;
                temp << ptemp;
            }
        }else { temp << p; }
    }

    stream.close(); temp.close();
    remove(f_sec);
    rename("temp", f_sec);

    return 1;
}
```

### Time.h

```cpp
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Time{
public:
    Time();
    Time(int, int);
    Time(const Time&);
    ~Time();

    Time operator = (const Time&);
    bool operator == (const Time&);
    Time operator + (int);
    
    int getTime();

    friend ostream& operator << (ostream& out, const Time& p);
    friend istream& operator >> (istream& in, Time& p);
    friend fstream& operator >> (fstream& fin, Time& p);
    friend fstream& operator << (fstream& fout, const Time& p);
private:
    int sec;
    int min;
};
```

### Time.cpp

```cpp
#include "Time.h"

Time::Time(){
	sec = 0; min = 0;
}
Time::Time(int N, int A){
	sec = N; min = A;
}
Time::Time(const Time& p){
	sec = p.sec; min = p.min;
}
Time::~Time() {}

Time Time::operator = (const Time& p){
	if (&p == this) { return *this; }
	sec = p.sec;
	min = p.min;

	return *this;
}
Time Time::operator + (int seconds) {
	int t = min * 60 + sec;
	t + seconds > 0 ? t += seconds : t = 0;
	Time temp(t % 60, t / 60);

	return temp;
}

int Time::getTime() {
	return min * 60 + sec;
}

ostream& operator << (ostream& out, const Time& p){
	out << "[" << p.min << ":" << p.sec << "]\n";

	return out;
}
istream& operator >> (istream& in, Time& p){
	cout << "min: "; in >> p.min;
	cout << "sec: "; in >> p.sec;
	cout << endl;

	return in;
}

fstream& operator >> (fstream& fin, Time& p){
	fin >> p.sec;
	fin >> p.min;

	return fin;
}
fstream& operator << (fstream& fout, const Time& p){
	fout << p.sec << "\n" << p.min << "\n";

	return fout;
}

bool Time::operator == (const Time& t){
	if ((min == t.min) && (sec == t.sec)) { return true; } else { return false; }
}
```

# Тест

```cpp
1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 1
File name: f1
Amount of entries: 6
min: 10
sec: 30

min: 22
sec: 14

min: 43
sec: 22

min: 12
sec: 33

min: 78
sec: 22

min: 16
sec: 16


1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[10:30]
[22:14]
[43:22]
[12:33]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 7
File name: f1
Time to delete:
min: 12
sec: 33

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[10:30]
[22:14]
[43:22]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 8
File name: f1
Time to lower:
min: 10
sec: 30

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[9:0]
[22:14]
[43:22]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 9
File name: f1
Time to add after:
min: 22
sec: 14

How many elements to add: 2
min: 13
sec: 13

min: 14
sec: 14

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[9:0]
[22:14]
[13:13]
[14:14]
[43:22]
[78:22]
[16:16]
```

# Вопросы

1. **Что такое поток?**
   
   Абстракция, которая представляет последовательность байтов или символов.

2. **Какие типы потоков существуют?**
   
   Ввода, вывода и двунаправленные

3. **Какую библиотеку надо подключить при использовании стандартных потоков?**
   
   iostream

4. **Какую библиотеку надо подключить при использовании файловых потоков?**
   
   fstream

5. **Какую библиотеку надо подключить при использовании строковых потоков?**
   
   sstream

6. **Какая операция используется при выводе в форматированный поток?**
   
   '<<'

7. **Какая операция используется при вводе из форматированных потоков?**
   
   '>>'

8. **Какие методы используются при выводе в форматированный поток?**
   
   put(), write(), перегруженный '<<'

9. **Какие методы используется при вводе из форматированного потока?**
   
   get(), read(), getline(), перегруженный '>>'

10. **Какие режимы для открытия файловых потоков существуют?**
    
    чтение, запись, добавление в конец файла, перемещение указателя в конец файла, обрезание файла, бинарный режим

11. **Какой режим используется для добавления записей в файл?**
    
    Добавление в конец файла

12. **Какой режим (комбинация режимов) используется в конструкторе ifstream file("f.txt")?**
    
    Чтение

13. **Какой режим (комбинация режимов) используется в конструкторе fstream file("f.txt")?**
    
    Чтение / Запись

14. **Какой режим (комбинация режимов) используется в конструкторе ofstream file("f.txt")?**
    
    Запись

15. **Каким образом открывается поток в режиме ios::out|ios::app?**
    
    Конструктором или методом open() с указанием режимов

16. **Каким образом открывается поток в режиме ios::out |ios::trunc?**
    
    Конструктором или методом open() с указанием режимов

17. **Каким образом открывается поток в режиме ios::out |ios::in|ios::trunc?**
    
    Конструктором или методом open() с указанием режимов

18. **Каким образом можно открыть файл для чтения?**
    
    конструктор ifstream или метод open() с указанием пути к файлу

19. **Каким образом можно открыть файл для записи?**
    
    конструктор ofstream или метод open() с указанием пути к файлу

20. **Привести примеры открытия файловых потоков в различных режимах.**
    
    ```cpp
    std::ofstream out("file.txt"); // Открытие для записи, режим ios::out
    std::ifstream in("file.txt"); // Открытие для чтения, режим ios::in
    std::fstream fs("file.txt", std::ios::in | std::ios::out); // Открытие для чтения и записи
    std::ofstream out_app("file.txt", std::ios::app); // Открытие для добавления в конец файла
    ```

21. **Привести примеры чтения объектов из потока.**
    
    ```cpp
    int number;
    std::ifstream in("file.txt");
    in >> number; // Чтение числа из файла
    ```

22. **Привести примеры записи объектов в поток.**
    
    ```cpp
    int number = 42;
    std::ofstream out("file.txt");
    out << number; // Запись числа в файл
    ```

23. **Сформулировать алгоритм удаления записей из файла.**
    
    ```cpp
    1. Создать временный файл для записи.
    2. Открыть исходный файл для чтения.
    3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
    4. Инициализировать счетчик прочитанных записей.
    5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
    	- Если достигнут конец файла, прервать чтение.
    	- Увеличить счетчик прочитанных записей.
    	- Если номер текущей записи не равен заданному номеру k, записать её во временный файл.
    6. Закрыть исходный и временный файлы.
    7. Удалить исходный файл.
    8. Переименовать временный файл в исходный.
    9. Вернуть количество прочитанных записей.
    
    Данная функция принимает название файла (полный путь), номер элемента который нужно удалить.
    ```

24. **Сформулировать алгоритм добавления записей в файл.**
    
    ```cpp
    1. Создать временный файл для записи.
    2. Открыть исходный файл для чтения.
    3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
    4. Инициализировать счетчики прочитанных и добавленных записей.
    5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
    	- Если достигнут конец файла, прервать чтение.
    	- Увеличить счетчик прочитанных записей.
    	- Если номер текущей записи равен заданному номеру k, записать новую запись во временный файл и увеличить счетчик добавленных записей, иначе - записать текущую запись во временный файл.
    6. Закрыть исходный и временный файлы.
    7. Удалить исходный файл.
    8. Переименовать временный файл в исходный.
    9. Вернуть количество добавленных записей.
    
    Данная функция принимает название файла (полный путь), номер элемента, куда нужно вставить запись и запись, которую нужно вставить.
    ```

25. **формулировать алгоритм изменения записей в файле.**
    
    ```cpp
    1. Создать временный файл для записи.
    2. Открыть исходный файл для чтения.
    3. Проверить, удалось ли открыть исходный файл. Если нет, вернуть -1 как признак ошибки.
    4. Инициализировать счетчики прочитанных и измененных записей.
    5. Читать записи из исходного файла до тех пор, пока не достигнут конец файла.
    	- Если достигнут конец файла, прервать чтение.
    	- Увеличить счетчик прочитанных записей.
    	- Если номер текущей записи равен заданному номеру k, записать измененную запись во временный файл и увеличить счетчик измененных записей, иначе - записать текущую запись во временный файл.
    6. Закрыть исходный и временный файлы.
    7. Удалить исходный файл.
    8. Переименовать временный файл в исходный.
    9. Вернуть количество измененных записей.
    
    Данная функция принимает название файла (полный путь), номер элемента, который нужно изменить и запись, на которую нужно изменить запись с указанным номером.
    ```
