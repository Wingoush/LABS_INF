Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 3, Сумма серий

# Блок-Схема
![series](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/56fb0de0-96e8-4c9a-873d-f0bbbcc9606b)

# Код

```cpp
#include <iostream>
#include <cmath>

using namespace std;

double fact(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

double func(int x, int n, int iteration) {
	if (iteration > n) { return 0; }
	double result = (pow((-1), iteration) * (pow((2 * x), (2 * iteration)) / fact(2 * iteration))) + func(x, n, iteration + 1);
	return result;
}

int main() {
	int x, n;
	cout << "Type 'x' and 'n': " << endl;
	cin >> x >> n;
	cout << "Function result: " << func(x, n, 1);

	return 0;
}
/*
Tests:

Test 1:
Type 'x' and 'n':
1
1
Function result: -2


Test 2:
Type 'x' and 'n':
2
7
Function result: -1.86065


Test 3:
Type 'x' and 'n':
6
2
Function result: 792
*/
```

# Тесты

```cpp
Test 1:
Type 'x' and 'n':
1
1
Function result: -2
```

```cpp
Test 2:
Type 'x' and 'n':
2
7
Function result: -1.86065
```

```cpp
Test 3:
Type 'x' and 'n':
6
2
Function result: 792
```
