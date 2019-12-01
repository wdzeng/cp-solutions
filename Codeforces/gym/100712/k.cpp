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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> vec;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        sort(iter(vec));
        int i = 0, j = n - 1;
        while (i < j) {
            ll p = vec[i] * vec[j];
            if (p == k) break;
            if (p > k)
                j--;
            else
                i++;
        }
        if (i < j) {
            cout << vec[i] << ' ' << vec[j] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}