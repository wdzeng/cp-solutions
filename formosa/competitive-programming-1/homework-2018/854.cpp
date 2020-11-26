#include <iostream>
using namespace std;

// 854 AC

// ax + by = 1
void gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return;
    }
    int x1, y1;
    gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
}

int modInverse(int a, int m) {
    int x, y;
    // ax + my = 1
    gcd(a, m, &x, &y);
    return x > 0 ? x : ((x % m + m) % m);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, m;
        cin >> a >> m;
        cout << modInverse(a, m) << "\n";
    }
    return 0;
}