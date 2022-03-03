#include <iostream>

using namespace std;

int func(int & sum, int & n) {
    int a;
    cin >> a;
    if (a == 0) {
        double mean = sum * 1.0 / n;
        cout << mean;
        return 0;
    }
    sum += a;
    n += 1;
    func(sum, n);
}

int main() {
    int sum = 0, n = 0;
    func(sum, n);
}
