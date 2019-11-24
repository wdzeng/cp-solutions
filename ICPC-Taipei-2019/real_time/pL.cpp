#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

typedef long long ll;
typedef pair<ll, ll> pii;
pii operator-(const pii &a, const pii &b) {
	return {a.x - b.x, a.y - b.y};
}
ll cross(const pii &a, const pii &b) {
	return a.x * b.y - a.y * b.x;
}
ll crossfrom(const pii &o, const pii &a, const pii &b) {
	return cross(a - o, b - o);
}
ll dd(const pii &a, const pii &b) {
	ll dx = a.x - b.x, dy = a.y - b.y;
	return dx * dx + dy * dy;
}

vector<pii> makepoly(vector<pii> &pp) {
	int n = pp.size();
	sort(pp.begin(), pp.end());
	vector<pii> ret;
	for (int i = 0; i < n; i++) {
		while (ret.size() >= 2 && crossfrom(ret[ret.size() - 2], ret.back(), pp[i]) <= 0)
			ret.pop_back();
		ret.push_back(pp[i]);
	}
	for (int i = n - 2, t = ret.size() + 1; i >= 0; i--) {
		while (ret.size() >= t && crossfrom(ret[ret.size() - 2], ret.back(), pp[i]) <= 0)
			ret.pop_back();
		ret.push_back(pp[i]);
	}
	if (n >= 2)
		ret.pop_back();
	return ret;
}

#define ii ((i + p) % n)
#define kk1 ((k1 + 1) % n)
#define kk2 ((k2 + 1) % n)

ll area(vector<pii> &poly) {
	int k1, k2, n = poly.size();
	ll ans = 0;
	for (int p = 2; p < n - 1; p++) {
		k1 = 1, k2 = (p + 1) % n;
		for (int i = 0; i < n; i++) {
			while (abs(crossfrom(poly[kk1], poly[i], poly[ii])) >= abs(crossfrom(poly[k1], poly[i], poly[ii])) && poly[kk1] != poly[ii])
				k1 = kk1;
			
			while (abs(crossfrom(poly[kk2], poly[i], poly[ii])) >= abs(crossfrom(poly[k2], poly[i], poly[ii])) && poly[kk2] != poly[ii])
				k2 = kk2;
			ans = max(ans, abs(crossfrom(poly[k1], poly[i], poly[ii])) + abs(crossfrom(poly[k2], poly[i], poly[ii])));
			// cout << poly[k1].x << ' ' << poly[k1].y << ' ' << poly[i].x << ' ' << poly[i].y << ' ' << poly[ii].x << ' ' << poly[ii].y << ' ' << abs(crossfrom(poly[k1], poly[i], poly[ii])) << '\n';
			// cout << poly[k2].x << ' ' << poly[k2].y << ' ' << poly[i].x << ' ' << poly[i].y << ' ' << poly[ii].x << ' ' << poly[ii].y << ' ' << abs(crossfrom(poly[k2], poly[i], poly[ii])) << "\n\n";
		}
	}
	return ans;
}

int t, n;

ll ans, tri, crt;

vector<pii> p, ch, ch2;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		set<pii> s;
		set<pii> ispointdulplicated;
		cin >> n, p.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
			if(s.count(p[i])) ispointdulplicated.insert(p[i]);
			else s.insert(p[i]);
		}
		vector<pii> pcopy(s.begin(), s.end());
		ch = makepoly(pcopy);
		if (ch.size() < 3)
			ans = 0;
		else if (ch.size() == 3) {
			ans = 0, tri = abs(crossfrom(ch[0], ch[1], ch[2]));
			for (int i = 0; i < n; i++)
				if (p[i] != ch[0] && p[i] != ch[1] && p[i] != ch[2]) {
					crt = tri - abs(crossfrom(p[i], ch[0], ch[1]));
					ans = max(ans, crt);
					crt = tri - abs(crossfrom(p[i], ch[1], ch[2]));
					ans = max(ans, crt);
					crt = tri - abs(crossfrom(p[i], ch[2], ch[0]));
				}
			for (auto ppp: ispointdulplicated) {
				crt = tri - abs(crossfrom(ppp, ch[0], ch[1]));
				ans = max(ans, crt);
				crt = tri - abs(crossfrom(ppp, ch[1], ch[2]));
				ans = max(ans, crt);
				crt = tri - abs(crossfrom(ppp, ch[2], ch[0]));
				ans = max(ans, crt);
			}
				
		} else
			ans = area(ch);
		cout << ans / 2;
		if (ans % 2)
			cout << ".5";
		cout << "\n";
		// cout << "!" << endl;
	}
	return 0;
}
/*
7
5
0 0
1 0
3 1
1 2
0 1
4
0 0
4 0
0 4
1 1
4
0 0
1 1
2 2
1 1
8
0 0
0 0
5 0
5 0
3 8
3 8
0 2
0 2
4
0 0
0 0
0 0
0 0
4
0 0
4 0
0 4
1 2
4
0 0
1 0
0 1
3 2

*/
