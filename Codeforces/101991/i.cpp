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
    int n, k;
    cin >> n >> k;
    vector<ll> cal(n), hap(n);
    for (int i = 0; i < n; i++) cin >> cal[i];
    for (int i = 0; i < n; i++) cin >> hap[i];

    vector<int> num(n);
    for (int i = 0; i < n; i++) num[i] = i;
    sort(iter(num), [&](int i, int j) { return cal[i] < cal[j]; });
    int mincal = cal[num[k - 1]];

    vector<int> uhap;
    for (int i = 0; i < n && cal[num[i]] <= mincal; i++) {
        uhap.push_back(hap[num[i]]);
    }
    sort(iter(uhap), greater<int>());
    ll hsum = 0;
    for (int i = 0; i < k; i++) hsum += uhap[i];
    cout << mincal << ' ' << hsum << '\n';
}

int main() {
    freopen("icecream.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}