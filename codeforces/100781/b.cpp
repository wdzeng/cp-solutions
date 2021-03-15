#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

inline int step(int n) {
    int ret = 1;
    for (int i = 1; i <= n; i++) ret *= i;
    return ret;
}

vector<vector<int>> solve(int n) {
    if (n == 1) {
        return {{1}};
    }
    auto u = solve(n - 1);

    vector<vector<int>> ret;
    bool toleft = 1;
    for (auto& v : u) {
        if (toleft) {
            for (int i = n - 1; i >= 0; i--) {
                auto vv = v;
                vv.insert(vv.begin() + i, n);
                ret.push_back(vv);
            }
        } else {
            for (int i = 0; i < n; i++) {
                auto vv = v;
                vv.insert(vv.begin() + i, n);
                ret.push_back(vv);
            }
        }
        toleft = !toleft;
    }
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    auto ans = solve(n);
    for (auto& v : ans) {
        for (auto val : v) cout << val << ' ';
        cout << '\n';
    }

    return 0;
}