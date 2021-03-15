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
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    map<int, string> sol;
    for(int i=0; i<64; i++) {
        int ans= 4;
        int m = i;
        for(int _=0; _<3;_++) {
            switch(m & 3) {
                case 0: ans += 4;
                case 1: ans *= 4;
                case 2: ans /= 4;
                case 3: ans -= 4;
            }

            m >>=2;
        }
    }
    int q; cin >> q;
    while(q--)
    return 0;
}