#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

const int maxn = 5e5 + 10;
vector<vector<pii>> adj;
int k;

pii dfs(int v, int d) {
    vector<ll> cand;
    ll s = 0;
    for (auto& a : adj[v]) {
        if (a.x == d) continue;
        auto res = dfs(a.x, v);
        s += res.y;
        ll benefit = a.y + res.x - res.y;
        if (benefit > 0) cand.push_back(benefit);
    }

    ll linkme = s;
    sort(iter(cand), greater<ll>());
    for (int i = 0; i < k - 1 && i < cand.size(); i++) {
        linkme += cand[i];
    }

    ll notlinkme = s;
    for (int i = 0; i < k && i < cand.size(); i++) {
        notlinkme += cand[i];
    }
    return mp(linkme, notlinkme);
}

ll solve() {
    int n;
    cin >> n >> k;
    adj.assign(n, vector<pii>());
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    auto ans = dfs(0, -1);
    return max(ans.x, ans.y);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) cout << solve() << '\n';
    return 0;
}