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

vector<int> a = {2, 3, 5, 7, 11, 13, 17, 19};

int main() {
    fastio();
    vector<int> b(8);
    for (int i = 0; i < 8; i++) cin >> b[i];
    int ans = 0;
    while (1) {
        b[0]++;
        ans++;
        for (int i = 0; i < 8; i++) {
            if (b[i] == a[i]) {
                if(i==7) {
                    cout << ans - 1 << endl;
                    return 0;
                }
                b[i] = 0, b[i + 1] ++;
            }
            else {
                break;
            }
        }
    }
    return 0;
}