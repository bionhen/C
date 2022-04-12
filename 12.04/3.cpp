#include <iostream>
using namespace std;

struct item {
    int mass;
    int utility;
    double alpha;
};

int data_in(item*& List) {
    int n = 0;
    cin >> n;
    List = new item[n];
    for (int i = 0; i < n; i++) {
        cin >> List[i].mass >> List[i].utility;
        List[i].alpha = (double)List[i].utility / (double)List[i].mass;
    }
    return n;
}

void swap_item(item*& List, int i, int j) {
    item tmp = List[i];
    List[i] = List[j];
    List[j] = tmp;
}

void distribution(item*& List, int n, int sum_mass) {
    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            if (List[j].alpha < List[i].alpha) {
                swap_item(List, i, j);
            }
        }
    }
    int alpha = List[0].alpha;
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (List[i].mass <= sum_mass) {
            cout << List[i].mass << " " << List[i].utility << " " << (sum_mass / List[i].mass) << '\n';
            sum_mass = sum_mass - (sum_mass / List[i].mass) * List[i].mass;
        }
        if (i == n-1 && sum_mass != 0) {
            cout << List[i].mass << " " << List[i].utility << " " << ((double)sum_mass / (double)List[i].mass) << '\n';
        }
    }
    delete[] List;
    return;
}

int main() {
    item* List = nullptr;
    int n = data_in(List);
    int sum_mass = 0;
    cin >> sum_mass;
    distribution(List, n, sum_mass);
    return 0;
}