#include <iostream>
#include <string>
using namespace std;

struct STUDENT{
    string NAME_1, NAME_2;
    int GROUP;
    int SES[5] = {0};
};

void data_in(STUDENT STUD1[]) {
    for (int i = 0; i < 10; i++) {
        cin >> STUD1[i].NAME_1;
        cin >> STUD1[i].NAME_2;
        cin >> STUD1[i].GROUP;
        for (int j = 0; j < 5; j++) {
            cin >> STUD1[i].SES[j];
        }
    }
}

void swap(STUDENT STUD[10], int i, int j) {
    STUDENT tmp;
    tmp = STUD[i];
    STUD[i] = STUD[j];
    STUD[j] = tmp;
}


void sort(STUDENT STUD1[10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++)
            if (STUD1[i].NAME_1.compare(STUD1[j].NAME_1) == 1) {
                swap(STUD1, i, j);
            }
    }
    return;
}

void control(STUDENT STUD1[10]) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (STUD1[i].SES[j] == 2) {
                cout << STUD1[i].NAME_1 << " " << STUD1[i].NAME_2 << STUD1[i].GROUP<<'\n';
                count++;
                break;
            }
        }
    }
    if (count == 0) {
        cout << "No 2";
    }
    return;
}

void data_out(STUDENT STUD1[10]) {
    for (int i = 0; i < 10; i++) {
        cout << STUD1[i].NAME_1 << " " << STUD1[i].NAME_2 << '\n';
    }
}

int main(){
    STUDENT STUD1[10];
    data_in(STUD1);
    sort(STUD1);
    control(STUD1);
    data_out(STUD1);
}
