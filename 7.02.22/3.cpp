#include <iostream>
using namespace std;
int check(int p1, int p2, int k) {
    if (p1 < p2) {
        k += 1;
    }
    return k;
}

int main() {
    int p = 1, checked = 0, k = 0;
    while (p != 0) {
        cin >> p;
        k = check(checked, p, k);
        checked = p;
    }
    k -= 1;
    cout << k << endl;
    return 0;
}
