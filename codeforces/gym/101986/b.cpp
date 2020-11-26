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

int ans = 0;
vector<pii> marriage;
vector<pii> points;

void solve() {
    unordered_map<double, int> m;
    int intc = 0;
    for (auto& p : marriage) {
        pii a = points[p.x];
        pii b = points[p.y];
        // printf("Pair (%d,%d) (%d,%d) ", a.x, a.y, b.x, b.y);
        // printf("(%d, %d) ", p.x, p.y);
        if (a.x == b.x)
            intc++;
        else {
            double slope = double(a.y - b.y) / (a.x - b.x);
            m[slope]++;
        }
    }
    // printf("\n");
    int tmpans = 0;
    for (auto& p : m) {
        tmpans += p.y * (p.y - 1) / 2;
    }
    tmpans += intc * (intc - 1) / 2;
    ans = max(ans, tmpans);
}

void dfs(int mask) {
    // cout << mask << endl;
    if (!mask) {
        solve();
        return;
    }
    int low = mask & -mask;
    mask &= ~low;

    vector<int> wife;
    while (mask) {
        int k = mask & -mask;
        wife.push_back(k);
        mask &= ~k;
    }
    for (int k : wife) mask |= k;
    for (int k : wife) {
        mask &= ~k;
        marriage.emplace_back(__lg(low), __lg(k));
        dfs(mask);
        marriage.pop_back();
        mask |= k;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    dfs((1 << n) - 1);
    cout << ans << endl;
    return 0;
}
