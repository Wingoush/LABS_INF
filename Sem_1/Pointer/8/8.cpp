#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU");

    int countA, counta, countothers, total;
    countA = counta = countothers = total = 0;
    string st;
    char A, a;

    cin >> st;
    cin >> A;
    cin >> a;

    const char *pt = st.c_str();

    for (int i = 0; i < st.length(); i++) {
        if (*pt == A) { 
            countA++; 
        } else if (*pt == a) { 
            counta++; 
        } else {
            countothers++;
        }
        
        pt++;
    }
    
    total = countA + counta + countothers;
    
    cout << "Количество " << A << " = " << countA << endl << "Количество " << a << " = " << counta << endl << "Количество других символов = " << countothers << endl << "Общее количество символов = " << total;
    
    return 0;
}