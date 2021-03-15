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

vector<int> vec;
int n;

pii solve(int l, int r) {
    static map<pii, pii> rec;
    if (rec.count({l, r})) return rec[{l, r}];
    if (l == r) return {0, 0};

    auto a = solve((l + 1) % n, r);
    if (vec[l]) a.y++;
    auto b = solve(l, (r - 1 + n) % n);
    if (vec[(r - 1 + n) % n]) b.y++;

    swap(a.x, a.y);
    swap(b.x, b.y);
    return rec[{l, r}] = max(a, b);
}

int main() {
    fastio();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        vec.push_back(val % 2);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto res = solve((i + 1) % n, i);
       
        if(vec[i]) res.y++;
        if (res.x < res.y) ans++;
    }
    cout << ans << endl;
    return 0;
}