#include <iostream>
using namespace std;
int min(int p1, int p2) {
    if (p1 >= p2) {
            return p2;
     }
    else {
       return p1;
        }
    }

int main() {
    int minim = 0, p = 1, N, k = 0, i = 1;
    cin >> N;
    while (i <= N) {
        cin >> p;
        if (i == 1) {
            minim = p;
        }
        i += 1;
        if (min(p, minim) != minim) {
            k = 1;
        }
        else { if (p == minim) { 
            k += 1; 
        } 
        }
        minim = min(p, minim);
    }
    cout << minim << endl;
    cout << k;
    return 0;
}