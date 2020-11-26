#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const int N = 12;
ll dp[1 << N][N];
int n;
vector<set<int>> h;

ll finddp(int m, int f) {
    if (~dp[m][f]) return dp[m][f];
    if ((1 << f) == m) return 1;
    dp[m][f] = 0;
    for (int i = 0; i < n; i++) {
        if (i == f) continue;
        if (((m >> i) & 1) == 0) continue;
        if (h[i].count(f)) continue;
        dp[m][f] += finddp(m - (1 << f), i);
    }
    return dp[m][f];
}

void findans(int dep, int m, vector<int>& ans) {
    if (dep == 0) {
        throw 1;
    }
    for (int i = 0; i < n; i++) {
        if ((m >> i) & 1) {
            if (ans.size() && h[i].count(ans.back())) continue;
            ans.push_back(i);
            findans(dep - 1, m - (1 << i), ans);
            ans.pop_back();
        }
    }
}

void solve() {
    cin >> n;
    vector<string> i2col;
    map<string, int> col2i;
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        i2col.push_back(c);
        col2i[c] = i;
    }

    h.assign(n, {});

    int m;
    cin >> m;
    while (m--) {
        string sa, sb;
        cin >> sa >> sb;
        int a = col2i[sa];
        int b = col2i[sb];
        h[a].insert(b);
        h[b].insert(a);
    }

    mss(dp);
    ll cans = 0;
    for (int i = 0; i < n; i++) {
        cans += finddp((1 << n) - 1, i);
    }
    vector<int> ans;
    try {
        findans(n, (1 << n) - 1, ans);
    } catch (...) {
    }

    cout << cans << endl;
    for (int i : ans) cout << i2col[i] << ' ';
    cout << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}