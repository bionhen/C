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

int search(int*& arr, int k, int*& memoization) {
    int energy;
    if (k == 1){
        memoization[0] = 0;
        return 0;
    }
    if (k == 2) {
        energy = abs(arr[k-1] - arr[k - 2]);
        memoization[1] = energy;
        return energy;
    }
    int energy_1, energy_2;
    if (memoization[k - 2] != -1) {
        energy_1 = memoization[k - 2];
    }
    else {
        energy_1 = search(arr, k - 1, memoization);
    }
    if (memoization[k - 3] != -1) {
        energy_2 = memoization[k - 3];
    }
    else {
        energy_2 = search(arr, k - 2, memoization);
    }
    energy = min(energy_1 + abs(arr[k-1] - arr[k - 2]), energy_2 + 3 * abs(arr[k-1] - arr[k - 3]));
    memoization[k - 1] = energy;
    return energy;
}

int main() {
    int* arr = nullptr;
    int n = data_in(arr);
    int* memoization = new int[n];
    for (int i = 0; i < n; i++) {
        memoization[i] = -1;
    }
    cout << search(arr, n, memoization);
    delete[] arr;
    delete[] memoization;
}