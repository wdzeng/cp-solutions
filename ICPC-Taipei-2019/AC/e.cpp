#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void testb(ll b, ll l, ll k) {
	assert((b*l-b-k) % l ==0);
	ll s = (b*l-b-k) / l;
	deque<int> ans;
	while(s) {
		int p = min(1000000ll, s);
		ans.push_back(-p);
		s-=p;
	}
	ans.push_back(b);
	assert(ans.size() <= l);
	while(ans.size() < l) ans.push_front(0);
	cout << l << endl;
	for(int a: ans) cout << a << ' '; cout << endl;
}

ll testl(ll l, ll k) {
	int b = 1000000;
	while((b+k) % l !=0) {
		b--;
	}
	return b;
}

void findl(int minlen, ll k) {
	for(int l=1999; l>=minlen; l--) {
		ll b = testl(l, k);
		assert(b>0);
		if(b > 1000000) continue;
		testb(b, l, k);
		return;
	}
}

void solve() {
	int diff, minlen; cin >> diff >> minlen;
	if(minlen >= 2000) {
		cout << -1 << endl;
		return;
	}
	findl(minlen , diff);
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
