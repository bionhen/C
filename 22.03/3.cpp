#include <iostream>

using namespace std;

void my_personal_swap(int* a, int* b) {
    if (a != nullptr && b!= nullptr) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    return;
}


int main() {
    int a, b;
    cin >> a >> b;
    my_personal_swap(&a, &b);
    cout << a << " " << b << endl;
    my_personal_swap(&a, nullptr);
    my_personal_swap(nullptr, &b);
    my_personal_swap(nullptr, nullptr);
    return 0;
}