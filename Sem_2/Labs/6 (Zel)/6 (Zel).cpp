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
		Тестовые данные

		Тест 1:
		Входные данные: karrak
		Выходные данные: Word - palindrome

		Тест 2:
		Входные данные: karak
		Выходные данные: Word - palindrome

		Тест 3:
		Входные данные: karrk
		Выходные данные: Word - not palindrome
	*/