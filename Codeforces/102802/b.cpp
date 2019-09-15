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

    clock_t t0 = clock();

    freopen("b.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;

    int val[n];
    unordered_map<int, int> v2i;
    for (int i = 0; i < n; i++) cin >> val[i];
    sort(val, val + n);
    for (int i = 0; i < n; i++) v2i[val[i]] = i;

    int mx = 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const int d = val[j] - val[i];
            int x = 2;
            while (v2i.count(val[i] + x * d)) {
                int k = v2i[val[i] + x * d];
                x++;
                mx = max(mx, x);
            }
        }
    }

    cout << mx << endl;

    clock_t t1 = clock();
    cout << (double)(t1-t0) / (CLOCKS_PER_SEC) * 1000 << "ms\n";
    return 0;
}