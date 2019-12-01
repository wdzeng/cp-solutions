#include <bits/stdc++.h>
using namespace std;
typedef long double dd;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

vector<int> primes(int n) {
    bool flag[n + 1];
    ms(flag);
    vector<int> ret;
    for (int i = 2; i <= n; i++) {
        if (flag[i]) continue;
        for (int x = i; x <= n; x += i) flag[x] = true;
        ret.push_back(i);
    }
    return ret;
}

ll roundup(ll a, ll b) {
    if (a == 0) return 0;
    return (a - 1) / b + 1;
}

const int ASK = 41;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;

    ll v;
    for (int i = 0; i < ASK; i++) {
        cout << 2 << endl;
        string reply;
        cin >> reply;
        if (reply == "OK") return 0;
        assert(reply != "=");
        v <<= 1;
        if (reply == "<") v |= 1;
    }

    ll v2_ASK = 1;
    for (int i = 0; i < ASK; i++) v2_ASK <<= 1;
    auto ps = primes(n);

    for (ll p : ps) {
        ll x = roundup(v * p, v2_ASK);
        if (x * v2_ASK < (v + 1) * p) {
            cout << p << endl;
            string reply;
            cin >> reply;
            assert(reply == "OK");
            return 0;
        }
    }
    assert(false);
    return -1;
}