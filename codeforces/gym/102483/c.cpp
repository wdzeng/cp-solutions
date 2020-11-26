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

const double PI = acos(-1.0);
const double T = PI / 1005;
vector<int> adj[1005];
vector<pair<double, double>> ans;
int c = 0;
void dfs(int i, int p) {
    for (int a : adj[i]) {
        if (a != p) {
            ans[a] = {ans[i].x + cos(c * T), ans[i].y + sin(c * T)};
            c++;
            dfs(a, i);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans.resize(n);
    dfs(0, -1);
    for (auto& p : ans) printf("%.18f %.18f\n", p.x, p.y);
    return 0;
}