#include <iostream>
using namespace std;

int data_in(int* &arr, int n) {
    int P = 0;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> P;
    return P;
}

int choose(int*& arr, int P, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (P < arr[i]) {
            continue;
        }
        else {
            cout << P / arr[i] << "x" << arr[i] << '\n';
            P = P - (P / arr[i])*arr[i];
        }
    }
    return 0;
}

int main() {
    int* arr = nullptr;
    int n = 0;
    cin >> n;
    int P = data_in(arr , n);
    choose(arr, P, n);
}
