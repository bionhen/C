#include <iostream>

using namespace std;

int data_in() {
    int a;
    cin >> a;
    return a;
}

void func(int& a, int& n) {
    if (a % 10 == 0) {
        cout << n;
        return;
    }
    n = 10 * n + a % 10;
    a = a / 10;

    func(a, n);
}

int main() {
    int n = 0;
    int a = data_in();
    func(a, n);
    return 0;
}