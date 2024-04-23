Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 17 - Поиск (Кнут-Моррис-Пратт и Бойер-Мур)

# Блок-Схема

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-23-14-07-42-KMP.png)

# Код

```cpp
#include <iostream>
#include <string>

using namespace std;

const int CHAR_TABLE_SIZE = 256;

int* calcPrefixFunc(string key, int size) {
    int* lps = new int[size];
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < size) {
        if (key[i] == key[len]) {
            lps[i] = len;
            len++;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void knuthMorrisPrattSearch(string str, string key) {
    int str_size = str.size();
    int key_size = key.size();
    int* lps = calcPrefixFunc(key, key_size);
    int str_indx = 0;
    int key_indx = 0;

    while ((str_size - str_indx) >= (key_size - key_indx)) {
        if (key[key_indx] == str[str_indx]) {
            key_indx++;
            str_indx++;
        }

        if (key_indx == key_size) {
            cout << "Pattern start index: " << str_indx - key_indx << endl;
            key_indx = lps[key_indx - 1];
        }
        else if (str_indx < str_size && key[key_indx] != str[str_indx]) {
            if (key_indx != 0) {
                key_indx = lps[key_indx - 1];
            }
            else {
                str_indx++;
            }
        }
    }
}

void charTableCalculate(string str, int size, int charTable[CHAR_TABLE_SIZE]) {
    for (int i = 0; i < CHAR_TABLE_SIZE; i++) {
        charTable[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        charTable[(int)str[i]] = i;
    }
}

void boyerMooreSearch(string str, string key) {
    int str_size = str.size();
    int key_size = key.size();

    int shift_table[CHAR_TABLE_SIZE];

    charTableCalculate(str, key_size, shift_table);

    int shift = 0;

    while (shift <= (str_size - key_size)) {
        int j = key_size - 1;

        while (j >= 0 && key[j] == str[shift + j]) { j--; }

        if (j < 0) {
            cout << "Pattern start index: " << shift << endl;

            if (shift + key_size < str_size) {
                shift += key_size - shift_table[(int)str[shift + key_size]];
            }
            else { shift++; }
        }
        else {
            shift += max(1, j - shift_table[(int)str[shift + j]]);
        }
    }
}

int main() {
    string str, key;
    cout << "Type in string and search key: \n";
    cin >> str >> key;

    cout << "\n"
        "1 - Knuth-Morris-Pratt (KMP) search\n"
        "2 - Booyer-Moore search\n"
        "Select search method: ";
    int n;
    cin >> n;

    cout << endl;

    switch (n) {
    case 1:
        knuthMorrisPrattSearch(str, key);
        break;
    case 2:
        boyerMooreSearch(str, key);
        break;
    default:
        cout << "Invalid search method.";
    }

    return 0;
}
/*
Tests

Test 1:
Type in string and search key:
abra_abra
abra

1 - Knuth-Morris-Pratt (KMP) search
2 - Booyer-Moore search
Select search method: 1

Pattern start index: 0
Pattern start index: 5


Test 2:
Type in string and search key:
abra_abrac_abra
abr

1 - Knuth-Morris-Pratt (KMP) search
2 - Booyer-Moore search
Select search method: 2

Pattern start index: 0
Pattern start index: 5
Pattern start index: 11


Test 3:
Type in string and search key:
abrabrabrabr
abr

1 - Knuth-Morris-Pratt (KMP) search
2 - Booyer-Moore search
Select search method: 1

Pattern start index: 0
Pattern start index: 3
Pattern start index: 6
Pattern start index: 9
*/
```

# Тесты

## Тест 1

```cpp
Type in string and search key:
abra_abra
abra

1 - Knuth-Morris-Pratt (KMP) search
2 - Booyer-Moore search
Select search method: 1

Pattern start index: 0
Pattern start index: 5
```

## Тест 2

```cpp
Type in string and search key:
abra_abrac_abra
abr

1 - Knuth-Morris-Pratt (KMP) search
2 - Booyer-Moore search
Select search method: 2

Pattern start index: 0
Pattern start index: 5
Pattern start index: 11
```

## Тест 3

```cpp
Type array size: 10
Array: [39] [19] [51] [50] [34] [11] [48] [60] [55] [16]
Sorted array: [11] [16] [19] [34] [39] [48] [50] [51] [55] [60]
```
