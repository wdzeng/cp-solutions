#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 1e5 + 10;
vector<vector<int>> adj(N), radj(N);
vector<int> isTo(N, -1);

void heIsBad(int src, int dst) {
    assert(isTo[src] != -2);
    isTo[src] = -2;
    vector<int> vec = {src};
    while (!vec.empty()) {
        int v = vec.back();
        vec.pop_back();
        for (int a : radj[v]) {
            if (a == dst) continue;
            if (isTo[a] == -2) continue;
            isTo[a] = -2;
            vec.push_back(a);
        }
    }
}

void explore(int src, int dst) {
    if (isTo[src] == -2) return;
    if (isTo[src] != -1 and isTo[src] != src) {
        heIsBad(src, dst);
        return;
    }
    if (isTo[src] == src) return;

    isTo[src] = src;
    vector<int> vec = {src};
    while (!vec.empty()) {
        int v = vec.back();
        vec.pop_back();
        if (isTo[v] == -2) continue;
        for (int a : radj[v]) {
            if (a == dst) continue;
            int to = isTo[a];
            if (to == -2) continue;
            if (to != -1 and to != src) {
                heIsBad(a, dst);
                continue;
            }
            if (to == src) continue;
            isTo[a] = src;
            vec.push_back(a);
        }
    }
    return;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for (int i : radj[t]) {
        explore(i, t);
    }

    vector<int> ans;
    for (int i : radj[t]) {
        if (isTo[i] == i) ans.push_back(i);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (int a : ans) cout << a << '\n';
    return 0;
}