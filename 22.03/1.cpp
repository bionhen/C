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
    for (int idx = 0; idx < N; idx++) {
        if (arr[idx] < 0) {
            for (int i = idx + 1; i < d + idx; i++) {
                if (arr[i] == -arr[idx]) {
                    d = i - idx ;
                    break;
                }
            }
        }
    }
    if (arr[0] != arr[N - 1] && d == N) {
        d = 0;
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

