#pragma GCC optimization("Ofast", "unroll-loops")
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
    for (int i = 0; i < n; i++) cin >> v[i];

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
    int f = -1;
    vector<int> prv(n), nxt(n);
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) continue;
        if (p != -1) nxt[p] = i;
        prv[i] = p;
        p = i;
        if (f == -1) f = i;
    }
    if (p != -1) nxt[p] = -1;
    int l = p;

    if (f == -1) {
        cout << min(r * n, c) << endl;
        return 0;
    }

    nr = 0;
    for (int i = nxt[f]; i != -1; i = nxt[i]) {
        assert(i >= 0 and i < n);
        nr += bad(v, i, prv[i]);
    }
    ans = min(ans, nr * r + c);

    vector<pair<ll, int>> vs;
    for (int i = 0; i < n; i++) {
        if (v[i] != 0) vs.emplace_back(abs(v[i]), i);
    }
    sort(all(vs));

    for (const auto& p : vs) {
        int index = p.y;
        ll fake = p.x + 1;
        int pindex = prv[index];
        int nindex = nxt[index];
        assert(index >= 0 and index < n);

        if (pindex == -1) {
            if (nindex != -1) {
                if (bad(v, index, nindex)) nr--;
                prv[nindex] = -1;
            }
        }  //
        else if (nindex == -1) {
            if (bad(v, index, pindex)) nr--;
            nxt[pindex] = -1;
        }  //
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