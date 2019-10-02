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

int solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    reverse(iter(v));
    stack<int> k;
    int ans = 0;
    for (int val : v) {
        while (!k.empty() && val > k.top()) k.pop();
        k.push(val);
        ans = max(ans, (int)k.size());
    }
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}