#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))

int n, k;
const int maxn = 1e4 + 2;

struct edge {
    int dest, dist, e;
    edge(int dst, int d, int e) : dest(dst), dist(d), e(e) {}
};

vector<edge> graph[maxn];

struct path {
    int loc, min_e, dist;
    path(int l, int e, int d) : loc(l), min_e(e), dist(d) {}
};

vector<pii> dijsktra() {
    vector<pii> power(k, {0, INT_MAX});
    bool visited[n];
    ms(visited);
    visited[n - 1] = true;

    auto comp = [](path& a, path& b) {
        if (a.min_e != b.min_e) return a.min_e < b.min_e;
        return a.dist > b.dist;
    };
    priority_queue<path, vector<path>, decltype(comp)> q(comp);
    for (edge& e : graph[n - 1]) {
       // cout << "Pushed " << e.dest +1 << ", " << e.e << ", " << e.dist << endl;
        q.push(path(e.dest, e.e, e.dist));
    }
    int kv = 0;
    while (kv < k && !q.empty()) {
        path p = q.top();
        q.pop();
        if (visited[p.loc]) continue;
      //  cout << "Point " << p.loc+1 << endl;
        visited[p.loc] = true;
        if (p.loc < k) kv++, power[p.loc] = {p.min_e, p.dist};
        for (edge& e : graph[p.loc])
            if (!visited[e.dest]) q.push(path(e.dest, min(e.e, p.min_e), p.dist + e.dist));
    }
    return power;
}

vi solve() {
    int m;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int a, b, d, e;
        cin >> a >> b >> d >> e;
        a--, b--;
        graph[a].push_back(edge(b, d, e));
        graph[b].push_back(edge(a, d, e));
    }

    auto res = dijsktra();
    vi danger;
    int maxpower = 0, mindist = INT_MAX;
    for (int i = 0; i < k; i++) {
        if (res[i].first > maxpower) maxpower = res[i].first, mindist = INT_MAX, danger.clear();
        if (res[i].first == maxpower) {
            if (res[i].second < mindist) mindist = res[i].second, danger.clear();
            if (res[i].second == mindist) danger.push_back(i);
        }
    }
  //  cout << maxpower << ", " << mindist << endl;
    return danger;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        auto v = solve();
        cout << "Case #" << i << ": ";
        for (auto i : v) cout << i + 1 << " ";
        cout << endl;
        for (vector<edge>& v : graph) v.clear();
    }
    return 0;
}