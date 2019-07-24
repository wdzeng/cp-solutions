#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// AC
class frac {
   private:
    ll num, den;
    void refresh() {
        ll g = __gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) {
            num *= -1;
            den *= -1;
        }
    }

   public:
    frac(ll num, ll den) : num(num), den(den) { refresh(); }
    frac(ll num) : num(num), den(1) {}
    frac operator!() { return frac(den, num); }
    frac operator+(const frac& f) { return frac(num * f.den + den * f.num, den * f.den); }
    frac operator-(const frac& f) { return frac(num * f.den - den * f.num, den * f.den); }
    frac operator*(const frac& f) { return frac(num * f.num, den * f.den); }
    frac operator/(const frac& f) { return frac(num * f.den, den * f.num); }
    frac& operator-=(ll i) {
        num -= den * i;
        refresh();
        return *this;
    }
    ll base() { return floor((double)num / den); }
    bool operator!=(ll i) { return num != i || den != 1; }
};

frac build(vector<int>& v, int index = 0) {
    if (index == v.size() - 1) return frac(v[index]);
    return frac(v[index]) + !build(v, index + 1);
}

vector<ll> expand(frac f) {
    vector<ll> ret;
    ll i = f.base();
    ret.push_back(i);
    f -= i;
    while (f != 0) {
        f = !f;
        ll i = f.base();
        ret.push_back(i);
        f -= i;
    }
    return ret;
}

void solve(int t, int na, int nb) {
    vector<int> va(na), vb(nb);
    for (int i = 0; i < na; i++) cin >> va[i];
    for (int i = 0; i < nb; i++) cin >> vb[i];

    frac fa = build(va);
    frac fb = build(vb);
    printf("Case %d:\n", t);
    for (ll x : expand(fa + fb)) cout << x << " ";
    cout << endl;
    for (ll x : expand(fa - fb)) cout << x << " ";
    cout << endl;
    for (ll x : expand(fa * fb)) cout << x << " ";
    cout << endl;
    for (ll x : expand(fa / fb)) cout << x << " ";
    cout << endl;
}

int main() {
    int t = 0;
    int na, nb;
    while (cin >> na >> nb && na && nb) {
        t++;
        solve(t, na, nb);
    }
    return 0;
}