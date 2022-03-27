#include <iostream>

using namespace std;

int *creation(int n) {
    int *matrix = new int[n*n];
    int x = 0;
    for (int i = 0; i < n * n; i++) {
        cin >> x;
        matrix[i] = x;
    }
    return matrix;
}

int pow_minus_one(int k) {
    if (k % 2 == 1) {
        return -1;
    }
    else { return 1; }
}

int det(int n, int* arr) {
    int d = 0;
    if (n == 1) {
        return arr[0];
    }
    int* arr_1 = new int[(n - 1) * (n - 1)];
    for (int idx = 0; idx < n; idx++) {
        for (int r = 0; r < idx * (n - 1); r++) {
            int i = r / (n - 1);
            int j = r % (n - 1);
            arr_1[r] = arr[i * n + 1 + j];
        }
        for (int r = idx*(n-1); r < (n - 1) * (n - 1); r++) {
            int i = r / (n - 1);
            int j = r % (n - 1);
            arr_1[r] = arr[(i + 1) * n + 1 + j];
        }
        d += pow_minus_one(idx + 1 + 1) * det(n - 1, arr_1) *  arr[idx*n];
    }
    delete[] arr_1;
    return d;
}

int main(){
    int n = 0;
    cin >> n;
    int *matrix = creation(n);
    cout << det(n, matrix);
}

