#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string a, b;
    cin >> a >> b;
    int l = -1, r = -1, n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i > -1; i--) {
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    }

    if (l == -1 && r == -1) return true;

    for (int i = l, j = r; i <= r; i++, j--) {
        if (a[i] != b[j]) return false;
    }

    return true;
}

int main() {
    cout << (solve() ? "YES" : "NO") << endl;
    return 0;
}