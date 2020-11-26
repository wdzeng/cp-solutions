#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

void solve() {
    ll f, e;
    cin >> f >> e;

    vector<pii> evs;
    for (int i = 0; i < e; i++) {
        ll m, r;
        cin >> r >> m;
        while (r < f) {
            evs.emplace_back(r, i);
            r += m;
        }
    }

    evs.emplace_back(0, e++);
    evs.emplace_back(f - 1, e++);
    sort(all(evs));

    ll dist[e][e];
    memset(dist, 1, sizeof(dist));
    for (int i = 0; i < e; i++) dist[i][i] = 0;
    for (int i = 1; i < evs.size(); i++) {
        ll d = evs[i].x - evs[i - 1].x;
        int a = evs[i].y;
        int b = evs[i - 1].y;
        dist[a][b] = min(dist[a][b], d);
        dist[b][a] = dist[a][b];
    }

    for (int i = 0; i < e; i++)
        for (int j = 0; j < e; j++)
            for (int k = 0; k < e; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

    ll maxans = 0;
    ll minf = 0;
    for (int i = 1; i < evs.size(); i++) {
        ll fd = evs[i - 1].x;
        ll fu = evs[i].x;
        ll cd = dist[e - 2][evs[i - 1].y];
        ll cu = dist[e - 2][evs[i].y];
        ll fm = (fu + fd + cu - cd) / 2;
        ll cm = cd + fm - fd;
        if (fm < fd or fm > fu) continue;
        if (cm > maxans) {
            maxans = cm;
            minf = fm;
        }
    }

    cout << maxans << ' ' << minf << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}