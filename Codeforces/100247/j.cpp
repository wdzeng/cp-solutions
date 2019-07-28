#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 0, y = 0;
    int n;
    cin >> n;
    while (n--) {
        int _x, _y;
        cin >> _x >> _y;
        if (_x > x) {
            x = _x;
            y = max(y, _y);
        }
    }
    cout << y << endl;
    return 0;
}