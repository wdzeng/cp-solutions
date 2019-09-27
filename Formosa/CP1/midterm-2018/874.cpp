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

const int maxn = 1e6 + 10;
int val[maxn * 4];
vector<bool> ok(maxn * 4, 1);

void asg(int i, int curl, int curr, int tarl, int tarr, int v) {
    if (curr < tarl || tarr < curl) return;
    if (tarl <= curl && curr <= tarr) {
        ok[i] = 1, val[i] = v;
        return;
    }
    if (ok[i]) {
        val[i * 2 + 1] = val[i * 2 + 2] = val[i];
        ok[i * 2 + 1] = ok[i * 2 + 2] = 1;
    }
    ok[i] = 0;
    int m = (curl + curr) / 2;
    asg(i * 2 + 1, curl, m, tarl, tarr, v);
    asg(i * 2 + 2, m + 1, curr, tarl, tarr, v);
    if (ok[i * 2 + 1] && ok[i * 2 + 2] && val[i * 2 + 1] == val[i * 2 + 2]) {
        ok[i] = 1, val[i] = val[i * 2 + 1];
    }
}

void asg(int l, int r, int v) { asg(0, 0, maxn - 1, l, r, v); }

int sum(int i, int curl, int curr, int tarl, int tarr) {
    if (curr < tarl || tarr < curl) return 0;
    if (tarl <= curl && curr <= tarr && ok[i]) {
        return (curr - curl + 1) * val[i];
    }
    if (ok[i]) {
        val[i * 2 + 1] = val[i * 2 + 2] = val[i];
        ok[i * 2 + 1] = ok[i * 2 + 2] = 1;
    }
    int m = (curl + curr) / 2;
    int l = sum(i * 2 + 1, curl, m, tarl, tarr);
    int r = sum(i * 2 + 2, m + 1, curr, tarl, tarr);
    return l + r;
}

int sum(int l, int r) { return sum(0, 0, maxn - 1, l, r); }

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int o, l, r;
        cin >> o >> l >> r; r--;
        int ans = sum(l, r);
        o %= 2;
        if (o == 1) ans = (r - l + 1) - ans;
        asg(l, r, o);
        cout << ans << '\n';
    }
    return 0;
}