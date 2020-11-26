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

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (auto& val : a) cin >> val;
        for (auto& val : b) cin >> val;
        sort(all(a));
        sort(all(b));
        reverse(all(a));
        int ok = 1;
        for (int i = 0; i < n; i++)
            if (a[i] + b[i] > x) ok = 0;
        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}