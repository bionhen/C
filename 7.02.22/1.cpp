#include <iostream>
using namespace std;
int max2(int p1, int p2) {
    if (p1 % 2 == 0 && p2 % 2 == 0) {
        if (p1 >= p2) {
            return p1;
        }
        else {
            return p2;
        }
    }
    else {
        return p2;
    }
    }
int main() {
    int max = -2147483648;
    int p=1;
    while (p != 0) {
        cin >> p;
        max = max2(p, max);
    }
    cout << max;
    return 0;
}