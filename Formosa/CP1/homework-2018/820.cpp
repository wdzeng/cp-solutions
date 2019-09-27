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

struct BigInt {
    static const int D = 9;
    static const ll M = 1e9;
    list<ll> val;

    BigInt() {}
    static list<ll> stobigint(string s) {
        list<ll> ret;
        while (!s.empty()) {
            string n;
            for (int i = 0; i < D && !s.empty(); i++) {
                n += s.back();
                s.pop_back();
            }
            reverse(iter(n));
            ret.push_front(stoll(n));
        }
        return ret;
    }
    static list<ll> mut(list<ll> a, ll b) {
        list<ll> ret;
        ll c = 0;
        while (!a.empty()) {
            ll p = a.back() * b + c;
            c = p / M;
            p %= M;
            ret.push_front(p);
            a.pop_back();
        }
        if(c) ret.push_front(c);
        return ret;
    }
    static void add(list<ll>& a, list<ll>& b) {
        list<ll> sum;
        ll c = 0;
        while (!a.empty() || !b.empty()) {
            ll x = a.empty() ? 0 : a.back();
            ll y = b.empty() ? 0 : b.back();
            ll s = x + y + c;
            c = s / M;
            s %= M;
            sum.push_front(s);
            if (!a.empty()) a.pop_back();
            if (!b.empty()) b.pop_back();
        }
        if(c) sum.push_front(c);
        a.swap(sum);
    }

    BigInt& operator+=(const string& s) {
        auto b = stobigint(s);
        add(val, b);
        clear();
    }

    BigInt& operator*=(const string& s) {
        list<ll> pdt;
        list<ll> a = val;
        list<ll> b = stobigint(s);
        while (!b.empty()) {
            list<ll> p = mut(a, b.back());
            add(pdt, p);
            a.push_back(0);
            b.pop_back();
        }
        val.swap(pdt);
        clear();
    }

    void clear() {
        while (!val.empty() && val.front() == 0) val.pop_front();
    }

    void output() const {
        if (val.empty()) {
            printf("0");
            return;
        }
        bool first = true;
        for (ll v : val) {
            if (first)
                printf("%lld", v);
            else
                printf("%09lld", v);
            first = false;
        }
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string line;
    while (getline(cin, line) && !line.empty()) {
        BigInt b;
        bool plus = true;
        string n;
        for (char c : line) {
            if (c == '+' || c == '*') {
                if (plus)
                    b += n;
                else
                    b *= n;
                plus = c == '+';
                n.clear();
            } else {
                n += c;
            }
        }
        if (plus)
            b += n;
        else
            b *= n;
        b.output();
        printf("\n");
    }
    return 0;
}