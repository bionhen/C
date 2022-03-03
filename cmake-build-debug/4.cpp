#include <iostream>

using namespace std;

void func(int& max, int& n) {
    int a;
    cin >> a;
    if (a == 0) {
        cout << max << " " << n;
        return;
    }
    if (a > max) {
        max = a;
        n = 0;
    }
    if (a == max) {
        n++;
    }
    func(max, n);
}

int main() {
    int max = 0, n = 0;
    func(max, n);
}

