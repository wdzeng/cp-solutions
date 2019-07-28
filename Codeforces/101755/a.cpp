#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int s, g;
    cin >> s >> g;
    if (s % g != 0) {
        cout << -1 << endl;
        return 0;
    }

    s /= g;
    for (int i = 1; i < s; i++) {
        int x = i, y = s - i;
        if (__gcd(x, y) == 1) {
            cout << x*g << " " << y*g << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}