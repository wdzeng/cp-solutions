#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

pii magic(ll k) {
    ll n = sqrt(ll(k) * 2);
    for (ll i = n;; i--) {
        ll v = i * (i + 1) / 2 + i / 2 * 2 + 2;
        if (v <= k) return {i, v};
    }
    throw "";
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    char d = 'b';
    while (n > 1) {
        pii m = magic(n);
        // cout << m.first << ", " << m.second << endl;
        n -= m.second;
        cout << d++;
        for (int i = 0; i < m.first; i++) cout << 'a';
        cout << d++;
    }
    if (n == 1) cout << d++;

    cout << endl;
    return 0;
}