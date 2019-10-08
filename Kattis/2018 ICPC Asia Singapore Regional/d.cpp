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

const int maxn = 5e5 + 10;
int n, k;
int val[maxn * 2];

bool judge(int mask, int l) {
    // cout << "l" << l << endl;
    int g = 0, v = 0;
    for (int i = l; i < l + n; i++) {
        v |= val[i];
        if ((v & mask) == mask) {
            // cout << "g at " << i << endl;
            if (++g == k) return 1;
            v = 0;
        }
    }
    // cout << g << endl;
    return 0;
}

bool judge(int mask) {
    int tried = 0;
    for (int i = 0; i < n; i++) {
        if ((mask & (tried | val[i])) == (mask & tried)) continue;
        if (judge(mask, i + 1)) return 1;
        tried |= val[i];
    }
    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        val[n + i] = val[i];
    }
    int ans = 0;
    for (int d = (1 << 30); d; d >>= 1) {
        if (judge(ans | d)) ans |= d;
    }
    cout << ans << endl;
    return 0;
}