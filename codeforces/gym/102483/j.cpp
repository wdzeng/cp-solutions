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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    ll me;
    cin >> me;
    ll init = me;
    map<ll, int> m;
    for (int i = 1; i < n; i++) {
        ll val;
        cin >> val;
        m[val]++;
    }
    vector<pair<ll, int>> rec(all(m));

    while (1) {
        ll h1 = rec.back().x;
        int p1 = rec.back().y;
        if (h1 == me && p1 > 1) break;

        if (rec.size() == 1) {
        }

        ll step = __lg(p1) + 1;
        ll r;
        if (rec.size() == 1) {
            assert(step > 1);
            r = (me - h1) / (step - 1);
        } else if (step == 1)
            r = h1 - rec[rec.size() - 2].x;
        else
            r = min(h1 - rec[rec.size() - 2].x, (me - h1) / (step - 1));
        if (!r) break;

        rec.back().x -= r;
        me -= step * r;
        if (rec.size() > 1 && rec.back().x == rec[rec.size() - 2].x) {
            rec.pop_back();
            rec.back().y += p1;
        }
    }
    while (1) {
        ll h1 = rec.back().x;
        int &p1 = rec.back().y;
        if (me == h1 && p1 > 1) break;
        if (rec.size() == 1) {
            int del = (p1 + 1) >> 1;
            p1 -= del;
            if (!p1) rec.pop_back();
            rec.emplace(rec.begin(), h1 - 1, del);
        }  //
        else {
            ll h2 = rec[rec.size() - 2].x;
            int &p2 = rec[rec.size() - 2].y;
            int del = (p1 + 1) >> 1;
            p1 -= del;
            if (!p1) rec.pop_back();
            p2 += del;
        }
        me--;
    }

    cout << init - me << endl;
    return 0;
}