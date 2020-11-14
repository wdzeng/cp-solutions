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

const int N = 505;
vector<int> fa[N], owns[N];
int afab[N][N], aownb[N][N];

int vis[N];
void dfsfa(int v, int src) {
    vis[v] = 1;
    afab[src][v] = 1;
  //  printf("%d has father %d\n", src, v);
    for (int a : fa[v])
        if (!vis[a]) dfsfa(a, src);
}
void dfsown(int v, int src) {
    vis[v] = 1;
    aownb[src][v] = 1;
  //  printf("%d owns %d\n", src, v);
    for (int a : owns[v])
        if (!vis[a]) dfsown(a, src);
}

unordered_map<string, int> m;
int id(const string& s) {
    if (!m.count(s)) m[s] = m.size();
    return m[s];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int w = 0; w < n; w++) {
        string a, b, v;
        cin >> a >> v >> b;
        int i = id(a), j = id(b);
        if (v == "is-a") {
            fa[i].push_back(j);
        } else {
            owns[i].push_back(j);
        }
    }
    n = m.size();

    for (int i = 0; i < n; i++) ms(vis), dfsfa(i, i);
    for (int i = 0; i < n; i++) ms(vis), dfsown(i, i);
    for (int i = 0; i < n; i++) {
        vector<int> owner, owned;
        for (int x = 0; x < n; x++)
            if (afab[x][i]) owner.push_back(x);
        for (int o = 0; o < n; o++)
            if (aownb[i][o])
                for (int f = 0; f < n; f++)
                    if (afab[o][f]) owned.push_back(f);
        for (auto x : owner)
            for (auto y : owned) aownb[x][y] = 1/*, printf("%d owns %d\n", x, y)*/;
    }
    fflush(stdin);

    for (int _q = 1; _q <= q; _q++) {
        string a, b, v;
        cin >> a >> v >> b;
        int i = id(a), j = id(b);
        int ans;
        if (v == "is-a")
            ans = afab[i][j];
        else
            ans = aownb[i][j];
        printf("Query %d: %s\n", _q, ans ? "true" : "false");
    }
    return 0;
}