Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 11, Вариант 23 - Информационные динамические структуры

Задание:

    Записи в линейном списке содержат ключевое поле типа
*char(строка символов). Сформировать двунаправленный
список. Удалить элемент с заданным ключом. Добавить К
элементов после элемента с заданным ключом.

# Блок-Схема

# Код

```cpp
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct node {
    node* next = nullptr;
    node* prev = nullptr;

    string s;
};

struct list {
    node* head = nullptr;
    node* tail = nullptr;

    int size = 0;

    void push(node* n);
    void remove(string key);
    void add(node* n, string key);
    void write(ofstream& out);
    void read(ifstream& in);
    void print();
};

void list::push(node* n) {
    if (size == 0) {
        head = n;
        tail = n;

        size = 1;
    }
    else {
        head->next = n;
        n->prev = head;

        head = n;

        size++;
    }
    return;
}

void list::remove(string key) {
    node* temp = tail;

    if (size == 0) { return; }

    for (; temp != nullptr; temp = temp->next) {
        if (temp->s == key) {
            if (size == 1) {
                delete tail;
                tail == nullptr;
                head == nullptr;

                return;
            }
            else if (temp->next == nullptr) {
                temp->prev->next = nullptr;
                head = temp->prev;
            }
            else if (temp->prev == nullptr) {
                temp->next->prev = nullptr;
                tail = temp->next;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
        }
    }
    size--;
    delete temp;
    return;
}

void list::add(node* n, string key) {
    node* temp = tail;

    for (; temp != nullptr; temp = temp->next) {
        if (temp->s == key) {
            if (temp->next == nullptr) {
                head->next = n;
                n->prev = head;

                head = n;
            }
            else {
                n->next = temp->next;
                n->prev = temp;

                temp->next->prev = n;
                temp->next = n;
            }

            size++;
            return;
        }
    }
}

void list::print() {
    if (size > 0) {
        node* temp = tail;
        for (; temp != nullptr; temp = temp->next) {
            cout << temp->s << endl;
        }
    }
    else {
        cout << "List is empty.";
    }
    return;
}

void list::write(ofstream& out) {
    if (size > 0) {
        node* temp = tail;
        for (; temp != nullptr; temp = temp->next) {
            out << temp->s << endl;
        }
    }
}

void list::read(ifstream& in) {
    node* temp;

    while (!in.eof() && in.peek() != -1) {
        temp = new node;

        in >> temp->s;

        push(temp);
    }
}

int main() {
    list strs;

    ifstream in;
    in.open("F1");

    if (!in) {
        cerr << "Error. File 'F1' is not open." << endl;
    }

    strs.read(in);
    strs.print();

    string key;
    cout << "String to delete (by key): ";
    cin >> key;

    strs.remove(key);
    strs.print();


    cout << "Add elements after string (by key): ";
    cin >> key;

    int amount;
    cout << "Amount of new elements: ";
    cin >> amount;

    for (int k = 0; k < amount; k++) {
        node* temp = new node;
        cout << k + 1 << " new element's key: ";
        cin >> temp->s;

        strs.add(temp, key);
    }

    in.close();


    ofstream out;

    out.open("F2");

    if (!out) {
        cerr << "Error. File 'F2' is not open." << endl;
    }

    strs.print();
    strs.write(out);
    out.close();

    return 0;
}
/*
Тест

Alpha
Bravo
Charlie
Delta
Echo
Foxtrot
Golf
Hotel
Juliet
Kilo

String to delete (by key): Golf
Alpha
Bravo
Charlie
Delta
Echo
Foxtrot
Hotel
Juliet
Kilo

Add elements after string (by key): Alpha
Amount of new elements: 2
1 new element's key: Sierra
2 new element's key: Tango
Alpha
Tango
Sierra
Bravo
Charlie
Delta
Echo
Foxtrot
Hotel
Juliet
Kilo
*/
```

# Тест

```cpp
Alpha
Bravo
Charlie
Delta
Echo
Foxtrot
Golf
Hotel
Juliet
Kilo

String to delete (by key): Golf

Alpha
Bravo
Charlie
Delta
Echo
Foxtrot
Hotel
Juliet
Kilo

Add elements after string (by key): Alpha
Amount of new elements: 2

1 new element's key: Sierra
2 new element's key: Tango

Alpha
Tango
Sierra
Bravo
Charlie
Delta
Echo
Foxtrot
Hotel
Juliet
Kilo
```
