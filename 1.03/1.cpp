#include <iostream>

using namespace std;

int func() {
    int a;
    cin >> a;
    if (a % 2 == 1) {
        cout << a<< '\n';
    }
    if (a == 0) {
        return 0;
    }
    func();
}

int main() {
    func();
}
