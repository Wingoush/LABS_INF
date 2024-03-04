Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 2

Задание:

    Заполнить двумернный массив. Все элементы выше главной диагонали равны 0. Все элементы на главной диагонали и ниже заполняются цифрами по порядку.

## Блок-схема программы
![2](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/9ccaa9a1-56de-41ca-ad07-bd1fd28bfcb0)


## Код программы

```cpp
#include <iostream>

using namespace std;

int main() {
    const int arraySize = 5;
    int array[arraySize][arraySize];
    int tmp;

    for (int a = 0; a < arraySize; a++) {
        tmp = 1;

        for (int b = a; b < arraySize; b++) {
            array[b][a] = tmp++;
        }

        for (int c = 0; c < a; c++) {
            array[c][a] = 0;
        }
    }

    for (int a = 0; a < arraySize; a++) {
        for (int b = 0; b < arraySize; b++) {
            cout << array[a][b] << " ";
        }

        cout << endl;
    }

    return 0;
}
    /*
        Тестовые данные:

        Тест 1: arraySize = 8

        1 0 0 0 0 0 0 0
        2 1 0 0 0 0 0 0
        3 2 1 0 0 0 0 0
        4 3 2 1 0 0 0 0
        5 4 3 2 1 0 0 0
        6 5 4 3 2 1 0 0
        7 6 5 4 3 2 1 0
        8 7 6 5 4 3 2 1

        Тест 2: arraySize = 4

        1 0 0 0
        2 1 0 0
        3 2 1 0
        4 3 2 1

        Тест 3: arraySize = 5

        1 0 0 0 0
        2 1 0 0 0
        3 2 1 0 0
        4 3 2 1 0
        5 4 3 2 1
    */
```

## Тесты

Тест 1:

Входные данны: arraySize = 8

Выходные данные:

```cpp
1 0 0 0 0 0 0 0
2 1 0 0 0 0 0 0
3 2 1 0 0 0 0 0
4 3 2 1 0 0 0 0
5 4 3 2 1 0 0 0
6 5 4 3 2 1 0 0
7 6 5 4 3 2 1 0
8 7 6 5 4 3 2 1
```

Тест 2:

Входные данны: arraySize = 4

Выходные данные:

```cpp
1 0 0 0
2 1 0 0
3 2 1 0
4 3 2 1
```

Тест 3:

Входные данны: arraySize = 5

Выходные данные:

```cpp
1 0 0 0 0
2 1 0 0 0
3 2 1 0 0
4 3 2 1 0
5 4 3 2 1
```
