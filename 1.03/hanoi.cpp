#include <iostream>

using namespace std;
int hanoi(int n, char from, char to, char use) {
    if (n == 1) {
        cout << from << "->" << to << '\n';
        return n;
    }
    hanoi(n - 1, from, use, to);
    cout << from << "->" << to << '\n';
    hanoi(n - 1, use, to, from);
}

int main() {
    hanoi(3, 1, 3, 2);
}
