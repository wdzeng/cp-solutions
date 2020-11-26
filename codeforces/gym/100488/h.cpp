#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int iceil(int x, int y) { return (x - 1) / y + 1; }

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int l = 2, r = *max_element(a, a + n) + 1;
    while (l < r) {
        int max_reward = (l + r) / 2;
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < max_reward) continue;
            int cc = (a[i] - max_reward) / b[i] + 1;
            cost += cc;
        }
        if (cost > m)
            l = max_reward + 1;
        else
            r = max_reward;
    }

    ll income = 0;
    if (l != r) throw "";
    int max_reward = r;
    for (int i = 0; i < n; i++) {
        if (a[i] < max_reward) continue;
        int cc = (a[i] - max_reward) / b[i] + 1;
        int rem = a[i] - (cc - 1) * b[i];
        income += ll(a[i] + rem) * cc / 2;
        m -= cc;
        a[i] = max(1, rem - b[i]);
    }
    income += ll(m) * *max_element(a, a + n);
    cout << income << endl;
    return 0;
}