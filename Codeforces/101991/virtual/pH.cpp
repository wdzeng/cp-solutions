#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, v, l, r, X,Y, M;

int modinv(ll a, ll m) {
    if(m==1) return 0;
    ll m0=m, y=0, x=1;
    while(a>1) {
        ll q = a/m, t = m;
        m=a%m, a=t, t=y;
        y=x-q*y;
        x=t;
    }
    x=(x%m0+m0)%m0;
    // if(x<0) x+=m0;
    return x;
}

void solve() {
    ll h = -1;
    int c = 0;
    int revx=modinv(X,M);
    vector<bool> vis(M);
    for(int i=0;i<N;i++) {
        if(h==-1) h = v;
        else {
            ll r = (h-Y+M)%M;
            h=r*revx%M;
            // h=h*r%M;
        }
        if(vis[h]) break;
        // cout << h << ' ';
        if(l<=h&&h<=r) c++;
        vis[h]=1;
    }
  //  cout << endl;
    int len = r-l+1;
    int g = __gcd(len,c);
    len/=g, c/=g;
    cout << c << '/' << len << '\n';
}

int main() {
    freopen("hawawshi.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0); 
    int t; cin >> t;
    while(t--) {
         cin >> N >> v >> l >> r >> X >> Y >> M;
        solve();
    }
    return 0;
}
