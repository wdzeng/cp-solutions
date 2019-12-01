#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10;

pair<int, int> a[maxn];

int t, n, k;

long long ans;

vector<long long> v;

int main() {
    // cin.tie(0), ios::sync_with_stdio(0); 
    freopen("icecream.in", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i].first;
        for (int i = 0; i < n; i++)
            cin >> a[i].second;
        sort(a, a + n);
        ans = 0, v.clear();
        for (int i = 0; i < n && a[i].first <= a[k - 1].first; i++)
            v.push_back(-a[i].second);
        sort(v.begin(), v.end());
        for (int i = 0; i < k; i++)
            ans += -v[i];
        cout << a[k - 1].first << ' ' << ans << '\n';
    }
    return 0;
}
