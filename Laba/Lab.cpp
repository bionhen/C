﻿#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int div) {
    int a = rand() % div;
    return a;
}

int creation(int area[], int n, int a) {
    int count = 0;
    while(count < n) {
        int b = random(a * a);
        if (area[b] == 0) {
            area[b] = 1;
            count++;
        }
    }
    return 0;
}

int move(int area[], int a) {
    for (int i = 0; i < a * a; i++) {
        if (area[i] == 1) {
            if (i % a == 0 || i < a || i > a * a - a - 1 || i % a == a - 1)
                area[i] = 3;
            else { area[i] = 1; }
        }
    }
    for (int i = 0; i < a * a; i++) {
        if (area[i] == 1) {
            area[i] = 0;
            int step = random(4);
            if (step == 0 && area[i + 1] == 0) {
                area[i + 1] = 2;
            }
            if (step == 1 && area[i + a] == 0) {
                area[i + a] = 2;
            }
            if (step == 2 && area[i - a] == 0) {
                area[i - a] = 2;
            }
            if (step == 3 && area[i - 1] == 0) {
                area[i - 1] = 2;
            }
        }
    }
    for (int i = 0; i < a * a; i++) {
        if (area[i] == 2) {
            if (i % a == 0 || i < a || i > a * a - a - 1 || i % a == a - 1)
                area[i] = 3;
            else { area[i] = 1; }
        }
    }
    for (int i = 0; i < a * a; i++) {
        if (area[i] == 1) {
            if (area[i + 1] != 0 || area[i - 1] != 0 || area[i + a] != 0 || area[i - a] != 0) {
                area[i] = 3;
            }
        }
    }
    return 0;
}

int count(int area[], int a) {
    int c = 0;
    for (int i = 0; i < a * a; i++) {
        if (area[i] == 1) {
            c++;
        }
    }
    return c;
}

int process(int area[], int a) {
    int i = 0;
    int c = count(area, a);
    while (c != 0) {
        move(area, a);
        //for (int i = 0; i < a * a; i++) {
            //cout << area[i];
            //if (i % a == a - 1) { cout << '\n'; }
        //}
        //cout << '\n';
        c = count(area, a);
        i++;
    }
    return i;
}
int one_a_vs_time() {
    int a = 0, c = 0, i = 0, sum = 0;
    float mean = 0;
    for (a = 2; a < 60; a++) {
        sum = 0;
        for (int j = 0; j < 50000; j++) {
            int area[3600] = { 0 };
            creation(area, 1, a);
            i = process(area, a);
            sum += i;
        }
        mean = sum / 50000.0;
        cout << mean << " " << '\n';
    }
    return 0;
}


int main() {
    srand(static_cast<unsigned int>(time(0)));
    one_a_vs_time();
    return 0;
}