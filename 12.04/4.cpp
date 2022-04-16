#include <iostream>
using namespace std;

int data_in(int** &matrix, int* &arr){
    int n = 0;
    cin >> n;
    matrix = new int*[n-1];
    for (int i = 0; i < n - 1; i++) {
        matrix[i] = new int[n - 1];
        for (int j = 0; j < n - 1; j++) {
            if (j < i) {
                matrix[i][j] = 0;
            }
            else {
                cin >> matrix[i][j];
            }
        }
    }
    arr = new int[n + 1];
    for (int i = 1; i < n + 1; i++) {
        arr[i] = -2;
    }
    return n;
}


int search(int**& matrix, int n, int*& arr, int k, int f) {
    int minim = 0;
    bool check = false;
    if (k > -1) {
        for (int i = 0; i < k + 1; i++) {
            for (int j = 0; j < f; j++) {
                if (i - 1 == arr[j]) {
                    check = true;
                    break;
                }
            }
            if (check == true) {
                check = false;
                continue;
            }
            if (minim == 0) {
                 minim = matrix[i][k];
                 arr[f] = i - 1;
            }
            if (matrix[i][k] < minim) {
                minim = matrix[i][k];
                arr[f] = i - 1;
            }
        }
    }
    if (k < n - 2) {
        for (int i = k + 1; i < n - 1; i++) {
            for (int j = 0; j < f; j++) {
                if (i == arr[j]) {
                    check = true;
                    break;
                }
            }
            if (check == true) {
                check = false;
                continue;
            }
            if (minim == 0) {
                minim = matrix[k + 1][i];
                arr[f] = i;
            }
            if (matrix[k + 1][i] < minim) {
                minim = matrix[k + 1][i];
                arr[f] = i;
            }
        }
    }
    return 0;
}

void way(int**& matrix, int n, int *& arr) {
    arr[0] = -1;
    for (int f = 1; f < n; f++) {
        search(matrix, n, arr, arr[f - 1], f);
        for (int l = 0; l < n; l++) {
            cout << arr[l] << " ";
        }
        cout << '\n';
    }
    arr[n] = -1;
    return;
}

void data_out(int**& matrix, int n, int*& arr){
    for (int i = 0; i < n; i++) {
        cout << arr[i] + 2 << "-";
    }
    cout << "1";
    return;
}

int main() {
    int** matrix = nullptr;
    int* arr = nullptr;
    int n = data_in(matrix, arr); // вводится верхнетреуголная (без главной диагонали) матрица порядка n-1
    way(matrix, n, arr);
    data_out(matrix, n, arr);
    return 0;
}