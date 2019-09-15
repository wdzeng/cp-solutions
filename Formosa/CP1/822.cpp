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

void solve() {
    int n;
    ll l, r;
    cin >> n >> l >> r;

    int len = min((int)(r - l + 1), n);
    bool vis[len] = {0};

    while (n--) {
        ll x;
        cin >> x;
        x -= l;
        if (x < 0 || x >= len) continue;
        vis[x] = 1;
    }

    for (ll i = l; i <= r; i++) {
        ll index = i - l;
        if (index >= len || !vis[index]) {
            cout << i << endl;
            return;
        }
    }

    cout << "^v^\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) solve();
    return 0;
}