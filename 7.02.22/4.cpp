#include <iostream>
using namespace std;
int max1(int p1, int p2) {
    if (p1 < p2) {
        return p2;
    }
    else { return p1; }
}
int max2(int p1, int m2, int m1) {
    if (max(p1, m1)!=m1) {
        return m1;
    }
    else { return m2; }
}
int min1(int p1, int p2) {
    if (p1 > p2) {
        return p2;
    }
    else { return p1; }
}
int min2(int p1, int m2, int m1) {
    if (min(p1, m1) != m1) {
        return m1;
    }
    else { return m2; }
}

int main() {
    int N, i = 1, p = 0, maxim1 = 0, maxim2 = 0, minim1 = 0, minim2 = 0;
    cin >> N;   
    while (i <= N) {
        cin >> p;
        if (i == 1) { maxim1 = p; maxim2 = p; minim1 = p; minim2 = p;}
        maxim2 = max2(p, maxim2, maxim1);
        maxim1 = max1(maxim1, p);
        minim2 = min2(p, minim2, minim1);
        minim1 = min1(minim1, p);
        i += 1;
    }
    int summax = maxim1 + maxim2;
    int summin = minim1 + minim2;
    cout << summax << endl;
    cout << summin << endl;
    return 0;
}
