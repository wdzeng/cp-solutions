#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 1e6 + 10;
const ll M = 1e9 + 7;

ll step(int n) {
    static vector<ll> rec = {1};
    while (rec.size() <= n) {
        rec.push_back(rec.back() * rec.size() % M);
    }
    return rec[n];
}

// 解 (ax == 1) mod p 。p 必須是質數，a 是正整數。
inline ll modinv(ll a, ll p) {
    if (p == 1) return 0;
    ll pp = p, y = 0, x = 1;
    while (a > 1) {
        ll q = a / p, t = p;
        p = a % p, a = t, t = y, y = x - q * y, x = t;
    }
    if (x < 0) x += pp;
    return x;
}
// 解 (ax == b) mod p 。p 必須是質數，a 和 b 是正整數。
inline ll modinv(ll a, ll b, ll p) {
    ll ret = modinv(a, p);
    return ret * b % p;
}

ll kata(int n) {
    static unordered_map<int, ll> rec;
    if (rec.count(n)) return rec[n];
    ll c2n = step(2 * n);
    ll cn = step(n);
    ll cnp1 = step(n + 1);
    ll ret = modinv(cnp1, modinv(cn, c2n, M), M);
    return rec[n] = ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

#define updateAns()                  \
    if (total >= 2) {                \
        ans = ans * kata(total) % M; \
    }

    vector<int> seq;
    ll ans = 1;
    int n;
    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        int e = -1;
        int total = 0;
        while (!seq.empty() && val < seq.back()) {
            if (seq.back() == e)
                total++;
            else {
                updateAns();
                e = seq.back();
                total = 1;
            }
            seq.pop_back();
        }
        updateAns();
        seq.push_back(val);
    }

    int e = -1;
    int total = 0;
    while (!seq.empty()) {
        if (seq.back() == e)
            total++;
        else {
            updateAns();
            e = seq.back();
            total = 1;
        }
        seq.pop_back();
    }
    updateAns();

    cout << ans << endl;
    return 0;
}