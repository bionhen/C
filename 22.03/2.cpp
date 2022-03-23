#include <iostream>

using namespace std;

int func(int N) {
    int* arr = new int[N];

    int s = 0;
    int d = N;
    for (int idx = 0; idx < N; idx++) {
        cin >> s;
        arr[idx] = s;
    }
    for (int idx = N - 1; idx >= 0; idx--) {
        if (arr[idx] % 2 == 1) {
            cout << arr[idx] << " ";
        }
    }
    for (int idx = N - 1; idx >= 0; idx--) {
        if (arr[idx] % 2 == 0) {
            cout << arr[idx] << " ";
        }
    }
    delete[] arr;
    return d;
}


int main() {
    int N = 0;
    cin >> N;
    cout << '\n' << func(N);
    return 0;
}

