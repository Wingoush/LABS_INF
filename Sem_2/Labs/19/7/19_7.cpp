#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

int main(){
	Vector<int> v(5, 0);
	cout << "Vector v: " << v << endl;
	cin >> v;
	cout << "Vector v: " << v << endl << endl;

	Vector<int> v2(10, 1);
	cout << "Vector v2: " << v2 << endl;
	v2 = v + 24;
	cout << "Vector v2, =v1 + 24: " << v2 << endl;

	cout << "Vector v2, 3rd element: " << v2[2] << endl << endl;
	Vector<int> v3(4, 5);
	cout << "Vector v3: " << v3 << endl;
	v3 = v3+v2;
	cout << "Vector v3, +v2: " << v3 << endl << endl;

	Time t;
	cout << "Time t: " << t << endl;
	cin >> t;
	cout << "Time t: " << t << endl;

	Time k;
	cout << "Input additional time: " << endl; cin >> k;
	Time p;
	p = t+k;
	cout << "Time t, +additional time: " << p << endl << endl;

	Vector<Time> t2(2, t); cin >> t2; cout << "Time t2, parametrized: " << t2 << endl;
	Vector<Time> t3(2, t); cin >> t3; cout << "Time t3, parametrized: " << t3 << endl;
	t3 = t2;
	cout << "Time t3, =t2: " << t3 << endl;
	cout << "Time t3, 2rd element: " << t3[1] << endl;

	return 0;
}
/*
Test:

Vector v: [0] [0] [0] [0] [0]
Input 1 element: 1
Input 2 element: 2
Input 3 element: 3
Input 4 element: 4
Input 5 element: 5
Vector v: [1] [2] [3] [4] [5]

Vector v2: [1] [1] [1] [1] [1] [1] [1] [1] [1] [1]
Vector v2, =v1 + 24: [25] [26] [27] [28] [29]
Vector v2, 3rd element: 27

Vector v3: [5] [5] [5] [5]
Vector v3, +v2: [30] [31] [32] [33]

Time t: 0 : 0
Input minutes: 50
Input seconds: 55
Time t: 50 : 55
Input additional time:
Input minutes: 10
Input seconds: 5
Time t, +additional time: 61 : 0

Input 1 element: Input minutes: 50
Input seconds: 51
Input 2 element: Input minutes: 40
Input seconds: 41
Time t2, parametrized: [50 : 51] [40 : 41]
Input 1 element: Input minutes: 30
Input seconds: 31
Input 2 element: Input minutes: 20
Input seconds: 21
Time t3, parametrized: [30 : 31] [20 : 21]
Time t3, =t2: [50 : 51] [40 : 41]
Time t3, 2rd element: 40 : 41
*/