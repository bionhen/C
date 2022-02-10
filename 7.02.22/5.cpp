#include <iostream>
using namespace std;
int x, y;

void point(int a1, int b1, int a2, int b2, int c1, int c2) {
    if (a1*b2==a2*b1) {
        cout << "NO";
    }
    else {int x = (c2 * b1 - c1 * b2)/(a1 * b2 - b1 * a2); int y = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1); 
    cout << x << "," << y;
    }
}

int main() {
    int a1, b1, a2, b2, c1, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    point(a1, b1, a2, b2, c1, c2);
    return 0;
}
