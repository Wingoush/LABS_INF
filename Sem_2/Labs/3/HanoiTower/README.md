Романов Артём Алексеевич (ИВТ-23-1Б)

# Задание

Лабораторная работа № 3 - Ханойская башня



# Блок-Схема

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-21-15-13-48-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-04-21-15-14-14-image.png)

# Код

```cpp
#include <iostream>

using namespace std;

void hanoiTower(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Disk " << n << " moved from " << A << " to " << C << endl;
        return;
    }

    hanoiTower(n - 1, A, C, B);
    cout << "Disk " << n << " moved from " << A << " to " << C << endl;
    hanoiTower(n - 1, B, A, C);
}

int main() {
    int n;
    cout << "Type rings amount: ";
    cin >> n;

    cout << "Rod A - starting rod" << endl;
    cout << "Rod B - middle rod" << endl;
    cout << "Rod C - target rod" << endl;

    if (n == 0) { cout << "No disks."; return 0; }

    hanoiTower(n, 'A', 'B', 'C');

    return 0;
}
/*
Tests:

Test 1:
Type rings amount: 0
Rod A - starting rod
Rod B - middle rod
Rod C - target rod
No disks.


Test 2:
Type rings amount: 1
Rod A - starting rod
Rod B - middle rod
Rod C - target rod
Disk 1 moved from A to C


Test 3:
Type rings amount: 3
Rod A - starting rod
Rod B - middle rod
Rod C - target rod
Disk 1 moved from A to C
Disk 2 moved from A to B
Disk 1 moved from C to B
Disk 3 moved from A to C
Disk 1 moved from B to A
Disk 2 moved from B to C
Disk 1 moved from A to C
*/
```

# Тесты

```cpp
Test 1:
Type rings amount: 0
Rod A - starting rod
Rod B - middle rod
Rod C - target rod
No disks.
```

```cpp
Test 2:
Type rings amount: 1
Rod A - starting rod
Rod B - middle rod
Rod C - target rod
Disk 1 moved from A to C
```

```cpp

```
