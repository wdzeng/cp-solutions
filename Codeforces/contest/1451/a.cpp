#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#else
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#endif

int main() {
    fastio();
    int q; cin >> q; while(q--) {
        int n ; cin >> n;
        if(n==1) cout << 0 << endl;
        else if(n==2) cout << 1 << endl;
        else if(n==3) cout << 2 << endl;
        else if(n%2) cout << 3 << endl;
        else cout << 2 << endl;
    }
    return 0;
}