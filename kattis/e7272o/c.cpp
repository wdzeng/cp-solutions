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
    int n;
    cin >> n;
    string sn = to_string(n);
    multiset<char> mcs(all(sn));
    for(int i=n+1; i<1000000; i++) {
        string si = to_string(i);
        multiset<char> msi(all(si));
        if(mcs == msi) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}