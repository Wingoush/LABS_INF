#include <iostream>
#include <string>

int main() {
    std::setlocale(LC_ALL, "Russian");

    int countC = 0;
    int countV = 0;
    std::string st;

    std::cout << "������� ������: " << std::endl;
    std::cin >> st;

    const char *pt = st.c_str();

    for (int i = 0; i < st.length(); i++) {
        char tmp = tolower(*pt);
        
        std::cout << tmp << std::endl;

        if (tmp == L'a' || tmp == L'�' || tmp == L'i' || tmp == L'o' || tmp == L'u' || tmp == L'y') {
            countV++;
        } else { 
            countC++; 
        }
        
        pt++;
    }

    std::cout << "���������� �������:  " << countV << std::endl;
    std::cout << "���������� ���������:  " << countC << std::endl;
    
    return 0;
}