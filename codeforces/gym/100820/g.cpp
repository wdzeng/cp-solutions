#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const double Q = sqrt(0.5);

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll n, r, v, w;
    cin >> n >> r >> v >> w;
    vector<pii> gems(n);

    for (auto& p : gems) {
        double x, y;
        cin >> x >> y;
        x *= r;
        p.x = (x + y) * Q;
        p.y = (-x + y) * Q;
    }

    sort(all(gems));
    vector<double> lis;

    for (auto& p : gems) {
        double y = p.y;
        auto a = upper_bound(all(lis), y);
        if (a == lis.end())
            lis.push_back(y);
        else
            *a = y;
    }

    cout << lis.size() << endl;

    return 0;
}