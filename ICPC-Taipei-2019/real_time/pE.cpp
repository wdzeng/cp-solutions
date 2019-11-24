#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, k, L, a, b, s;

bool flag;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> k >> L, flag = false;
		for (int l = max(L, 4LL); l < 2000 && !flag; l++) {
			// cout << l << endl;
			for (a = l - (k % l), s = (k + a) / l; a <= 1e6 && !flag; a += l, s++) {
				b = s - 2 * a + 1;
				if (a + b < 0 && a > 0 && abs(b) <= 1e6) {
					cout << l << '\n';
					cout << a << ' ' << b;
					for (int i = 0; i < l - 4; i++)
						cout << " 0";
					cout << " -1 " << a << '\n';
					flag = true;
					break;
				}
			}
		}
		if (!flag)
			cout << "-1\n";
	}
	return 0;
}
