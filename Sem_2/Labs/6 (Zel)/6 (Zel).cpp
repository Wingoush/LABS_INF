#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	char s[255];
	bool palindrome = true;

	gets_s(s);

	for (int a = 0; a < strlen(s); a++) {
		if (s[a] != s[strlen(s) - 1 - a]) { palindrome = false; }
	}

	if (palindrome) {
		cout << "Word - palindrome" << endl;
	} else {
		cout << "Word - not palindrome" << endl;
	}

	return 0;
}
	/*
		�������� ������

		���� 1:
		������� ������: karrak
		�������� ������: Word - palindrome

		���� 2:
		������� ������: karak
		�������� ������: Word - palindrome

		���� 3:
		������� ������: karrk
		�������� ������: Word - not palindrome
	*/