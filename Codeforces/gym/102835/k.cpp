#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())
#ifndef hy
#define endl '\n'
#endif

vector<ll> decpre, hexpre, fact;

void initdec() {
    decpre.push_back(10);
    ll num = 9;
    for (int i = 9; i >= 1; i--) {
        num *= i;
        decpre.push_back(decpre.back() + num);
    }
}
void inithex() {
    hexpre.push_back(16);
    ll num = 15;
    for (int i = 15; i >= 1; i--) {
        num *= i;
        hexpre.push_back(hexpre.back() + num);
    }
}
void initfact() {
    fact.push_back(1);
    for (int i = 1; i <= 16; i++) fact.push_back(fact.back() * i);
}

string ll2s(int base, ll val) {
    if (base == 10) return to_string(val);
    if (!val) return "0";
    string ret;
    while (val) {
        int d = val % 16;
        if (d < 10)
            ret.push_back(d + '0');
        else
            ret.push_back(d - 10 + 'a');
        val >>= 4;
    }
    reverse(all(ret));
    return ret;
}

ll s2ll(int base, const string& val) {
    if (base == 10) return stoull(val);
    ll ret = 0;
    for (char c : val) {
        int d;
        if ('0' <= c && c <= '9')
            d = c - '0';
        else
            d = c - 'a' + 10;
        ret = ret * 16 + d;
    }
    return ret;
}

ll kth(int base, ll k) {
    const auto& vecpre = base == 10 ? decpre : hexpre;
    auto a = lower_bound(all(vecpre), k);
    if (a == vecpre.end()) return -1;
    if (a == vecpre.begin()) return k - 1;
    int digit = a - vecpre.begin() + 1;
    k -= *(a - 1);
    k--;
    ll big = 1;
    for (int i = 0; i < digit - 1; i++) big *= (base - 1 - i);
    vector<ll> ret = {k / big + 1};
    k %= big;
    for (int i = 0; i < digit - 1; i++) {
        big /= (base - 1 - i);
        ret.push_back(k / big);
        k %= big;
    }
    assert(big == 1);
    assert(k == 0);
    assert(ret.size() == digit);

    vector<int> used(base);
    used[ret[0]] = 1;
    for (int i = 1; i < digit; i++) {
        int u = 0, j = 0;
        while (1) {
            if (!used[j]) {
                if (++u == ret[i] + 1) break;
            }
            j++;
        }
        ret[i] = j;
        used[j] = 1;
    }

    ll retnum = 0;
    for (auto val : ret) retnum = retnum * base + val;
    return retnum;
}

ll kthindex(int base, ll val) {
    if (val < 0) return 0;
    const auto& vecpre = base == 10 ? decpre : hexpre;
    //if (val > vecpre.back()) return vecpre.back();
    ll l = 1, r = vecpre.back();
    while (l <= r) {
        ll m = (l + r) >> 1;
        ll res = kth(base, m);
        if (res > val)
            r = m - 1;
        else
            l = m + 1;
    }
    return r;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    inithex();
    initdec();
    initfact();
    while (t--) {
        string d;
        cin >> d;
        int base = (d == "d" ? 10 : 16);

        int typ;
        cin >> typ;
        if (typ == 1) {
            string k;
            cin >> k;
            ll dk = s2ll(base, k);
            ll ans = kth(base, dk);
            if (ans == -1)
                cout << "-" << endl;
            else
                cout << ll2s(base, ans) << endl;
        } else {
            string a, b;
            cin >> a >> b;
            ll da = s2ll(base, a);
            ll db = s2ll(base, b);
            ll ans;
            if (da == 0)
                ans = kthindex(base, db);
            else
                ans = kthindex(base, db) - kthindex(base, da - 1);
            cout << ll2s(base, ans) << endl;
        }
    }

    return 0;
}