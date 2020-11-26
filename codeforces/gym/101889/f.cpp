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
typedef pair<pii, ll> piii;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    vector<piii> P;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        P.push_back({{a, b}, w});
    }
    sort(all(P), [](const piii& a, const piii& b) {
        if (a.x.x != b.x.x) return a.x.x < b.x.x;
        return a.x.y > b.x.y;
    });

    vector<piii> tmp;
    for (auto& p : P) {
        if (!tmp.empty() && tmp.back().x == p.x)
            tmp.back().y += p.y;
        else
            tmp.push_back(p);
    }
    P.swap(tmp);

    map<int, ll> m = {{0, 0}};
    for (auto& p : P) {
        auto a = prev(m.lower_bound(p.x.y), 1);
        ll val = m[p.x.y] = max(m[p.x.y], a->y + p.y);
        while (1) {
            auto g = m.upper_bound(p.x.y);
            if (g == m.end() && g->y > val) break;
            m.erase(g);
        }
    }

    cout << m.rbegin()->y << endl;
    return 0;
}