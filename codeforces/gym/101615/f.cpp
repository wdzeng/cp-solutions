#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

struct frac {
    ll a, b;
    frac(ll a, ll b) {
        ll g = __gcd(a, b);
        a /= g;
        b /= g;
        if (b < 0) {
            a *= -1, b *= -1;
        }
        this->a = a, this->b = b;
    }
    frac operator+(const frac& f) const {
        return frac(a * f.b + b * f.a, b * f.b);
    }
    frac operator-(const frac& f) const {
        return frac(a * f.b - b * f.a, b * f.b);
    }
    frac operator*(const frac& f) const {
        return frac(a * f.a, b * f.b);
    }
    frac operator/(const frac& f) const {
        return frac(a * f.b, b * f.a);
    }
    bool operator==(const frac& f) const {
        return f.a * b == f.b * a;
    }
    frac pow2() const {
        return frac(a * a, b * b);
    }
};

ll det(ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h, ll i) {
    return (a * e * i + b * f * g + c * d * h) - (c * e * g + b * d * i + a * f * h);
}

pair<frac, frac> out(const pii& a, const pii& b, const pii& c) {
    ll xup = det(
        a.x * a.x + a.y * a.y, a.y, 1,
        b.x * b.x + b.y * b.y, b.y, 1,
        c.x * c.x + c.y * c.y, c.y, 1);

    ll yup = det(
        a.x, a.x * a.x + a.y * a.y, 1,
        b.x, b.x * b.x + b.y * b.y, 1,
        c.x, c.x * c.x + c.y * c.y, 1);

    ll down = det(
                  a.x, a.y, 1,
                  b.x, b.y, 1,
                  c.x, c.y, 1) *
              2;

    return pair<frac, frac>(
        frac(xup, down),
        frac(yup, down));
}

bool isline(pii a, pii b, pii c) {
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (b < c) swap(b, c);
    if (a.x == b.x || a.x == c.x) {
        if (a.x == b.x && b.x == c.x) return 1;
        return 0;
    }
    return frac(b.y - a.y, b.x - a.x) == frac(c.y - a.y, c.x - a.x);
}

frac dist(const pii& g, const pair<frac, frac>& f) {
    pair<frac, frac> h(
        frac(g.x, 1),
        frac(g.y, 1));
    return (f.x - h.x).pow2() + (f.y - h.y).pow2();
}

main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> vp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vp.emplace_back(x, y);
    }

    int maxcircle = 3;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isline(vp[i], vp[j], vp[k])) {
                } else {
                    pair<frac, frac> o = out(vp[i], vp[j], vp[k]);
                    int cc = 0;
                    frac d = dist(vp[i], o);
                    for (int a = 0; a < n; a++) {
                        if (dist(vp[a], o) == d) cc++;
                    }
                    maxcircle = max(maxcircle, cc);
                }
            }
        }
    }

    cout << max(1, n - maxcircle + 1) << endl;
    return 0;
}