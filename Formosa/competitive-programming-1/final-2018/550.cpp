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
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        s.insert(v);
    }
    if (s.size() < n) {
        cout << 0 << endl;
        return 0;
    }

    const int sum = 5e5 + 10;
    vector<bool> diff(sum), good(sum);

    for (int v : s) {
        vector<bool> d(sum);
        for (int i = 0; i < sum; i++) {
            if (!diff[i]) continue;
            d[i] = d[i + v] = d[abs(i - v)] = 1;
            good[i + v] = good[abs(i - v)] = 1;
        }
        diff.swap(d);
        diff[v] = 1;
        if(diff[0] and good[0]) cout << 0 << endl, exit(0);
    }

    for (int i = 0; i < sum; i++) {
        if (diff[i] and good[i]) cout << i << endl, exit(0);
    }
    assert(0);
    return 0;
}
