Романов Артём Алексеевич (ИВТ-23-1Б)



# Задание

Задание: Вывести способы расстановки 8 ферзей так, чтобы ни один из них не был под ударом других ферзей.



# Блок-схема программы

![2024-03-15-21-49-01-image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/abf2e874-f753-40dd-99e6-c5da41424b92)

![2024-03-15-21-49-17-image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/c64e17f1-c4c4-4576-be1d-8d2eebdc111d)

![2024-03-15-21-49-51-image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/af2dd65a-c9fb-46ee-ae51-4a7d259d67d4)

![2024-03-15-21-50-25-image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/489b51da-2e20-4d07-a1d8-37f62c33f729)

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

![2024-03-15-21-51-31-image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/0076ca3a-8c51-4f9b-b3f9-17a111bbf9a7)

![2024-03-15-21-51-55-image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/47bb1d06-9d07-41a3-8e66-add898930801)

![2024-03-15-21-52-36-image](https://github.com/Wingoush/LABS_PSTU_2023/assets/147124195/30c70117-3de7-499c-a307-54039691f233)
