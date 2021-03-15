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
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

int main() {
    fastio();
    cout << 1 << endl << 628 << endl;
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'a')
            cout << "aa\naz\n";
        else if (c == 'z') {
            for (char j = 'a'; j <= 'z'; j++) {
                cout << 'z' << j << endl;
            }
        }
        else {
             for (char j = 'a'; j <= 'y'; j++) {
                cout << c << j << endl;
            }
        }
    }
    return 0;
}