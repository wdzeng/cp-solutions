#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

inline int sign(ll val) {
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

inline bool bad(const vector<ll> v, int a, int b) {
    if (a == -1 or b == -1) return false;
    bool even = (a - b) % 2 == 0;
    return (sign(v[a]) == sign(v[b])) != even;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int n;
    ll c, r;
    cin >> n >> c >> r;
    vector<ll> v(n);
    for (auto& val : v) cin >> val;

    int nr = 0;
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0)
            nr++;
        else {
            if (p != -1 and sign(v[i]) == sign(v[p]))
                nr++;
            else
                p = i;
        }
    }
    ll ans = nr * r;

    p = -1;
    int prv[n], nxt[n];
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) continue;
        if (p != -1) nxt[p] = i;
        prv[i] = p;
        p = i;
    }
    if (p != -1) nxt[p] = -1;

    vector<pair<ll, int>> vs;
    for (int i = 0; i < n; i++) vs.emplace_back(abs(v[i]), i);
    sort(all(vs));

    nr = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) continue;
        nr += bad(v, i, prv[i]);
    }
    ans = min(ans, nr * r + c);

    for (auto& p : vs) {
        int index = p.y;
        ll fake = p.x + 1;
        if (fake == 1) continue;
        int pindex = prv[index];
        int nindex = nxt[index];

        if (pindex == -1) {
            if (nindex != -1) {
                if (bad(v, index, nindex)) nr--;
                prv[nindex] = -1;
            }
        } //
        else if (nindex == -1) {
            if (bad(v, index, pindex)) nr--;
            nxt[pindex] = -1;
        } //
        else {
            if (bad(v, index, pindex)) nr--;
            if (bad(v, index, nindex)) nr--;
            if (bad(v, nindex, pindex)) nr++;
            prv[nindex] = pindex;
            nxt[pindex] = nindex;
        }
        ans = min(ans, fake * c + nr * r);
    }

    cout << ans << endl;

    return 0;
}