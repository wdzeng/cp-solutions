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

double deg2rad(double d) { return d / 180 * PI; }

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    double g;
    cin >> n >> g;

    vector<pii> v;
    while (n--) {
        pii p;
        cin >> p.x >> p.y;
        v.push_back(p);
    }

    double e = 0;
    list<double> ans;
    while (!v.empty()) {
        double a = deg2rad(v.back().y);
        double d = v.back().x;
        double de = d * cos(a) * g;
        e += de;
        ans.push_front(sqrt(e * 2));
        v.pop_back();
    }

    
    for(double e: ans) printf("%.6f\n", e);
    return 0;
}