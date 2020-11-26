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

const int N = 1e5 + 10;
vector<int> O[N];
vector<int> G[N];
int vis[N];

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = 1;
    for (int a : G[i]) dfs(a);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        int t;
        cin >> t;
        while (t--) {
            int a;
            cin >> a;
            a--;
            O[a].push_back(i);
        }
    }

    for (auto& v : O) {
        assert(v.size() == 0 or v.size() == 2);
        if (v.size() == 2) {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
    }

    int k = 0;
    for (int i = 0; i < R; i++) {
        if (vis[i]) continue;
        k++;
        dfs(i);
    }

    cout << R - k << endl;
    return 0;
}