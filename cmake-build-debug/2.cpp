#include <iostream>

using namespace std;

int func() {
    int a, n = 1;
    cin >> a;
    n++;
    if (a == 0) {
        return 0;
    }
    if (n == 1) {
        cout <<'\n'<< a;
    }
    func();
}

int main() {
    func();
}
