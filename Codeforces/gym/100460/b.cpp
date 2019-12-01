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
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        b.push_back(v);
    }
    vector<int> o;
    for (int i = 0; i < n; i++) o.push_back(i);
    sort(iter(o), [&](int i, int j) { return a[i] < a[j]; });
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += b[o[i]];
        if (s >= a[o[i]]) {
            cout << "Redemption\n";
            return 0;
        }
    }
    cout << "Dire victory\n";
    return 0;
}
