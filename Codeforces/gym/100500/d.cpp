#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()

ll solve() {
    int n, d, c;
    cin >> n >> d >> c;
    vi v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x * c);
    }
    sort(iter(v), greater<int>());

    ll ans = d * n;
    for (int i = 0; i < n; i++) {
        ans = min((ll)d * i + (ll)v[i] * (n - i), ans);
    }
    return ans;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case %d: %lld\n", i, solve());
    }
    return 0;
}