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