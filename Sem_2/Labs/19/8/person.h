#pragma once
#include "object.h"
#include "event.h"

using namespace std;

class Person : public Object{
public:
	Person();
	Person(string, int);
	Person(const Person&);
	virtual ~Person();

	void Show();
	void Input();

	string getName() { return name; }
	int getAge() { return age; }

	void setName(string);
	void setAge(int);

	Person& operator=(const Person&);

	virtual int HandleEvent(const TEvent& e);
protected:
	string name;
	int age;
};