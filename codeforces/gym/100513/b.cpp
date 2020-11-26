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

int k, n;
vector<vector<int>> x;

int most() {
    int ret = -1;
    int sz = -1;
    for (int i = 0; i < n; i++) {
        if ((int)x[i].size() > sz) {
            ret = i;
            sz = x[i].size();
        }
    }
    return ret;
}

int least() {
    int ret = -1;
    int sz = k + 1;
    for (int i = 0; i < n; i++)
        if (!x[i].empty() && (int)x[i].size() < sz) {
            ret = i;
            sz = x[i].size();
        }
    return ret;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    cin >> k >> n;
    vector<pii> ans(k);
    x.resize(n);
    vector<int> b;
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        if (c == -1)
            b.push_back(i);
        else
            x[c - 1].push_back(i);
    }

    int m = most();
    x[m].insert(x[m].end(), iter(b));

    int rm = n;
    while (rm--) {
        int m = most();
        int l = least();
        assert(m!=-1 && l!=-1);
        assert(x[m].size() + x[l].size() >= k / n);

        int r = k / n;
        vector<pii> u;
        while (r--) {
            if (!x[l].empty()) {
                int i = x[l].back();
                x[l].pop_back();
                u.push_back({l, i});
            }  //
            else {
                assert(!x[m].empty());
                int i = x[m].back();
                x[m].pop_back();
                u.push_back({m, i});
            }
        }

        for (auto& p : u) {
            int i = p.y;
            ans[i] = {p.x, p.x == l ? m : l};
        }
    }

    cout << "Yes\n";
    for (auto& p : ans) cout << p.x + 1 << ' ' << p.y + 1 << '\n';
    return 0;
}