#include <iostream>

using namespace std;

int func() {
    int a;
    cin >> a;
    if (a == 0) {
        return 0;
    }
    func();
    cout  << a << '\n';
    return 0;
}

int main() {
    func();
}
