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

void inc(int i, int j, ll& v) {
    int loc = i * 3 + j;
    ll bits = v >> (loc * 2);
    bits &= 0b11;
    if (bits != 3) {
        v += 1 << (loc * 2);
    } else {
        v -= 3 << (loc * 2);
    }
}

int main() {
    fastio();
    ll src = 0;
    for (int i = 0; i < 9; i++) {
        ll v;
        cin >> v;
        src = (src << 2) | v;
    }
    if (src == 0) {
        cout << 0 << endl;
        return 0;
    }
    unordered_map<ll, int> s;
    s[src] = 0;
    queue<ll> q({src});
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ll v = u;
                inc(i, 0, v);
                inc(i, 1, v);
                inc(i, 2, v);
                if (i != 0) inc(0, j, v);
                if (i != 1) inc(1, j, v);
                if (i != 2) inc(2, j, v);

                if (v == 0) {
                    cout << s[u] + 1 << endl;
                    return 0;
                }
                if (!s.count(v)) {
                    s[v] = s[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}