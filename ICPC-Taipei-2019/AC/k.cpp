#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll ai;
            cin >> ai;
            pq.push(ai);
        }
        while (pq.size() > 1) {
            ll x1 = pq.top();
            pq.pop();
            ll x2 = pq.top();
            pq.pop();
            ans += (x1 + x2);
            pq.push(x1 + x2);
        }
        cout << ans << '\n';
    }
    return 0;
}
