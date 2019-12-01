#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] || a[i] == c[i])
            cout << a[i];
        else if (b[i] == c[i])
            cout << b[i];
        else
            cout << a[i];
    }
    return 0;
}