#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

struct line {
    int l, r;
    bool operator<(const line& o) const {
        if (r == o.r) return l < o.l;
        return r < o.r;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<line> v(n);
    for (auto& p : v) cin >> p.l >> p.r;

    multiset<int> s;
    for (int i = 0; i < k; i++) s.insert(0);
    sort(all(v));

    int ans = 0;
    for (auto& p : v) {
        auto a = s.upper_bound(p.l);
        if (a == s.begin()) continue;
        a--;
        s.erase(a);
        s.insert(p.r);
        ans++;
    }
    cout << ans << endl;
    return 0;
}