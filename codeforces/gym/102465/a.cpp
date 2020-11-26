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
#endif

const int N = 1e6 + 5;
int down[N];
int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int n;
    cin >> n;
    int t;
    cin >> t;
    int maxans = 0;
    while (t--) {
        int x;
        cin >> x;
        for (int i = x; i <= n; i += x) down[i] = !down[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += down[i];
        maxans = max(ans, maxans);
    }
    cout << maxans << endl;

    return 0;
}