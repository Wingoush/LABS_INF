#include <iostream>
#include <string>
#include "dialog.h"
#include "event.h"
#include "vector.h"
#include "object.h"

int main(){
	Dialog D;
	D.Execute();
	return 0;
}
/*
Test:

>m3
Created a group of size 3.
>s
===========================
Group is empty.
===========================
>+
1. Person
2. Abiturient
Input type to add (1-2): 1
Input name: Dante
Input age: 11

Added person into group.
>+
1. Person
2. Abiturient
Input type to add (1-2): 2

Input name: Vergillius
input age: 20
Input score: 180
Input speciality: KT
Added abiturient into group.
>+
1. Person
2. Abiturient
Input type to add (1-2): 1
Input name: Charon
Input age: 29

Added person into group.
>s
===========================
Name: Dante
Age: 11
---------------------------
Name: Vergillius
Age: 20
Score: 180
Speciality: KT
---------------------------
Name: Charon
Age: 29
---------------------------
===========================
>z
Average age of group: 20
>-
Removed last element from group.
>z
Average age of group: 15.5
*/