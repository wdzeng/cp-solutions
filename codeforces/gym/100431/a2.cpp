#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX_N 1234
using namespace std;

int gao[MAX_N];
int k;
struct edge {
    bool vis;
    int to;
    edge(int t)
        : vis(0), to(t) {}
    edge() {}
};

vector<edge> G[MAX_N];
int tot = 0, road[MAX_N];
bool flag = false;
int n;

int st[MAX_N], all = 0;

void dfs(int u) {
    //cout<<u<<endl;
    int i = gao[u];
    while (i < G[u].size() && G[u][i].vis) i++;
    if (i == G[u].size()) return;
    gao[u] = i + 1;
    G[u][i].vis = 1;
    st[all++] = G[u][i].to;
    dfs(G[u][i].to);
}

bool check(int u) {
    //cout<<G[u][0].vis<<endl;
    if (gao[u] == G[u].size()) return false;
    return true;
}

void Fluery(int s) {
    st[all++] = s;
    while (all) {
        int now = st[all - 1];
        if (check(now))
            dfs(now);
        else {
            //cout<<rHash(now)<<endl;
            road[tot++] = now;
            all--;
        }
    }
}

bool vis[MAX_N][MAX_N];
int newRoad[MAX_N];

int main() {
   // freopen("achromatic.in", "r", stdin);
   // freopen("achromatic.out", "w", stdout);
    scanf("%d", &n);
    for (k = 0;; k++) {
        int t;
        if (k & 1)
            t = k * (k - 1) / 2;
        else
            t = k * k / 2;
        if (t > n) break;
    }
    k--;
    if ((k & 1) && n == (k * (k - 1)) / 2 + 1) k--;
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
        for (int j = 1; j <= k / 2; j++) {
            int u = i;
            int v = (i + j) % k;
            G[u].push_back(edge(v));
        }
    Fluery(0);
    int pos = 0;
    for (int i = 0; i < tot - 1; i++) {
        int u = i, v = (i + 1) % (tot - 1);
        if (vis[u][v]) {
            pos = u;
            break;
        }
        vis[u][v] = vis[v][u] = 1;
    }
    int nt = 0;
    for (int i = pos + 1; i < tot - 1; i++)
        newRoad[nt++] = road[i];
    for (int i = 0; i <= pos; i++) newRoad[nt++] = road[i];
    for (int i = 0; i < tot - 1; i++)
        printf("%d ", newRoad[i] + 1);
    if (n == tot - 1) {
        return 0;
    }
    if (n - (tot - 1) == 1) {
        int j = 1;
        while (j == newRoad[tot - 2] + 1 || j == newRoad[0] + 1) {
            j++;
            if (j == k + 1) j = 1;
        }
        printf("%d\n", j);
        return 0;
    }
    printf("%d ", newRoad[0] + 1);
    int p = newRoad[0] + 1;
    for (int i = tot; i < n; i++) {
        int j = 1;
        while (j == p || (i == n - 1 && j == newRoad[0] + 1)) {
            j++;
            if (j == k + 1) j = 1;
        }
        printf("%d ", j);
        p = j;
    }
    printf("\n");
    return 0;
}