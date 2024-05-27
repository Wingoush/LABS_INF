#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
#include "money.h"

using namespace std;

Money s;
Money sumMinMax(0, 0);

struct EqualTo{
	bool operator()(Money t){
		return t == s;
	}
};

struct CompareTwo{
	bool operator()(Money t1, Money t2){
		if (t1 > t2) { return true; }
		else {return false;}
	}
};

void sumAdd(Money& t){
	t = t + sumMinMax;
}

vector<Money> makeVector(int n){
	Money money;
	vector<Money> v;

	for (int i = 0; i < n; i++){
		cin >> money;
		v.push_back(money);
	}

	return v;
}

void printVector(vector<Money> v){
	for (int i = 0; i < v.size(); i++) { cout << v[i] << endl; }

	cout << endl;
}

queue<Money> makeQueue(int n){
	Money money;
	queue<Money> q;

	for (int i = 0; i < n; i++){
		cin >> money;
		q.push(money);
	}

	return q;
}

void printQueue(queue<Money> q){
	Money tmp;

	for (int i = 0; i < q.size(); i++){
		tmp = q.front();
		q.pop();
		cout << tmp << endl;
		q.push(tmp);
	}

	cout << endl;
}

vector<Money> copyQueueToVector(queue<Money> q){
	vector<Money> result;
	Money tmp;

	for (int i = 0; i < q.size(); i++){
		tmp = q.front();
		q.pop();
		result.push_back(tmp);
		q.push(tmp);
	}

	return result;
}

queue<Money> copyVectorToQueue(vector<Money> v){
	queue<Money> result;
	Money tmp;

	for (int i = 0; i < v.size(); i++){
		result.push(v[i]);
	}

	return result;
}

void sortQueueIncrement(queue<Money>& q){
	vector<Money> v(copyQueueToVector(q));
	sort(v.begin(), v.end());

	q = copyVectorToQueue(v);
}

void sortQueueDecrement(queue<Money>& q){
	vector<Money> v(copyQueueToVector(q));
	sort(v.begin(), v.end(), CompareTwo())
		;
	q = copyVectorToQueue(v);
}

Money queueMin(queue<Money> q){
	vector<Money> v(copyQueueToVector(q));
	auto i = min_element(v.begin(), v.end());

	return (*i);
}

Money queueMax(queue<Money> q){
	vector<Money> v(copyQueueToVector(q));
	auto i = max_element(v.begin(), v.end());

	return (*i);
}

Money queueFindS(queue<Money> q, Money s){
	vector<Money> v(copyQueueToVector(q));

	Money result(INT64_MAX, INT32_MAX);
	auto i = find_if(v.begin(), v.end(), EqualTo());

	if (i != v.end()){
		cout << "Element " << *i << " found." << endl;
		result = (*i);
		return result;
	}
	else { cout << "Error: element not found." << endl; }

	return result;
}

void queueRemoveS(queue<Money>& q, Money s){
	vector<Money> v(copyQueueToVector(q));

	auto i = remove_if(v.begin(), v.end(), EqualTo());
	v.erase(i, v.end());

	q = copyVectorToQueue(v);
}

void queueMinMaxAdder(queue<Money>& q){
	vector<Money> v(copyQueueToVector(q));

	sumMinMax = sumMinMax + queueMin(q);
	sumMinMax = sumMinMax + queueMax(q);
	for_each(v.begin(), v.end(), sumAdd);

	q = copyVectorToQueue(v);
}

map<int, Money> makeMap(int n){
	map<int, Money> m;
	Money money;

	for (int i = 0; i < n; i++){
		cin >> money;
		m.insert(make_pair(i, money));
	}
	return m;
}

void printMap(map<int, Money> m){
	for (int i = 0; i < m.size(); i++) { cout << i << " - " << m[i] << endl; }
}

int mapMaxElemKey(map<int, Money> v){
	auto i = v.begin();
	int nom = 0, k = 0;
	Money m = (*i).second;

	while (i != v.end()){
		if (m < (*i).second){
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}

	return nom;
}

int mapMinElemKey(map<int, Money> v){
	auto i = v.begin();
	int nom = 0, k = 0;
	Money m = (*i).second;

	while (i != v.end()){
		if (m > (*i).second){
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}

	return nom;
}

void delOneElemMap(map<int, Money>& mmm, int key){
	if (key >= mmm.size()) { return; }

	vector<Money> v;

	for (int i = 0; i < key; i++){
		v.push_back(mmm[i]);
	}
	for (int i = key + 1; i < mmm.size(); i++){
		v.push_back(mmm[i]);
	}
	map<int, Money> m;
	for (int i = 0; i < v.size(); i++){
		m.insert(make_pair(i, v[i]));
	}
	mmm = m;
}

void sortMapIncrement(map<int, Money>& mmm){
	vector<Money> v;

	for (int i = 0; i < mmm.size(); i++){
		v.push_back(mmm[i]);
	}

	sort(v.begin(), v.end());
	map<int, Money> m;
	
	for (int i = 0; i < v.size(); i++){
		m.insert(make_pair(i, v[i]));
	}

	mmm = m;
}

void sortMapDecrement(map<int, Money>& mmm){
	vector<Money> v;

	for (int i = 0; i < mmm.size(); i++){
		v.push_back(mmm[i]);
	}

	sort(v.begin(), v.end(), CompareTwo());
	map<int, Money> m;
	
	for (int i = 0; i < v.size(); i++){
		m.insert(make_pair(i, v[i]));
	}
	
	mmm = m;
}

void minMaxAddToMap(map<int, Money>& mmm){
	vector<Money> v;

	for (int i = 0; i < mmm.size(); i++){
		v.push_back(mmm[i]);
	
	}
	for_each(v.begin(), v.end(), sumAdd);
	map<int, Money> m;
	
	for (int i = 0; i < v.size(); i++){
		m.insert(make_pair(i, v[i]));
	}
	
	mmm = m;
}

int main(){
	int n;

	cout << "Task 1 - Vector." << endl;
	cout << "Input vector size: ";	cin >> n;

	vector<Money> v;
	v = makeVector(n);
	printVector(v);

	auto i = min_element(v.begin(), v.end());
	cout << "Min element: " << *i << endl;
	v.push_back(*i);
	printVector(v);

	cout << "Input key for removal: \n";
	cin >> s;
	i = find_if(v.begin(), v.end(), EqualTo());
	if (i != v.end()) { cout << "Element " << *(i) << " found." << endl; }
	else { cout << "Error: element not found." << endl; }		
	i = remove_if(v.begin(), v.end(), EqualTo());
	v.erase(i, v.end());
	printVector(v);

	cout << "Increment sort:" << endl;
	sort(v.begin(), v.end());
	printVector(v);
	cout << "Decrememt sort:" << endl;
	sort(v.begin(), v.end(), CompareTwo());
	printVector(v);

	cout << "Add min+max to all values:" << endl;
	i = min_element(v.begin(), v.end());
	sumMinMax = sumMinMax + (*i);
	i = max_element(v.begin(), v.end());
	sumMinMax = sumMinMax + (*i);
	for_each(v.begin(), v.end(), sumAdd);
	printVector(v);
	sumMinMax.setKop(0); sumMinMax.setRub(0);

	cout << "Task 2 - Queue." << endl;
	cout << "Input queue size: "; cin >> n;
	queue<Money> q;
	q = makeQueue(n);
	printQueue(q);

	Money qElem = queueMin(q);
	cout << "Minimal element: " << qElem << endl;
	q.push(qElem);
	printQueue(q);

	cout << "Input key for removal:\n";
	cin >> s;
	queueFindS(q, s);
	queueRemoveS(q, s);
	printQueue(q);

	cout << "Increment sort:" << endl;
	sortQueueIncrement(q);
	printQueue(q);
	cout << "Decrement sort:" << endl;
	sortQueueDecrement(q);
	printQueue(q);

	cout << "Add min+max to all values:" << endl;
	queueMinMaxAdder(q);
	printQueue(q);
	sumMinMax.setKop(0); sumMinMax.setRub(0);

	cout << "Task 3 - Associtative containter." << endl;
	cout << "Input container size: "; cin >> n;
	map<int, Money> m;
	m = makeMap(n);
	printMap(m);

	n = mapMinElemKey(m);
	cout << "Minimal element: " << m[n] << endl;
	m.insert(make_pair(m.size(), m[n]));
	printMap(m);

	cout << "Input index for removal: \n"; cin >> n;	
	if ((n < m.size()) && (n >= 0)) { cout << "Element: " << m[n] << " found." << endl; }
	else { cout << "Error: element not found." << endl; }
	delOneElemMap(m, n);
	printMap(m);

	cout << "Increment sort:" << endl;
	sortMapIncrement(m);
	printMap(m);
	cout << "Decrement sort:" << endl;
	sortMapDecrement(m);
	printMap(m);

	cout << "Add min+max to all values:" << endl;
	n = mapMinElemKey(m);
	sumMinMax = sumMinMax + m[n];
	n = mapMaxElemKey(m);
	sumMinMax = sumMinMax + m[n];
	minMaxAddToMap(m);
	printMap(m);
	sumMinMax.setKop(0); sumMinMax.setRub(0);

	return 0;
}
/*Test:

Task 1 - Vector.
Input vector size: 2
Input rub: 1
Input kop: 10
Input rub: 2
Input kop: 20
1,10
2,20

Min element: 1,10
1,10
2,20
1,10

Input key for removal:
Input rub: 2
Input kop: 20
Element 2,20 found.
1,10
1,10

Increment sort:
1,10
1,10

Decrememt sort:
1,10
1,10

Add min+max to all values:
3,30
3,30

Task 2 - Queue.
Input queue size: 3
Input rub: 1
Input kop: 10
Input rub: 2
Input kop: 20
Input rub: 3
Input kop: 30
1,10
2,20
3,30

Minimal element: 1,10
1,10
2,20
3,30
1,10

Input key for removal:
Input rub: 2
Input kop: 20
Element 2,20 found.
1,10
3,30
1,10

Increment sort:
1,10
1,10
3,30

Decrement sort:
3,30
1,10
1,10

Add min+max to all values:
7,70
5,50
5,50

Task 3 - Associtative containter.
Input container size: 3
Input rub: 1
Input kop: 10
Input rub: 2
Input kop: 20
Input rub: 3
Input kop: 30
0 - 1,10
1 - 2,20
2 - 3,30
Minimal element: 1,10
0 - 1,10
1 - 2,20
2 - 3,30
3 - 1,10
Input index for removal:
2
Element: 3,30 found.
0 - 1,10
1 - 2,20
2 - 1,10
Increment sort:
0 - 1,10
1 - 1,10
2 - 2,20
Decrement sort:
0 - 2,20
1 - 1,10
2 - 1,10
Add min+max to all values:
0 - 5,50
1 - 4,40
2 - 4,40
*/