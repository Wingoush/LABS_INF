#include <iostream>
#include "Vector.h"

using namespace std;

int main(){
	Vector v(5);
	cout << "Vector v: " << v << endl;
	cin >> v;
	cout << "Vector v: " << v << endl;

	v[3] = 9999;
	cout << endl <<  "Vector v, 4 element changed to 9999: " << v << endl << endl;

	Vector v2(6, 40);
	cout << "Vector v2: " << v2 << endl;
	Vector v3(8);
	cout << "Vector v3: " << v3 << endl;
	v3 = v2 + 60;
	cout << "Vector v3, =v2 and +60: " << v3 << endl;

	Iterator iter;
	iter = v.last(); --iter;
	cout << endl <<  "Vector v, last element: " << *iter << endl;
	--iter;
	cout << "Vector v, pre-last element: " << *iter << endl;

	cout << endl << "Vector v, print through iterator: ";
	for (iter = v.first(); iter != v.last(); ++iter) {
		cout << "[" << *iter << "] ";
	}

	return 0;
}
/*
Test

Vector v: [0] [0] [0] [0] [0]
Input 1 element: 10
Input 2 element: 20
Input 3 element: 30
Input 4 element: 40
Input 5 element: 50
Vector v: [10] [20] [30] [40] [50]

Vector v, 4 element changed to 9999: [10] [20] [30] [9999] [50]

Vector v2: [40] [40] [40] [40] [40] [40]
Vector v3: [0] [0] [0] [0] [0] [0] [0] [0]
Vector v3, =v2 and +60: [100] [100] [100] [100] [100] [100]

Vector v, last element: 50
Vector v, pre-last element: 9999

Vector v, print through iterator: [10] [20] [30] [9999] [50]
*/