#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int c, n;
    cin >> c >> n;
    long long s = 0;
    long long in, out, wait;
    for (int i = 0; i < n; i++) {
        cin >> out >> in >> wait;
        s -= out;
        if (s < 0) return false;
        s += in;
        if (s > c) return false;
        if (s != c && wait > 0) return false;
    }
    return s == 0;
}

int main() {
    cout << (solve() ? "possible": "impossible") << endl;
}