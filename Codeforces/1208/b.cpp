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

int n;
vector<int> v;

bool check(int wipe) {
    unordered_map<int, int> m;
    for (int i = wipe; i < n; i++) m[v[i]]++;
    if (m.size() == n - wipe) return 1;

    for (int i = 0; i < n - wipe; i++) {
        m[v[i + wipe]]--;
        m[v[i]]++;
        if (m[v[i + wipe]] == 0) m.erase(v[i + wipe]);
        if (m.size() == n - wipe) return 1;
    }
    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}