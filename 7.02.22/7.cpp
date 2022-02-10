#include <iostream>
using namespace std;
int f = 0; int s = 0; int t = 0; int fo = 0;
void point(int x, int y) {
    if (x > 0 && y > 0) {
        f += 1;
    }
    else {
        if (x < 0 && y > 0)
            s += 1;
        else {
            if (x < 0 && y < 0) { t += 1; }
            else { if (x > 0 && y < 0) { fo += 1; } }
        }
    }

}
int main() {
    int N = 0, i = 1, p1, p2;
    cin >> N;
    while (i <= N) {
        cin >>p1>>p2;
        point(p1, p2);
        i += 1;
    }
    cout << f <<","<< s << "," << t << "," << fo;
    return 0;
}
