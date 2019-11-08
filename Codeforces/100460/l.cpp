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
    int e, p;
    cin >> e >> p;
    vector<pair<int, vector<int>>> ee;
    while (e--) {
        vector<int> par;
        int pp;
        int x;
        cin >> pp >> x;
        while (pp--) {
            int a;
            cin >> a;
            a--;
            par.push_back(a);
        }
        ee.emplace_back(x, par);
    }

    sort(iter(ee));
    vector<int> ans(p, 2e9);
    for (auto& ev : ee) {
        int x = ev.x;
        auto& par = ev.y;
        bool safe = 0;
        for (int pa : par) {
            if (ans[pa] < x) continue;
            ans[pa] = x;
            safe = 1;
        }
        if(!safe) {cout << "Poor memory\n"; return 0;}
    }
    cout << "Good memory\n";
    for (int a : ans) cout << min(a, (int)1e9) << ' ';
    cout << endl;
    return 0;
}
