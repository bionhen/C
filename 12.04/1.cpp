#include <iostream>
using namespace std;

struct asking {
    int begin;
    int end;
};

int data_in(asking* &List, int *&arr) {
    int n = 0;
    cin >> n;
    List = new asking[n];
    for (int i = 0; i < n; i++) {
        cin >> List[i].begin >> List[i].end;
    }
    arr = new int[n];
    return n;
}

void swap_asking(asking* &List, int i, int j) {
    asking tmp = List[i];
    List[i] = List[j];
    List[j] = tmp;
}

void choose(asking* &List, int n, int* &arr) {
    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            if (List[j].end > List[i].end) {
                swap_asking(List, i, j);
            }
        }
    }
    arr[0] = 1;
    int end = List[0].end;
    for (int i = 1; i < n; i++) {
        if (List[i].begin > end) {
            end = List[i].end;
            arr[i] = 1;
        }
    }
    return;
}

void data_out(asking* &List, int n, int* &arr) {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            cout << List[i].begin << " " << List[i].end << '\n';
        }
    }
    delete[] arr;
    delete[] List;
    return;
}

int main(){
    asking* List = nullptr;
    int* arr = nullptr;
    int n = data_in(List, arr);
    choose(List, n, arr);
    data_out(List, n, arr);
    return 0;
}
