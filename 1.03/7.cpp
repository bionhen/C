#include <iostream>

using namespace std;

int data_in(int arr[]) {
    int n = 0, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        arr[i] = m;
    }
    return n;
}

void data_out(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";
    }
}

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void iteration(int arr[], int n) {
    if ((n - 1) % 2 != 0) {
        if (arr[n - 1]>arr[(n - 1) / 2]) {
            swap(arr, n - 1, (n - 1) / 2);
        }
    }
    for (int i = n - 1 - (n - 1) % 2; i >= 2; i -= 2) {
        if (arr[i] > arr[(i / 2 - 1)]) {
            swap(arr, i, i / 2 - 1);
        }
        if (arr[i - 1] > arr[(i / 2 - 1)]) {
            swap(arr, i - 1, i / 2 - 1);
        }
    }
    swap(arr, 0, n-1);
}

void pyramid(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        iteration(arr, n - i);
    }
}

int main() {
    int a[100] = { 0 };
    int n = data_in(a);
    pyramid(a, n);
    data_out(a, n);
    return 0;
}