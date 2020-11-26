#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 2e5 + 5;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int& val : a) {
            cin >> val;
            val--;
        }
        int g = 0, c = 0;
        int vis[N];
        ms(vis);
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i] == i) continue;
            int c = 0;
            int x = i;
            while (!vis[x]) {
                vis[x] = 1;
                c++;
                x = a[x];
            }
            arr.push_back(c);
        }
        int ans = 0;
        for (int a : arr) ans += a - 1;
        cout << ans << '\n';
    }

    return 0;
}