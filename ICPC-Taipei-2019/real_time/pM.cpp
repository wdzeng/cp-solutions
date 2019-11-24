#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastpow(ll a, ll p, ll m) {
	ll ret = 1;
	while(p) {
		if(p&1) ret = ret*a%m;
		a=a*a%m, p>>=1;
	}
	return ret;
}

ll modinv(ll a, ll p) {
	if(p==1) return 0;
	ll pp=p, y=0, x=1;
	while(a>1) {
		ll q=a/p, t=p;
		p=a%p, a=t, t=y, y=x-q*y, x=t;
	}
	if(x<0) x+=pp;
	return x;
}

ll modinv(ll a, ll b, ll p) {
	ll ret = modinv(a, p);
	return ret * b %p;
}

int qstep(ll n, int d) {
	int all = n / d;
	int rem = n % d;
	ll ret = 1;
	for(int i=1;i<=rem;i++) {
		ret*=i; ret%=d;
	}
	ll bs = 1;
	for(int i=1;i<d;i++) {
		bs*= i; bs%=d;
	}
	ret *= fastpow(bs, all, d);
	ret %= d;
	return ret;
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	ll m, n; int d; cin >> m >> n >> d;	
	ll a = qstep(m, d), b = qstep(m-n, d), c = qstep(n, d);
	cout << a << b << c << endl;
	ll ans = modinv(b*c%d,a,d);
	cout << ans << endl;
	return 0;
}
