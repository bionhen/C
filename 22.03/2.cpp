#include <iostream>

using namespace std;

void func(int N) {
    int* arr = new int[N];
    int s = 0;
    for (int idx = 0; idx < N; idx++) {
        cin >> s;
        arr[idx] = s;
    }
    for (int idx = N - 1; idx >= 0; idx--) {
        if (idx % 2 == 0) {
            cout << arr[idx] << " ";
        }
    }
    for (int idx = N - 1; idx >= 0; idx--) {
        if (idx % 2 == 1) {
            cout << arr[idx] << " ";
        }
    }
    delete[] arr;
}


int main() {
    int N = 0;
    cin >> N;
    func(N);
    return 0;
}

