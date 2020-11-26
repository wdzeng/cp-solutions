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
    int n;
    cin >> n;

    int sum = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    vector<bool> ks(sum + 1, 0);
    ks[0] = 1;
    for (int i = 1; i <= n; i++) {
        int val = v[i - 1];
        vector<bool> u(sum + 1, 0);
        u[0] = 1;
        for (int j = 0; j <= sum; j++) {
            if (ks[j]) u[j] = u[j + val] = 1;
        }
        ks.swap(u);
    }

    ll psum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            psum += v[i] * v[j];
        }
    }

    ll mn = 1e18;
    for (int i = 0; i <= sum; i++) {
        if (!ks[i]) continue;
        int ga = i;
        int gb = sum - ga;
        ll p = ll(ga) * gb;
        ll n = psum - p;
        mn = min(mn, abs(n - p));
    }

    cout << mn << endl;
    return 0;
}