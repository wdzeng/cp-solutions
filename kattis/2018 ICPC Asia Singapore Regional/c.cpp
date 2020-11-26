#include <bits/stdc++.h>
using namespace std;
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

const ll M = 1000000007;
const ll H = 1e7;
const char C = 'h';

ll token(ll prev) {
    prev = (prev * 31 + C) % M;
    prev = prev * 7 % M;
    ll ret = H - prev;
    ret = (ret % M + M) % M;
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll v;
    cin >> v;
    ll first = token(v);
    ll second = token(H);
    printf("%c %lld\n%c %lld\n", C, first, C, second);
    return 0;
}