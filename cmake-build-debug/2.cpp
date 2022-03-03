#include <iostream>

using namespace std;

int func() {
    int a, n = 0;
    cin >> a;
    n++;
    if (a == 0) {
        return 0;
    }
    if (n % 2 == 1) {
        cout << '\n' << a;
    }
    func();
    return 0;
}

int main() {
    func();
}
