#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#endif

ll modinv(ll a, ll p) {  //(ax == 1)mod p，p質數，a正整數
    if (p == 1) return 0;
    ll pp = p, y = 0, x = 1;
    while (a > 1) {
        ll q = a / p, t = p;
        p = a % p, a = t, t = y, y = x - q * y, x = t;
    }
    if (x < 0) x += pp;
    return x;
}

const ll M = 998244353;
ll c2n_n(int n) {
    ll ret = 1;
    ll fact = 1;
    for (int i = 1; i <= n; i++) ret = ret * (n + i) % M, fact = fact * i % M;
    return ret * modinv(fact, M) % M;
}

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int n;
    cin >> n;
    vector<int> vec(2 * n);
    for (auto& val : vec) cin >> val;
    sort(all(vec));
    ll cost = 0;
    for (int i = 0; i < n; i++) cost += abs(vec[i] - vec[2 * n - 1 - i]);
    cost %= M;
    cout << c2n_n(n) * cost % M << endl;
    return 0;
}