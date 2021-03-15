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
    set<int> s;
    unordered_set<int> a;
    while (n--) {
        int v;
        cin >> v;
        a.insert(v);
        s.insert(v);
    }

    cin >> n;
    unordered_set<int> b;
    while (n--) {
        int v;
        cin >> v;
        b.insert(v);
        s.insert(v);
    }
    int aqq = 0, bqq = 0;
    int ans = 0;
    for (int i : s) {
        if (a.count(i) && b.count(i)) {
            aqq = bqq = 0;
            ans++;
        } else if (a.count(i)) {
            if (!bqq) {
                bqq = 1;
                ans++;
                aqq = 0;
            } 
        } else if (b.count(i)) {
            if (!aqq) {
                aqq = 1;
                ans++;
                bqq = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}