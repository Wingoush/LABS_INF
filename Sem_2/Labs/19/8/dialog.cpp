#pragma once
#include <iostream>
#include <string>
#include "dialog.h"
#include "event.h"
#include "vector.h"
#include "object.h"

using namespace std;

Dialog::Dialog() : Vector() { EndState = 0; }
Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event){
	string OpInt = "+-s/qmz";
	string str;
	string param;
	char code;

	cout << ">";
	cin >> str; code = str[0];

	if (OpInt.find(code) < INT64_MAX) {
		event.what = evMessage;

		switch (code){
		case 'm': event.command = groupCreate; break;
		case '+': event.command = groupAdd; break;
		case '-': event.command = groupRemove; break;
		case 's': event.command = groupShow; break;
		case 'q': event.command = programEnd; break;
		case 'z': event.command = averageAge; break;
		}

		if (str.length() > 1){
			param = str.substr(1, str.length() - 1);
			int A = atoi(param.c_str());
			event.value = A;
		}

	} else { event.what = emptyEvent; }
}

int Dialog::Execute(){
	TEvent event;

	do{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());

	return EndState;
}

int Dialog::Valid(){
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event){
	event.what = emptyEvent;
}
void Dialog::EndExec(){
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event){
	if (event.what == evMessage){
		switch (event.command) {
		case groupCreate: {
			size = event.value;

			if (event.value <= 0) {
				cout << "Error: group size is less than 0." << endl;
				break;
			}

			start = new Object * [size];
			cout << "Created a group of size " << event.value << ".\n";
			cur = 0;
			ClearEvent(event);
			break;
		}

		case groupAdd: {
			Add();
			ClearEvent(event);
			break;
		}

		case groupRemove: {
			Del();
			cout << "Removed last element from group." << endl;
			ClearEvent(event);
			break;
		}

		case groupShow: {
			cout << "===========================" << endl;
			Show();
			cout << "===========================" << endl;
			ClearEvent(event);
			break;
		}

		case programEnd: {
			EndExec();
			ClearEvent(event);
			break;
		}

		case averageAge: {
			Vector::HandleEvent(event);
			ClearEvent(event);
			break;
		}

		default:{
				ClearEvent(event);
				break;
			}
		}
	};
}