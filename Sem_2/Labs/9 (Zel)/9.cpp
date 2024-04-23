#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numMaxCons = 1;
int num = 1;
int maxCons = 0;
string vowels = "aeiouyAEIOUY";

int main() {
	string s;

	ifstream in;
	in.open("F1");

	ofstream out;
	out.open("F2");

	while (getline(in, s)) {
		int cons = 0;
		bool check = true;
		for (char i : s) {
			if (i == ' ') {
				check = false;
				num--;
				break;
			}

			bool vowel = false;

			for (int j = 0; j < vowels.length(); j++) {
				if (i == vowels[j]) { vowel = true; break; }
			}

			if (!vowel) { cons++; }
		}

		if (check) {
			if (cons > maxCons) {
				numMaxCons = num;
				maxCons = cons;
			}
			out << s << endl;
		}
		num++;
	}

	in.close();
	out.close();

	cout << "Number of word (max consolants): " << numMaxCons << endl;

	return 0;
}