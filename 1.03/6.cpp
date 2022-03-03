#include <iostream>

using namespace std;

int data_in() {
    int n;
    cin >> n;
    return n;
}
int female(int n);
int male(int n);

int female(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n - male(female(n - 1));
    }
}

int male(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n - female(male(n - 1));
    }
}

void data_out(int n) {
    cout << female(n) << '\n' << male(n);
}

int main() {
    data_out(data_in());
}
