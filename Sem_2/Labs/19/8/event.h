#pragma once

const int emptyEvent = 0;
const int evMessage = 100;
const int groupAdd = 1;
const int groupRemove = 2;
const int groupShow = 3;
const int groupCreate = 4; 
const int averageAge = 5;
const int programEnd = 101;

struct TEvent{
	int what;
	union{
		int command;
		struct{
			int message;
			int value;
		};
	};
};