#include <iostream>

using namespace std;

int func() {
    int a, b;
    cin >> a >> b;
    if (a == 0 || b == 0) {
        return 0;
    }
    cout  << a << '\n';
    func();
    return 0;
}

int main() {
    func();
}
