#include <iostream>
using namespace std;

int data_in(int* &arr) {
    int n = 0;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return n;
}

int max(int a, int b) {
    if (b > a) {
        return b;
    }
    else {
        return a;
    }
}

void search(int*& arr, int n) {
    int* length = new int[n];
    for (int i = 0; i < n; i++) {
        length[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }
    int maximum = length[0];
    for (int i = 0; i < n; i++) {
        maximum = max(maximum, length[i]);
    }
    cout << maximum;
    return;
}

int main(){
    int* arr = nullptr;
    int n = data_in(arr);
    search(arr, n);
}

