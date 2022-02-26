#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int div) {
    int a = rand() % div;
    return a;
}

int creation(int area[], int n, int a, int sign) {
    int count = 0;
    if (sign < 3) { // создание массива для двумерного случая
        while (count < n) {
            int b = random(a * a);
            if (area[b] == 0) {
                area[b] = 1;
                count++;
            }
        }
    }
    else { // создание массива для одномерного случая
        while (count < n) {
            int b = random(a);
            if (area[b] == 0) {
                area[b] = 1;
                count++;
            }
        }
    }
    return 0;
}

int move(int area[], int a, int sign) {
    int bin[3600] = { 0 };
    for (int i = 0; i < 3600; i++) {
        bin[i] = area[i];
    }
    if (sign < 3) { // движение для двумерного случая
        for (int i = 0; i < a * a; i++) {
            if (area[i] > 0) {
                if (i % a == 0 || i < a || i > a * a - a - 1 || i % a == a - 1)
                    area[i] = 0;
            }
        }
        for (int i = 0; i < a * a; i++) {
            if (bin[i] > 0) {
                while (bin[i] > 0) {
                    int step = random(4);
                    if (step == 0) {
                        area[i + 1]++;
                        area[i]--;
                        bin[i]--;
                    }
                    if (step == 1 && area[i + a] == 0) {
                        area[i + a]++;
                        area[i]--;
                        bin[i]--;
                    }
                    if (step == 2 && area[i - a] == 0) {
                        area[i - a]++;
                        area[i]--;
                        bin[i]--;
                    }
                    if (step == 3 && area[i - 1] == 0) {
                        area[i - 1]++;
                        area[i]--;
                        bin[i]--;
                    }
                }
            }
        }
        for (int i = 0; i < a * a; i++) {
            if (i % a == 0 || i < a || i > a * a - a - 1 || i % a == a - 1) {
                area[i] = 0;
            }
        }
    }
    else { // движение для одномерного случая
        for (int i = 0; i < a; i++) {
            if (area[i] == 1) {
                if (i == 0 || i == a - 1)
                    area[i] = 0;
            }
        }
        for (int i = 0; i < a; i++) {
            if (bin[i] == 1) {
                while (bin[i]) {
                    int step = random(4);
                    if (step == 0) {
                        area[i + 1]++;
                        area[i]--;
                        bin[i]--;
                    }
                    if (step == 3) {
                        area[i - 1]++;
                        area[i]--;
                        bin[i]--;
                    }
                }
            }
        }
        for (int i = 0; i < a; i++) {
            if (i == 0 || i == a - 1){
                area[i] = 0;
            }
        }
    }
    return 0;
}

int count(int arr[], int a, int sign) {
    int c = 0;
    if (sign < 3) { // подсчет количества движущихся элементов для двумерного случая
        for (int i = 0; i < a * a; i++) {
            if (arr[i] > 0) {
                c++;
            }
        }
    }
    else { // подсчет количества движущихся элементов для одномерного случая
        for (int i = 0; i < a; i++) {
            if (arr[i] > 0) {
                c++;
            }
        }
    }
    return c;
}

int process(int area[], int a, int sign) {
    int i = 0;
    int c = count(area, a, sign);
    while (c != 0) {
        move(area, a, sign);
        c = count(area, a, sign);
        i++;
    }
    return i;
}

int one_a_vs_time(int sign) {
    const int N_of_average = 10000;
    int a = 0, i = 0, sum = 0;
    double mean = 0;
    for (a = 2; a < 60; a++) {
        sum = 0;
        for (int j = 0; j < N_of_average; j++) {
            int area[3600] = { 0 };
            creation(area, 1, a, sign);
            i = process(area, a, sign);
            sum += i;
        }
        mean = sum * 1.0 / N_of_average;
        cout << mean << " " << '\n';
    }
    return 0;
}

int two_alpha_dislocation_vs_time(int sign, int n) {
    const int N_of_average = 10000;
    int sum = 0, time = 0, ar = 0;
    double mean = 0;
    if (sign < 3) { ar = n * n; }
    else {
        ar = n;
    }
    for (int k = 1; k < ar; k++) {
        sum = 0;
        for (int j = 0; j < N_of_average; j++) {
            int area[3600] = { 0 };
            creation(area, k, n, sign);
            time = process(area, n, sign);
            sum += time;
        }
        mean = sum * 1.0 / N_of_average;
        cout << mean << " " << '\n';
    }
    return 0;
}

int main() {
    int number = 0, n = 0;
    srand(static_cast<unsigned int>(time(0)));
    cin >> number;
    if (number == 1) {
        one_a_vs_time(number);
    }
    if (number == 2) {
        cin >> n;
        two_alpha_dislocation_vs_time(number, n);
    }
    if (number == 3) {
        one_a_vs_time(number);
    }
    if (number == 4) {
        cin >> n;
        two_alpha_dislocation_vs_time(number, n);
    }
    return 0;
}