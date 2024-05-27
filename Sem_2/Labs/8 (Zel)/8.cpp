#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stadium {
    stadium* next = nullptr;
    stadium* prev = nullptr;

    string name;
    int year;
    int fields;
    int sports;
};

struct list {
    stadium* head = nullptr;
    stadium* tail = nullptr;
    int size = 0;

    void push(stadium* stad);
    void remove(int index);
    void add(stadium* stad, int index);
    void write(ofstream& out);
    void read(ifstream& in);
    void print();
};

void print_stadium(stadium* stad) {
    cout << endl
        << "    Name:    " << stad->name << endl
        << "    Year:    " << stad->year << endl
        << "    Fields:  " << stad->fields << endl
        << "    Sports:  " << stad->sports << endl << endl;

    return;
}

stadium* add_stadium() {
    stadium* stad = new stadium;

    string s;
    int i;

    cout << "Stadium name: ";
    cin >> s;
    stad->name = s;

    cout << "Year: ";
    cin >> i;
    stad->year = i;

    cout << "Fields: ";
    cin >> i;
    stad->fields = i;

    cout << "Number of sports: ";
    cin >> i;
    stad->sports = i;

    cout << endl;
    return stad;
}

void list::push(stadium* stad) {
    if (size == 0) {
        head = stad;
        tail = stad;

        stad->prev = nullptr;
        stad->next = nullptr;

        size = 1;
    } else {
        stad->prev = head;
        head->next = stad;
        head = stad;

        size++;
    }

    return;
}

void list::remove(int index) {
    if (index > size || index < 0) {
        cout << "Error. Invalid index." << endl;
        return;
    }

    if (size == 1) {
        delete tail;
        tail == nullptr;
        head == nullptr;

        size = 0;
        return;
    }

    stadium* temp = tail;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        temp->prev->next = nullptr;
        head = temp->prev;
    } else if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    if (temp->prev == nullptr) {
        temp->next->prev = nullptr;
        tail = temp->next;
    }else if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    }

    size--;
    delete temp;

    return;
}

void list::add(stadium* stad, int index) {

    stadium* temp = tail;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    if (temp->prev == nullptr) {
        stad->next = tail;

        tail->prev = stad;
        tail = stad;
    } else {
        stad->next = temp;
        stad->prev = temp->prev;

        temp->prev->next = stad;
        temp->prev = stad;
    }

    size++;

    return;
}

void list::print() {
    if (size > 0) {
        stadium* temp = tail;

        for (int i = 0; i < size; i++) {
            cout << i + 1 << " Stadium:";
            if (i > 0) { temp = temp->next; }
            print_stadium(temp);
        }
    } else {
        cout << "No stadiums." << endl << endl;
    }

    return;
}

void list::write(ofstream& out) {
    if (size > 0) {
        stadium* temp = tail;

        for (int i = 0; i < size; i++) {
            if (i > 0) { temp = temp->next; }
            out << "Name: " << temp->name << endl
                << "Year: " << temp->year << endl
                << "Fields: " << temp->fields << endl
                << "Sports: " << temp->sports << endl << endl;
        }
    }else {
        cout << "Nothing to write in file.";
    }

    return;
}

void list::read(ifstream& in) {
    stadium* temp;

    string line;
    int i;

    while (!in.eof() && in.peek() != -1) {

        temp = new stadium;

        in >> line >> line;
        temp->name = line;

        in >> line;
        in >> i;
        temp->year = i;

        in >> line;
        in >> i;
        temp->fields = i;

        in >> line;
        in >> i;
        temp->sports = i;

        push(temp);
    }

    return;
}

int main() {
    ifstream in;
    in.open("File1");

    if (!in) {
        cout << "Error. Can't open file 'File1'." << endl;
        return 1;
    }

    list stadiums;
    stadiums.read(in);
    stadiums.print();

    in.close();

    int min_year;
    stadium* temp = stadiums.tail;

    cout << "Year (less than) to delete: ";
    cin >> min_year;

    for (int i = 0; temp != nullptr; i++) {
        if (temp->year < min_year) {
            temp = temp->next;
            stadiums.remove(i);
            i--;
        } else {
            temp = temp->next;
        }
    }

    stadiums.print();

    int index;
    cout << "Insert before index: ";
    cin >> index;

    if (index > stadiums.size || index < 0) {
        cout << "Error. Invalid index." << endl;
    } else {
        stadiums.add(add_stadium(), index);
        stadiums.add(add_stadium(), index + 1);
    }

    stadiums.print();


    ofstream out;
    out.open("File2");

    if (!out) {
        cout << "Error. Can't open 'File2'." << endl;
        return 1;
    }

    stadiums.write(out);
    out.close();

    return 0;
}
/*
Test

1 Stadium:
    Name:    Alpha
    Year:    1990
    Fields:  80
    Sports:  40
2 Stadium:
    Name:    Bravo
    Year:    2000
    Fields:  100
    Sports:  100
3 Stadium:
    Name:    Charlie
    Year:    1995
    Fields:  15
    Sports:  5
4 Stadium:
    Name:    Delta
    Year:    2005
    Fields:  16
    Sports:  3

Year (less than) to delete: 2000
1 Stadium:
    Name:    Bravo
    Year:    2000
    Fields:  100
    Sports:  100
2 Stadium:
    Name:    Delta
    Year:    2005
    Fields:  16
    Sports:  3

Insert before index: 1
Stadium name: Echo
Year: 1660
Fields: 30
Number of sports: 15

Stadium name: Foxtrot
Year: 1990
Fields: 5
Number of sports: 4

1 Stadium:
    Name:    Bravo
    Year:    2000
    Fields:  100
    Sports:  100
2 Stadium:
    Name:    Echo
    Year:    1660
    Fields:  30
    Sports:  15
3 Stadium:
    Name:    Foxtrot
    Year:    1990
    Fields:  5
    Sports:  4
4 Stadium:
    Name:    Delta
    Year:    2005
    Fields:  16
    Sports:  3
*/