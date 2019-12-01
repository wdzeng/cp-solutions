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

vector<vector<string>> solve(const string& s) {
    set<string> ret = {""};
    for (char c : s) {
        set<string> u;
        for (string old : ret) u.insert(old + c);
        ret.insert(iter(u));
    }
    ret.erase("");
    vector<vector<string>> v(s.size());
    for (string sub : ret) {
        v[sub.size() - 1].push_back(sub);
    }
    return v;
}

const string& strcmp(const string& a, const string& b) {
    if (a == "") return b;
    if (b == "") return a;
    return a < b ? a : b;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    assert("B" < "U");
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];

    vector<string> dp(256);
    auto sub = solve(names[0]);
    for (auto& subs : sub) dp[subs[0].size()] = subs[0];

    for (int i = 1; i < n; i++) {
        string name = names[i];
        bool done = false;
        vector<string> u(256);
        auto sub = solve(name);
        for (int i = 1; i < 256; i++) {
            if (dp[i].empty()) continue;
            for (auto& subs : sub) {
                auto mx = upper_bound(iter(subs), dp[i]);
                if (mx == subs.end()) continue;
                int len = i + mx->size();
                u[len] = strcmp(u[len], *mx);
                done = 1;
            }
        }
        dp.swap(u);
        if (!done) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 255; i > -1; i--) {
        if (!dp[i].empty()) {
            cout << i << endl;
            return 0;
        }
    }
    assert(false);
    return 0;
}