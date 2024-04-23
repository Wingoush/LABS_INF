Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 9, Вариант 23 - Строковый ввод-вывод

Задание:

1) Скопировать из файла F1 в файл F2 все строки, в которых
   содержится только одно слово.
2) Определить номер слова, в котором больше всего
   согласных букв.

# Блок-Схема
![9](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/dd7c529f-0b57-4947-abd6-f69d41c9d143)


# Код

```cpp
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
```

# Тест

## F1

```cpp
One
Two
Ehehe
und an aCara
Ghilly
Alpha
Bravo
Charlie
Tan Go
Wo Xing Shi
```

## F2

```cpp
One
Two
Ehehe
Ghilly
Alpha
Bravo
Charlie
```

## Консоль

```cpp
Number of word (max consolants): 4
```
