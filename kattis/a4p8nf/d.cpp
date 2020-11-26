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
    int a, b, c; cin >> a >> b >> c;
    a+=b;
    int ans = 0;
    while(a>=c) {
        a-=c;
        a++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}