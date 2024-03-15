Романов Артём Алексеевич (ИВТ-23-1Б)



# Задание

Задание: Вывести способы расстановки 8 ферзей так, чтобы ни один из них не был под ударом других ферзей.



# Блок-схема программы

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-03-15-21-49-01-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-03-15-21-49-27-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-03-15-21-49-51-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-03-15-21-50-25-image.png)

# Код программы

```cpp
#include <iostream>

using namespace std;

const int boardSize = 8;
int board[boardSize][boardSize];
int currentValidVariant = 1;

void boardPrint() {
    for (int a = 0; a < boardSize; a++) {
        for (int b = 0; b < boardSize; b++) {
            cout << board[a][b] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n\n";

    return;
}

bool checkAvailability(int a, int b) {
    // Straight
    for (int i = 0; i < a; i++) {
        if (board[i][b] == 1) {
            return false;
        }
    }

    // Main Horizontal
    for (int i = 1; i <= a && b - i >= 0; i++) {
        if (board[a - i][b - i] == 1) {
            return false;
        }
    }

    // Side Horizontal
    for (int i = 1; i <= a && b + i < boardSize; i++) {
        if (board[a - i][b + i] == 1) {
            return false;
        }
    }

    return true;
}

void calculate(int a) {
    if (a == boardSize) {
        cout << "Valid variant: " << currentValidVariant << "\n\n";
        currentValidVariant++;
        boardPrint();
        return;
    }

    for (int i = 0; i < boardSize; i++) {
        if (checkAvailability(a, i)) {
            board[a][i] = 1;
            calculate(a + 1);
            board[a][i] = 0;
        }
    }

    return;
}

int main() {
    calculate(0);
    return 0;
}
```

# Тест

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-03-15-21-51-31-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-03-15-21-51-55-image.png)

![](C:\Users\DELL\AppData\Roaming\marktext\images\2024-03-15-21-52-36-image.png)
