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

vector<ll> v;

bool judge(int c, int lm) {
    ll diff = 0;
    ll l = 0, r = v.size() - 1;
    for (int i = 0; i < c; i++) {
        ll lcost = (v[r - 1] - v[r]) * (v.size() - r);
        ll hcost = (v[l] - v[l + 1]) * (l + 1);
        if (lcost < hcost) {
            diff += lcost;
            r--;
        } else {
            diff += hcost;
            l++;
        }
    }
    return diff <= lm;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    ll lm;
    cin >> lm;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(iter(v), greater<int>());
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (judge(m, lm))
            l = m + 1;
        else
            r = m - 1;
    }
    l--;
    cout << judge(l, lm) << endl;

    int lp = 0;
    int rp = v.size() - 1;
    for (int i = 0; i < l; i++) {
        ll lcost = (v[rp - 1] - v[rp]) * (v.size() - rp);
        ll hcost = (v[lp] - v[lp + 1]) * (lp + 1);
        if (lcost < hcost) {
            r--;
        } else {
            l++;
        }
    }
    cout << lp << ' ' << rp << ' ' << l << endl;
    cout << v[lp] - v[rp] << endl;
    return 0;
}
