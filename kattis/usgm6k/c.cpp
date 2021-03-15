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

// Time: O(VE)
const int INF = 2e9;
const int N = 2010 ;       // 男女總人數；女 id: 0 ~ p，男 id: p+1 ~ N-1
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
    } return 0;
}
int hungarian(int p) {  // p : 女性人數
    memset(m, -1, sizeof(m));
    int c = 0;
    for (int i = 0; i < p; i++) {
        if (m[i] == -1) {
            memset(vis, 0, sizeof(vis));
            c += dfs(i);
        }
    } return c; // 成功結婚對數
}

int main() {
    fastio();
    int a, b;
    cin >> a >> b;
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < a; i++) {
        string name;
        cin >> name;
        int n;
        cin >> n;
        while (n--) {
            string bname;
            cin >> bname;
            m[bname].push_back(i);
        }
    }
    for (int i = a; i < a + b; i++) {
        string name;
        cin >> name;
        int n;
        cin >> n;
        while (n--) {
            string bname;
            cin >> bname;
            m[bname].push_back(i);
        }
    }

    for(auto& p: m) {
        g[p.y[0]].push_back(p.y[1]);
        g[p.y[1]].push_back(p.y[0]);
    }

    cout << hungarian(a) << endl;

    return 0;
}
