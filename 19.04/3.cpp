#include <iostream>
using namespace std;

int data_in(int**& arr) {
    int n = 0;
    cin >> n;
    char a[3];
    arr = new int*[8];
    int pos_1 = 0;
    for (int i = 0; i < 8; i++) {
        arr[i] = new int [8];
        for (int j = 0; j < 8; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        cin >> a[0]>>a[1];

        for (int j = 0; j < 8; j++) {
           if (a[0] - 'a' == j) {
               pos_1 = j;
               break;
            }
        }
        if (i < n) {
            arr[a[1] - 1 - '0'][pos_1] = 1;
        }
        else {
            arr[a[1] - 1 - '0'][pos_1] = -1;
        }
    }
    return n;
}

int way(int**& arr, int pos_x, int pos_y, int & check, int**& arr_check) {
    int ch_1 = 0;
    if (arr[pos_y + 1][pos_x] == 0) {
        arr_check[pos_y + 1][pos_x] = -1;
        ch_1++;
    }
    if (pos_x < 7) {
        if (arr[pos_y + 1][pos_x + 1] == 1) {
            arr_check[pos_y + 1][pos_x + 1] = -1;
            ch_1++;
        }
    }
    if (pos_x > 0) {
        if (arr[pos_y + 1][pos_x - 1] == 1) {
            arr_check[pos_y + 1][pos_x - 1] = -1;
            ch_1++;
        }
    }
    check += ch_1 - 1;
    return 0;
}

int search(int**& arr) {
    int **arr_check = new int* [8];
    for (int i = 0; i < 8; i++) {
        arr_check[i] = new int[8];
        for (int j = 0; j < 8; j++) {
            arr_check[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < 8; i++) {
        if (arr[7][i]==-1) {
            return 1;
        }
    }
    int check = 1;
    for (int k = 0; k < 7; k++) {
        for (int j = 0; j < 8; j++) {
            if (arr_check[k][j] == -1) {
                way(arr, j, k, check, arr_check);
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        delete[] arr[i];
        delete[] arr_check[i];
    }
    delete[] arr_check;
    delete[] arr;
    return check;
}

int main() {
    int** arr = nullptr;
    int n = data_in(arr);
    cout << search(arr);
    return 0;
}