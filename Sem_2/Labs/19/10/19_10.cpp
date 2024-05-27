#include "Time.h" 
#include <iostream> 
#include <fstream> 
#include <string> 
#include "file_work.h"

using namespace std;

int main(){
    Time p, p1, p2, timeTask;
    int k, c, seconds, k_elements;
    char file_name[30];
    int k1, k2;
    char file_name1[30], file_name2[30];

    do{
        cout << "1. Make file\n";
        cout << "2. Print file\n";
        cout << "3. Delete record from file\n";
        cout << "4. Add record to file\n";
        cout << "5. Change record in file\n";
        cout << "6. Add/Remove seconds to record in file\n";
        cout << "7. Remove target time from file\n";
        cout << "8. Lower target time from file by [1:30]\n";
        cout << "9. Add K times after specific time\n";
        cout << "0. Exit\n";

        cout << "\nInput your choice: ";
        cin >> c;

        switch (c){
            case 1:
                cout << "File name: ";
                cin >> file_name;

                k = make_file(file_name);
                if (k < 0) {cout << "Can't make file";}
                break;
            case 2:
                cout << "File name: ";
                cin >> file_name;

                k = print_file(file_name);
                if (k == 0) { cout << "Empty file\n"; }
                if (k < 0) { cout << "Can't read file\n"; }
                break;
            case 3:
                cout << "File name: ";
                cin >> file_name;
                int numberOfEntry;
                cout << "Number of entry: ";
                cin >> numberOfEntry;

                k = del_file(file_name, numberOfEntry);
                if (k < 0) { cout << "Can't read file"; }
                break;
            case 4:
                cout << "Eile name: ";
                cin >> file_name;
                cout << "Number of entry: ";
                cin >> numberOfEntry;
                cout << "New time: ";
                cin >> p1;

                k = add_file(file_name, numberOfEntry, p1);
                if (k < 0) { cout << "Can't read file"; }
                if (k == 0) { k = add_end(file_name, p1); }
                break;
            case 5:
                cout << "File name: ";
                cin >> file_name;
                cout << "Number of entry: ";
                cin >> numberOfEntry;
                cout << "New time:";
                cin >> p2;

                k = change_file(file_name, numberOfEntry, p2);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 6:
                cout << "File name: ";
                cin >> file_name;
                cout << "Number of entry: ";
                cin >> numberOfEntry;
                cout << "Seconds to add: ";
                cin >> seconds;

                k = change_file(file_name, numberOfEntry, seconds);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 7:
                cout << "File name: ";
                cin >> file_name;
                cout << "Time to delete: " << endl;
                cin >> timeTask;

                k = deleteTarget(file_name, timeTask);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 8:
                cout << "File name: ";
                cin >> file_name;
                cout << "Time to lower: " << endl;
                cin >> timeTask;

                k = changeTarget(file_name, timeTask);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            case 9:
                cout << "File name: ";
                cin >> file_name;
                cout << "Time to add after: " << endl;
                cin >> timeTask;
                cout << "How many elements to add: ";
                cin >> k_elements;

                k = addAfterTarget(file_name, k_elements, timeTask);
                if (k < 0) { cout << "\nCan't read file"; }
                if (k == 0) { cout << "\nNo such record"; }
                break;
            }
    } while (c != 0);

    return 0;
}
/*
Test:

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 1
File name: f1
Amount of entries: 6
min: 10
sec: 30

min: 22
sec: 14

min: 43
sec: 22

min: 12
sec: 33

min: 78
sec: 22

min: 16
sec: 16


1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[10:30]
[22:14]
[43:22]
[12:33]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 7
File name: f1
Time to delete:
min: 12
sec: 33

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[10:30]
[22:14]
[43:22]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 8
File name: f1
Time to lower:
min: 10
sec: 30

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[9:0]
[22:14]
[43:22]
[78:22]
[16:16]

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 9
File name: f1
Time to add after:
min: 22
sec: 14

How many elements to add: 2
min: 13
sec: 13

min: 14
sec: 14

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
6. Add/Remove seconds to record in file
7. Remove target time from file
8. Lower target time from file by [1:30]
9. Add K times after specific time
0. Exit

Input your choice: 2
File name: f1
[9:0]
[22:14]
[13:13]
[14:14]
[43:22]
[78:22]
[16:16]

*/