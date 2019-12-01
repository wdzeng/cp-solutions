#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int h;
int full;

int feb(int i) {
    switch (i) {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 5;
    case 5:
        return 8;
    case 6:
        return 13;
    case 7:
        return 21;
    case 8:
        return 34;
    }
    assert(0);
}

int revmask(int m) {
    int ret = 0;
    for (int i = 0; i < h; i++) {
        ret <<= 1;
        ret |= (1 - (m & 1));
        m >>= 1;
    }
    return ret;
}

const ll mod = 1e9;
map<pair<ll, pii>, ll> rec;
ll cal(ll w, int lm, int rm) {
    if (w == 0) {
        ll ret = 1;
        for (int i = 0; i < h; i++) {
            if ((lm & 1) and (rm & 1)) ret *= 2;
            lm >>= 1, rm >>= 1;
        }
        return ret;
    }
    auto k = mp(w, mp(lm, rm));
    if (rec.count(k)) return rec[k];
    if (w == 1) {
        ll ret = 1;
        int cont = 0;
        for (int i = 0; i < h; i++) {
            if ((lm & 1) and (rm & 1)) return 0;
            if ((lm & 1) or (rm & 1)) {
                ret *= feb(cont);
                cont = 0;
            } else
                cont++;
            lm >>= 1, rm >>= 1;
        }
        ret *= feb(cont);
        printf("%lld %d %d -> %lld\n", w, k.y.x, k.y.y, ret);
        return rec[k] = ret;
    }
    int w1 = w / 2, w2 = w - w1 - 1;
    ll ret = 0;
    for (int m = 0; m <= full; m++) {
        ret += cal(w1, lm, m) * cal(w2, revmask(m), rm);
        cout << "+" << cal(w1, lm, m) * cal(w2, revmask(m), rm) << endl;
        ret %= mod;
    }
    printf("%lld %d %d -> %lld\n", w, lm, rm, ret);
    return rec[k] = ret;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    ll w;
    cin >> h >> w;
    full = (1 << h) - 1;
    cout << cal(w, 0, 0) << endl;
    return 0;
}
