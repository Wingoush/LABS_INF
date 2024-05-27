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