#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    vector<ll> b;
    cin >> n;
    while (n--) {
        ll bb;
        cin >> bb;
        b.push_back(bb);
    }

    unordered_map<ll, ll> m;
    for (int i = 0; i < b.size(); i++) {
        b[i] -= i;
        m[b[i]] += b[i] + i;
    }

    ll ans = 0;
    for (auto& p : m) {
        ans = max(ans, p.y);
    }
    cout << ans << endl;

    return 0;
}