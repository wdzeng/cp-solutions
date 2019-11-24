#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 50 + 5;

int n, a[maxn];

bool flag = true;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (i == j || j == k || k == i)
					continue;
				else
					flag &= ((a[i] - a[j]) % a[k] == 0);
	if (flag)
		cout << "yes\n";
	else
		cout << "no\n";
	return 0;
}
