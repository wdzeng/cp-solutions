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
    int q;
    cin >> q;
    while (q--) {
        int n, t;
        cin >> n >> t;
        string str;
        cin >> str;
        int l0 = n, l1 = n, r0 = -1, r1 = -1;
        for(int i=0; i<n; i++ )if(str[i] == '0') r0 = i; else r1 = i;
        for(int i=n-1; i>=0; i-- )if(str[i] == '0') l0 = i; else l1 = i;
        while(t--) {
            int l, r; cin >> l >> r;
            l--, r--;
            int okl = 1, okr = 1;
            if(str[l] == '0' && l0 >= l) okl =0;
            if(str[l] == '1' && l1 >= l) okl =0;
            if(str[r] == '0' && r0 <= r) okr =0;
            if(str[r] == '1' && r1 <= r) okr =0;
            cout << ((okl || okr) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}