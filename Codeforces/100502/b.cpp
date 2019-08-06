#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

double t0;
int n, k;
vector<int> edge[100000];

bool try_color() {
    bool vis[n];
    ms(vis);
    int colored = 0, rem = n;
    for (int i = 0; i < k; i++) {
        if (rem == 0) return false;
        int x = rand() % n;
        while (vis[x]) x = (x + 1) % n;
        vis[x] = true, colored++, rem--;
        for (int e : edge[x])
            if (!vis[e]) vis[e] = true, rem--;
    }
    return true;
}

int main() {
    t0 = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    cin.tie(NULL), ios::sync_with_stdio(false);
    scanf("%d%d", &k, &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int e;
            scanf("%d", &e);
            edge[i].push_back(e - 1);
        }
    }
    while (!try_color()) {
        if (clock() / CLOCKS_PER_SEC - t0 >= 1.750) {
            printf("impossible\n");
            return 0;
        }
    }
    printf("possible\n");
    return 0;
}