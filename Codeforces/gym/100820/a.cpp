#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

// 只能 0-base
const int N = 1010;  // count of left + right vertices
const int INF = 2e9;
int vis[N], rnd, m[N];  // m will store the result
vector<int> g[N];       // adjacent list 記得 right vertices index 平移

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

// Store the match result in `m` array and result the count of matches
int hungarian(int p) {  // p is count of left vertices
    memset(m, -1, sizeof(m));
    int c = 0;
    for (int i = 0; i < p; i++) {
        if (m[i] == -1) {
            memset(vis, 0, sizeof(vis));
            c += dfs(i);
        }
    }
    return c;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int air, m;
    cin >> air >> m;
    vector<int> rest(air);
    for (auto& r : rest) cin >> r;

    int dist[air][air];
    int mtx[air][air];
    for (int i = 0; i < air; i++) {
        for (int j = 0; j < air; j++) {
            cin >> mtx[i][j];
            dist[i][j] = mtx[i][j];
            if (i != j) dist[i][j] += rest[j];
        }
    }

    for (int i = 0; i < air; i++) {
        for (int j = 0; j < air; j++) {
            for (int k = 0; k < air; k++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<pair<pii, int>> task(m);
    for (auto& p : task) {
        cin >> p.x.x >> p.x.y >> p.y;
        p.x.x--;
        p.x.y--;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int ifrom = task[i].x.x;
            int ito = task[i].x.y;
            int jfrom = task[j].x.x;
            int jstart;
            if (ito != jfrom)
                jstart = task[i].y + mtx[ifrom][ito] + rest[ito] + dist[ito][jfrom];
            else
                jstart = task[i].y + mtx[ifrom][ito] + rest[ito];
            if (jstart <= task[j].y) g[i].push_back(j + m);
        }
    }

    cout << m - hungarian(m) << endl;

    return 0;
}