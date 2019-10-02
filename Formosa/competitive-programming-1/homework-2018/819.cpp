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
    static const int D = 18;
    static const ll M = 1e18;

    list<ll> val;
    bool neg = false;
    BigInt() {}

    list<ll> stobigint(string s) {
        list<ll> ret;
        while (!s.empty()) {
            string vs = "";
            for (int i = 0; i < D && !s.empty(); i++) {
                vs += s.back();
                s.pop_back();
            }
            reverse(iter(vs));
            ret.push_front(stoll(vs));
        }
        return ret;
    }

    BigInt& operator+=(const string& s) {
        list<ll> l = stobigint(s);
        list<ll> u;

        bool c = false;
        while (!l.empty() || !val.empty()) {
            ll vl = l.empty() ? 0 : l.back();
            ll vv = val.empty() ? 0 : val.back();
            u.push_front(vl + vv + c);

            c = u.front() >= M;
            if (c) u.front() -= M;
            if (!l.empty()) l.pop_back();
            if (!val.empty()) val.pop_back();
        }

        if (c) u.push_front(1);

        while (!u.empty() && u.front() == 0) {
            u.pop_front();
        }

        val.swap(u);
        return *this;
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
                printf("%018lld", v);
            first = false;
        }
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (1) {
        string line;
        getline(cin, line);
        if (line.empty()) break;
        BigInt b;
        stringstream ss(line);
        string s;
        while (ss >> s) {
            b += s;
        }
        b.output();
        printf("\n");
    }
    return 0;
}