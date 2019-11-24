#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 15 + 2;

string s[maxn], t, z, o;

ll ans, cnt, T, n, m;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n >> m, ans = m + 1;
		z = o = "";
		for (int i = 0; i < n; i++)
			z.push_back('0'), o.push_back('1');
		for (int i = 0; i < m; i++)
			cin >> s[i];
		for (int i = 1; i < (1 << m); i++) {
			t = z, cnt = 0;
			for (int j = 0; j < m; j++) {
				if (i & (1 << j)) {
					cnt++;
					for (int k = 0; k < n; k++)
						if (t[k] == '1' || s[j][k] == '1')
							t[k] = '1';
						else
							t[k] = '0';
				}
			}
			if (t == o)
				ans = min(ans, cnt);
		}
		if (ans > m)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}
	return 0;
}
