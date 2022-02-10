#include <iostream>
using namespace std;
int point(int x, int y, int a, int b, int r) {
    if ((x - a) * (x - a) + (x - b) * (x - b) <= r * r) {
        std::cout <<"YES" << std::endl;
        return 1;
    }
    else { std::cout << "NO" << std::endl;
           return 0;
    }

}


int main() {
    int x = 0, y = 0, a = 0, b = 0, r = 0;
    cin >> x >> y >> a >> b >> r;
    point(x, y, a, b, r);
    return 0;
}
