#include "Time.h"

Time::Time(void) {
	min = sec = 0;
}

Time::Time(int m, int s) {
	min = m; sec = s;
}

Time::Time(const Time& t) {
	min = t.min;
	sec = t.sec;
}

Time& Time::operator = (const Time& t) {
	min = t.min;
	sec = t.sec;
	return  *this;
}

ostream& operator << (ostream& out, const Time& t) {
	out << t.min << " : " << t.sec;
	return out;
}

istream& operator >> (istream& in, Time& t) {
	cout << "Input minutes: "; in >> t.min;
	cout << "Input seconds: "; in >> t.sec;
	return in;
}

Time Time::operator + (Time k) {
	int t = min * 60 + sec;
	int kt = k.min * 60 + k.sec;
	t += kt;
	Time temp(t / 60, t % 60);

	return temp;
}