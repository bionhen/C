#include <iostream>
#include <string>
using namespace std;

struct STUDENT{
    string NAME_1, NAME_2;
    int AGE;
    int CLASS;
    int N;
    int *SES;
};

void data_in(STUDENT STUD1[5]) {
    for (int i = 0; i < 5; i++) {
        cin >> STUD1[i].NAME_1;
        cin >> STUD1[i].NAME_2;
        cin >> STUD1[i].AGE;
        cin >> STUD1[i].CLASS;
        cin >> STUD1[i].N;
        STUD1[i].SES = new int [STUD1[i].N];
        for(int j = 0; j < STUD1[i].N; j++){
            cin >> STUD1[i].SES[j];
        }
    }
    return;
}

void add_mark(STUDENT& s, int mark) {
    double sum = 0;
    int N = 0;
    const double check = 4.5;
    double d = 0.0;
    for (int i = 0; i < s.N; i++) {
        sum += s.SES[i];
    }
    if (sum / s.N == 4.5){
        return;
    }
    while (d < check) {
        N++;
        d = (sum + N * mark) / (N + s.N);
    }
    int* SES_new = new int[s.N + N];
    for (int i = 0; i < s.N; i++) {
        SES_new[i] = s.SES[i];
    }
    for (int i = s.N; i < s.N + N; i++) {
        SES_new[i] = 5;
    }
    delete[] s.SES;
    s.N += N;
    s.SES = SES_new;
    return;
}

void improve_marks(STUDENT STUD1[5]) {
    for (int i = 0; i < 5; i++) {
        add_mark(STUD1[i], 5);
    }
    return;
}

void data_out(STUDENT STUD1[5]) {
    for (int i = 0; i < 5; i++) {
        cout << STUD1[i].NAME_1 << " " << STUD1[i].NAME_2 << " ";
        cout << STUD1[i].AGE << " "<<STUD1[i].CLASS << " "<<STUD1[i].N<< '\n';
        for (int j = 0; j < STUD1[i].N; j++) {
            cout << STUD1[i].SES[j]<< " ";
        }
        delete[] STUD1[i].SES;
        cout << '\n';
    }
    return;
}

int main(){
    STUDENT STUD1[5];
    data_in(STUD1);
    improve_marks(STUD1);
    data_out(STUD1);
    return 0;
}

