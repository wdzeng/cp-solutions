#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 16;
vector<int> adj[N];
int n;
int col[N];

int two(const vector<int>& cands) {
    ms(col);
    for (int i = 0; i < n; i++) {
        if (!cands[i]) continue;
        if (col[i]) continue;
        col[i] = 1;
        vector<int> k = {i};
        while (!k.empty()) {
            int u = k.back();
            k.pop_back();
            for (int a : adj[u]) {
                if (!cands[a]) continue;
                if (col[a] == col[u]) return 0;
                if (col[a]) continue;
                col[a] = 3 - col[u];
                k.push_back(a);
            }
        }
    }
    return (find(col, col + N, 2) == col + N) ? 1 : 2;
}

int four() {
    ms(col);
    vector<int> ga(n), gb(n);
    for (int m = 1; m < ((1 << n) - 1); m++) {
        ga.assign(n, 0);
        gb.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if ((m >> i) & 1)
                ga[i] = 1;
            else
                gb[i] = 1;
        }
        int ans1 = two(ga);
        if (ans1 == 0) continue;
        int ans2 = two(gb);
        if (ans2 == 0) continue;
        if (ans1 + ans2 == 3) return 3;
        return 4;
    }
    return 0;
}

void solve() {
    int m;
    cin >> n >> m;

    for (auto& a : adj) a.clear();

    if (m == 0) {
        cout << "1\n";
        return;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (two(vector<int>(n, 1))) {
        cout << "2\n";
        return;
    }

    int k = four();
    if (k) {
        cout << k << '\n';
        return;
    }

    cout << "many\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}