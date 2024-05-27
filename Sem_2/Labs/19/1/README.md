Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 19.1 - Классы и объекты. Инкапсуляция. Вариант 13.

1. Реализовать определение нового класса

2. Реализовать тип данных структурой pair

3. Структура pair: int - целая часть числа, float - дробная часть числа

4. Изменние данных через функции класса

# UML - Диаграмма

# Код

### operations.h

```cpp
#pragma once

class Calculations {
private:
	int integerPart;
	float floatPart;
public:
	void Init() {
		integerPart = 0;
		floatPart = 0.0;
	};
	void SetNumber(int n) {
		integerPart = n;
	};
	void SetNumber(float n) {
		floatPart = n;
	};
	double Multiply(double k) {
		return ((double)integerPart + (double)(floatPart - (int)floatPart)) * k;
	};
};

```

### main.cpp

```cpp
#include "header.h"
#include <iostream>

using namespace std;

int main() {
	Calculations mult;
	mult.Init();

	int a;
	float b;
	double k;

	cout << "Type in integer part: ";
	cin >> a; mult.SetNumber(a);

	cout << "Type in float part: ";
	cin >> b; mult.SetNumber(b);

	cout << "Type in multiplier: ";
	cin >> k;
	cout << "Result: " << mult.Multiply(k);

	return 0;
}
/*Tests

Test 1:
Type in integer part: 13
Type in float part: 60.32
Type in multiplier: 2
Result: 26.64

Test 2:
Type in integer part: 100
Type in float part: 0.4
Type in multiplier: 0.5
Result: 50.2

Test 3:
Type in integer part: 66
Type in float part: 12512.0
Type in multiplier: 0.3
Result: 19.8
*/
```

# Тесты

```cpp
Type in integer part: 13
Type in float part: 60.32
Type in multiplier: 2
Result: 26.64
```

```cpp
Type in integer part: 100
Type in float part: 0.4
Type in multiplier: 0.5
Result: 50.2
```

```cpp

```
