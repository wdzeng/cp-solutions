#include <iostream>
using namespace std;

// AC

int main() {
    int n, t;
    cin >> n >> t;
    int s[n + 1];
    s[0] = 0;
    int v = 0, x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s[i] = (v ^= x);
    }

    int l, r;
    while (t--) {
        cin >> l >> r;
        cout << (s[r] ^ s[l - 1]) << "\n";
    }

    return 0;
}