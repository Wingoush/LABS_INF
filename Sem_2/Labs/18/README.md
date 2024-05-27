Романов Артём ИВТ-23-1Б

# Лабораторная работа №18 - HASH-Таблица

Вариант 20.

Данные: ФИО человека, его дата рождения и номер паспорта

Ключ - дата рождения

HASH - функция: H(k) = [M(k * a * mod1)], 0 < A < 1, mod1 - дробная часть, [] - целая часть.

Метод рехеширования - метод цепочек.

## Блок - схема

## Код

```cpp
#include <iostream>
#include <string>

using namespace std;

string name[30] = { "Oleg", "Alexander", "Vladimir", "Elena", "Eva", "Adam", "Adam", "Vergillius", "Nikita", "Vladislav", "Andrew", "Thomas", "Kyle", "Mario", "Luigi", "Odin", "Thor", "Hercules", "Hades", "Triton", "Gefest", "Charon", "Angela", "Matthew", "Jorge", "Sinclair", "Medusa", "Theresa", "Irina", "Maria" };
string patronymic[30] = { "Olegov", "Olegovna", "Vladimirov", "Vladimirovna", "Adamov", "Adamovna", "Andreevich", "Andreevna", "Thomasov", "Thomasovna","Evgeniev", "Evgenievna", "Nikitych", "Alexandrovna", "Alexandrov", "Mikhailov", "Mikhailovna", "Makarov", "Makarovna", "Kirillov", "Kirillovna", "Konstantinov", "Konstantinovna", "Germanov", "Germanovna", "Innokentiev", "Innokentieva", "Bogdanov", "Bogdanovna", "Vasilyev" };
string surname[30] = { "Karpov", "Karpovna", "Vlasov","Vlasovna","Tihonov","Tihonovna","Gavriilov","Gavriilovna","Rodionov","Rodionovna","Kotov","Kotova","Bykov","Bykovna","Tretyakov","Tretyakovna","Smirnov","Smirnova","Suvorov","Suvorovna","Voronov","Voronovna","Arhipov","Arhipovna","Martynov","Martynova","Gorshkov","Gorshkova","Ovchinnikov","Ovcinnikovna" };
string passport[30] = { "571721","532521","232371","829321","323612","992999","921310","010395","865201","889211","111628","561217","915986","303490","901785","725524","714542","201175","802147","500011","328271","312131","278328","373278","282114","982348","238178","412211","327284","557211" };
string dates[30] = { "12.12.2011","18.05.1030","09.01.2000","21.03.2003","19.10.2010","23.09.2009","24.10.2010","25.11.2011","26.12.2012","27.01.1988","28.02.1967","29.04.1999","30.05.1867","31.12.1999","01.06.1976","02.07.1980","03.08.1982","04.09.1955","05.10.1948","06.11.2014","16.05.1977","29.06.2004","19.02.2001","09.11.1996","27.03.2002","30.10.2000","27.08.2022","28.02.2019","29.10.1932","30.09.2014" };
int collisions = 0;

struct Person {
    Person() { name = "NULL"; passport = "NULL"; birthday = "NULL"; }
    string name, passport, birthday;
};

struct hashTable {
    Person* arr;

    hashTable(int size) { arr = new Person[size]; }
    ~hashTable() { delete[] arr; }

    void search(string bday, const int size);
    void add(Person tmp, const int size);
};

void showTable(hashTable* table, const int size);
void show(const Person tmp);

Person personCreator();

int get_string(string str);

void printPerson(const Person* const arr, const int size);
int hashFunc(string str, const int size);
void createArray(Person* arr, const int collisions);


void hashTable::search(string bday, const int size) {
    int hash = hashFunc(bday, size);
    int index = hash;

    while (arr[index].birthday != bday && index < size) { index++; }
    if (index >= size) {
        index = 0;
        while (arr[index].birthday != bday && index < hash) { index++; }
        if (index >= hash) { cout << "Person with date of birth " << bday << " not found." << endl; }
        else { cout << "Person with date of birth " << bday << " found. Index " << index << endl; }
    }
    else { cout << "Person with date of birth " << bday << " found. Index " << index << endl; }
}


void hashTable::add(Person tmp, const int size) {
    int index = hashFunc(tmp.birthday, size);
    int hash = index;
    if (arr[index].name == "NULL") {
        arr[index] = tmp; return;
    }
    else {
        while (index < size) {
            if (arr[index].name == "NULL") { arr[index] = tmp; return; }
            index++;
            collisions++;
        }

        if (index >= size) {
            index = 0;
            collisions++;
            while (index < hash) {
                if (arr[index].name == "NULL") {
                    arr[index] = tmp;
                    return;
                }
                index++;
                collisions++;
            }
        }
    }
}

Person personCreator() {
    Person tmp;

    tmp.name = surname[rand() % 30] + " " + name[rand() % 30] + " " + patronymic[rand() % 30];
    tmp.birthday = dates[rand() % 30];
    tmp.passport = passport[rand() % 30];

    return tmp;
}

void show(const Person tmp) {
    cout << "Name: " << tmp.name << endl;
    cout << "Date of birth: " << tmp.birthday << endl;
    cout << "Passport: " << tmp.passport << endl;
    cout << "\n";
}

void printPerson(const Person* const arr, const int size) {
    for (int i = 0; i < size; i++) { show(arr[i]); }
}

void createArray(Person* arr, const int collisions) {
    for (int i = 0; i < collisions; i++) { arr[i] = personCreator(); }
}

int get_string(string str) {
    string yam = dates[11];
    int sum = stoi(yam);
    return sum;
}

int hashFunc(string str, const int size) {
    double a = 0.618 * get_string(str);
    double c = size * (a - static_cast<int>(a));
    return static_cast<int>(c);
}

void showTable(hashTable* table, const int size) {
    for (int i = 0; i < size; i++) { show(table->arr[i]); }
}

int main() {
    srand(time(0));
    int sizeArr;
    cout << "Input array size: "; cin >> sizeArr;

    Person* arr = new Person[sizeArr];
    hashTable table(sizeArr);
    createArray(arr, sizeArr);
    for (int i = 0; i < sizeArr; i++) { table.add(arr[i], sizeArr); }

    showTable(&table, sizeArr);

    table.search(dates[11], sizeArr);
    cout << "Collisions in the hash table, with the array size of " << sizeArr << ": " << collisions << endl;

    delete[] arr;
    return 0;
}
/*
Test:

Input array size: 3
Name: Smirnova Angela Makarov
Date of birth: 04.09.1955
Passport: 561217

Name: Rodionovna Mario Thomasov
Date of birth: 30.09.2014
Passport: 714542

Name: Tretyakov Eva Andreevich
Date of birth: 27.08.2022
Passport: 282114

Person with date of birth 29.04.1999 not found.
Collisions in the hash table, with the array size of 3: 5
*/
```

## Тест

```cpp
Input array size: 3
Name: Smirnova Angela Makarov
Date of birth: 04.09.1955
Passport: 561217

Name: Rodionovna Mario Thomasov
Date of birth: 30.09.2014
Passport: 714542

Name: Tretyakov Eva Andreevich
Date of birth: 27.08.2022
Passport: 282114

Person with date of birth 29.04.1999 not found.



Name: Smirnova Angela Makarov
Date of birth: 04.09.1955
Passport: 561217

Name: Rodionovna Mario Thomasov
Date of birth: 30.09.2014
Passport: 714542

Name: Tretyakov Eva Andreevich
Date of birth: 27.08.2022
Passport: 282114

Collisions in the hash table, with the array size of 3: 5
```
