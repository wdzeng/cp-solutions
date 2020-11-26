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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

void solve() {
    int n;
    cin >> n;
    int edge[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> edge[i][j];
            edge[i][j]--;
        }
    }

    int cur = 0;
    bool vis[n];
    ms(vis);
    for (int i = 0; i < n - 1; i++) {
        int far = n - 1;
        while (vis[edge[cur][far]]) far--;
        cur = edge[cur][far];
        vis[cur] = 1;
        int near = 1;
        while (vis[edge[cur][near]]) near++;
        cout << cur + 1 << ' ' << edge[cur][near] + 1 << '\n';
    }
    cout << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}