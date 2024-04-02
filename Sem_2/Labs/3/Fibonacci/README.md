Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Задание: Вывести числа Фибоначчи.

# Блок-схема программы
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/3cd95179-5ea4-431c-b427-5bb2870b0bf3)
![image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/d51b978f-0fae-4ead-853c-f79ca10a9a2b)

# Код программы

```cpp
#include <iostream>

using namespace std;

int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int amount;
	cout << "Type amount of numbers to display: ";
	cin >> amount;

	cout << "Fibonacci sequence (" << amount << " digits): ";
	for (int i = 0; i < amount; i++) {
		cout << fibonacci(i) << " ";
	}

	return 0;
}
/*
Tests:

Test 1:
Type amount of numbers to display: 0
Fibonacci sequence (0 digits):


Test 2:
Type amount of numbers to display: 1
Fibonacci sequence (1 digits): 0


Test 3:
Type amount of numbers to display: 15
Fibonacci sequence (15 digits): 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
*/
```

# Тест

Тест 1:

```cpp
Type amount of numbers to display: 0
Fibonacci sequence (0 digits):
```

Тест 2:

```cpp
Type amount of numbers to display: 1
Fibonacci sequence (1 digits): 0
```

Тест 3:

```cpp
Type amount of numbers to display: 15
Fibonacci sequence (15 digits): 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
```
