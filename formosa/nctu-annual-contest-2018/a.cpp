#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        int x, y;
        cin >> x >> y;
        if (x == y)
            cout << 2 << endl;
        else if (x == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
        return 0;
    }

    unordered_map<int, int> mmap;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mmap[x]++;
    }

    int ans = -1;
    for (auto& p : mmap) ans = max(ans, p.y);
    cout << max(ans, 2) << endl;
    return 0;
}