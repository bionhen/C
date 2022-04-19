#include <iostream>
using namespace std;

int data_in(int*& arr) {
    int n = 0;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return n;
}

int min(int a, int b) {
    if (b > a) {
        return a;
    }
    else {
        return b;
    }
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    else {
        return a;
    }
}

int search(int*& arr, int k) {
    int energy;
    if (k == 1){
        return 0;
    }
    if (k == 2) {
        energy = abs(arr[k-1] - arr[k - 2]);
        return energy;
    }
    energy = min(search(arr, k - 1) + abs(arr[k-1] - arr[k - 2]), search(arr, k - 2) + 3 * abs(arr[k-1] - arr[k - 3]));
    return energy;
}

int main() {
    int* arr = nullptr;
    int n = data_in(arr);
    cout << search(arr, n);
    delete[] arr;
}