#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<int, vector<int>, greater<int>> pq;

ll ans, t, n, ai, x1, x2;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n, ans = 0;
		for (int i = 0; i < n; i++)
			cin >> ai, pq.push(ai);
		while (pq.size() > 1) {
			x1 = pq.top();
			pq.pop();
			x2 = pq.top();
			pq.pop();
			ans += (x1 + x2);
			pq.push(x1 + x2);
		}
		pq.pop(), cout << ans << '\n';
	}
	return 0;
}
