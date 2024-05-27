#pragma once
#include <string>
#include <iostream>

using namespace std;

class Error {
public:
	virtual void what() {};
};

class IndexError : public Error {
protected:
	string msg;
public:
	IndexError() { msg = "Index Error.\n"; }
	virtual void what() { cout << msg; }
};

class SizeError : public Error {
protected:
	string msg;
public:
	SizeError() { msg = "Size Error.\n"; }
	virtual void what() { cout << msg; }
};