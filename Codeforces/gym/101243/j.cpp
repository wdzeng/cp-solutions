#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

namespace H {
// Time: O(VE)
const int INF = 2e9;
const int N = 205;      // 男女總人數；女 id: 0 ~ p，男 id: p+1 ~ N-1
int vis[N], rnd, m[N];  // 跑完匈牙利後配對結果儲存於此， -1 表示人醜
vector<int> g[N];       // 關係表
int dfs(int s) {
    for (int x : g[s]) {
        if (vis[x]) continue;
        vis[x] = 1;
        if (m[x] == -1 || dfs(m[x])) {
            m[x] = s, m[s] = x;
            return 1;
        }
    }
    return 0;
}
int hungarian(int p) {  // p : 女性人數
    memset(m, -1, sizeof(m));
    int c = 0;
    for (int i = 0; i < p; i++) {
        if (m[i] == -1) {
            memset(vis, 0, sizeof(vis));
            c += dfs(i);
        }
    }
    return c;  // 成功結婚對數
}
}

int main() {
#ifndef hy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> s, t;
    while (n--) {
        string str;
        cin >> str;
        s.push_back(str);
    }
    while (m--) {
        string str;
        cin >> str;
        t.push_back(str);
    }
    n = s.size(), m = t.size();
    for (auto& str : s)
        for (char& c : str) c -= '0';
    for (auto& str : t)
        for (char& c : str) c -= '0';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][0] + s[i][1] + s[i][2] == t[j][3] + t[j][4] + t[j][5] ||
            s[i][3] + s[i][4] + s[i][5] == t[j][0] + t[j][1] + t[j][2]) H::g[i].push_back(n + j);
        }
    }

    for (auto& str : s)
        for (char& c : str) c += '0';
    for (auto& str : t)
        for (char& c : str) c += '0';

    int res = H::hungarian(n);
    cout << res << '\n';
    for (int i = 0; i < n; i++) {
        if (H::m[i] == -1) continue;
        int j = H::m[i] - n;
        if (s[i][0] + s[i][1] + s[i][2] == t[j][3] + t[j][4] + t[j][5]) {
            cout << "AT " << s[i] << ' ' << t[j] << '\n';
        }  //
        else {
            cout << "TA " << t[j] << ' ' << s[i] << '\n';
        }
    }
    return 0;
}