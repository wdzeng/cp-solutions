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

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);

    int n, len;
    cin >> n >> len;
    int cand[n];
    for (int i = 0; i < n; i++) cin >> cand[i];

    set<pii> dp;
    for (int c : cand) {
        set<pii> u;
        for (auto& p : dp) {
            int sumlen = p.y + c;
            u.emplace(p.x + 1, sumlen);
        }
        dp.insert(iter(u));
        dp.emplace(1, c);
    }

    double maxq = -1;
    for (auto& c : dp) {
        // len - 2(5-q) = c.y - q*c.x + q
        // len - 10 + 2q = c.y - q*c.x + q
        // q(1+c.x) = c.y-len+10
        double q = double(c.y - len + 10) / (1 + c.x);
        // cout << c.x << ' ' << c.y << ' ' << q << endl;
        if (q < 0 || q > 5) continue;
        maxq = max(q, maxq);
    }

    if (maxq == -1)
        cout << "impossible\n";
    else
        cout << maxq << endl;
    return 0;
}