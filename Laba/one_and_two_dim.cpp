#include <iostream>
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
        }
    }
    for (int i = 0; i < a * a; i++) {
        if (area[i] == 1) {
            int step = random(4);
            if (step == 0 && area[i + 1] == 0) {
                area[i + 1] = 2;
                area[i] = 0;
            }
            if (step == 1 && area[i + a] == 0) {
                area[i + a] = 2;
                area[i] = 0;
            }
            if (step == 2 && area[i - a] == 0) {
                area[i - a] = 2;
                area[i] = 0;
            }
            if (step == 3 && area[i - 1] == 0) {
                area[i - 1] = 2;
                area[i] = 0;
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

int two_alpha_dislocation_vs_time() {
    int c = 0, n = 0, sum = 0, time = 0;
    float mean = 0;
    for (n = 1; n < 400; n++) {
        sum = 0;
        for (int j = 0; j < 10000; j++) {
            int area[3600] = { 0 };
            creation(area, n, 20);
            time = process(area, 20);
            sum += time;
        }
        mean = sum / 10000.0;
        cout << mean << " " << '\n';
    }
    return 0;
}

int creation_one_dim(int area[], int n, int a) {
    int count = 0;
    while (count < n) {
        int b = random(a);
        if (area[b] == 0) {
            area[b] = 1;
            count++;
        }
    }
    return 0;
}

int move_one_dim(int area[], int a) {
    for (int i = 0; i < a * a; i++) {
        if (area[i] == 1) {
            if (i == 0 || i == a - 1)
                area[i] = 3;
        }
    }
    for (int i = 0; i < a; i++) {
        if (area[i] == 1) {
            int step = random(4);
            if (step == 0 && area[i + 1] == 0) {
                area[i + 1] = 2;
                area[i] = 0;
            }
            if (step == 3 && area[i - 1] == 0) {
                area[i - 1] = 2;
                area[i] = 0;
            }
        }
    }
    for (int i = 0; i < a; i++) {
        if (area[i] == 2) {
            if (i == 0 || i == a - 1)
                area[i] = 3;
            else { area[i] = 1; }
        }
    }
    for (int i = 0; i < a; i++) {
        if (area[i] == 1) {
            if (area[i + 1] != 0 || area[i - 1] != 0) {
                area[i] = 3;
            }
        }
    }
    return 0;
}

int count_one_dim(int area[], int a) {
    int c = 0;
    for (int i = 0; i < a; i++) {
        if (area[i] == 1) {
            c++;
        }
    }
    return c;
}

int process_one_dim(int area[], int a) {
    int i = 0;
    int c = count(area, a);
    while (c != 0) {
        move_one_dim(area, a);
        c = count_one_dim(area, a);
        i++;
    }
    return i;
}
int one_a_vs_time_one_dim() {
    int a = 0, c = 0, i = 0, sum = 0;
    float mean = 0;
    for (a = 2; a < 200; a++) {
        sum = 0;
        for (int j = 0; j < 50000; j++) {
            int area[3600] = { 0 };
            creation_one_dim(area, 1, a);
            i = process_one_dim(area, a);
            sum += i;
        }
        mean = sum / 50000.0;
        cout << mean << " " << '\n';
    }
    return 0;
}

int two_alpha_dislocation_vs_time_one_dim() {
    int c = 0, n = 0, sum = 0, time = 0;
    float mean = 0;
    for (n = 1; n < 50; n++) {
        sum = 0;
        for (int j = 0; j < 10000; j++) {
            int area[3600] = { 0 };
            creation_one_dim(area, n, 50);
            time = process_one_dim(area, 50);
            sum += time;
        }
        mean = sum / 10000.0;
        cout << mean << " " << '\n';
    }
    return 0;
}

int main() {
    int number = 0;
    srand(static_cast<unsigned int>(time(0)));
    cin >> number;
    if (number == 1) {
        one_a_vs_time();
    }
    if (number == 2) {
        two_alpha_dislocation_vs_time();
    }
    if (number == 3) {
        one_a_vs_time_one_dim();
    }
    if (number == 4) {
        two_alpha_dislocation_vs_time_one_dim();
    }
    return 0;
}