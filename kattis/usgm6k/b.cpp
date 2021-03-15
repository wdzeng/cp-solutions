#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const ll X = 1e6 + 99;
const ll M = 1e9 + 7;
#define unordered_set set
ll rollhash(unordered_set<ll>& s) {
    ll ret = 9487;
    for (auto val : s) {
        ret = ret * X + val;
        ret %= M;
    }
    return ret;
}

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        vector<unordered_set<ll>> k;
        while (t--) {
            
            string op;
            cin >> op;
            if (op == "PUSH") {
                k.push_back({});
            } else if (op == "DUP") {
                k.push_back(k.back());
            } else if (op == "UNION") {
                auto a = k.back();
                k.pop_back();
                auto b = k.back();
                k.pop_back();
                a.insert(all(b));
                k.push_back(a);
            } else if (op == "INTERSECT") {
                auto a = k.back();
                k.pop_back();
                auto b = k.back();
                k.pop_back();
                unordered_set<ll> c;
                for (auto val : a)
                    if (b.count(val)) c.insert(val);
                k.push_back(c);
            } else if (op == "ADD") {
                auto a = k.back();
                k.pop_back();
                auto h = rollhash(a);
                k.back().insert(h);
            }
            
            cout << k.back().size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}