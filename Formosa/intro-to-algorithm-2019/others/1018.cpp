#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;

const int maxn = 1e5 + 10;
const ll inf = 1e18;
vector<pii> adj[maxn];
int N;

pii farthest(int src) {
    vector<ll> dist(N, inf);
    vector<int> k;
    k.push_back(src);
    dist[src] = 0;
    while (!k.empty()) {
        int v = k.back();
        k.pop_back();
        for (auto& a : adj[v]) {
            int e = a.first;
            ll d = a.second;
            if (dist[e] != inf) continue;
            dist[e] = dist[v] + d;
            k.push_back(e);
        }
    }

    auto far = max_element(dist.begin(), dist.end());
    int index = far - dist.begin();
    return pii(index, dist[index]);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N;
    ll pm = 0;
    for (int i = 0; i < N - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
        pm += w;
    }

    auto leaf = farthest(0);
    leaf = farthest(leaf.first);
    ll dm = leaf.second;

    cout << pm * 2 - dm << '\n';
    return 0;
}
