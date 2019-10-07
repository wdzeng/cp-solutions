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
    // cin.tie(0), ios::sync_with_stdio(0);
    int n, s, f, c;
    cin >> n >> s >> f >> c;
    vector<int> ff;
    int cold = 0;
    for (int i = 0; i < f; i++) {
        int x;
        cin >> x;
        ff.push_back(x);
        cold += x;
    }
    if (cold < s) {
        cout << "impossible\n";
        return 0;
    }

    deque<int> ind;
    for (int i = 0; i < f; i++) ind.push_back(i);
    sort(iter(ind), [&](int i, int j) { return ff[i] < ff[j]; });
    vector<int> ans(f);

    while (n) {
        int id = ind.front();
        ind.pop_front();
        int rem = c - ff[id];
        int putted = min(rem, n);
        n -= putted;
        ans[id] = putted;
    }

    cold = 0;
    for (int i = 0; i < f; i++) {
        if (ans[i]) continue;
        cold += ff[i];
    }
    if (cold < s) {
        cout << "impossible\n";
        return 0;
    }

    for (int a : ans) cout << a << ' ';
    cout << endl;
    return 0;
}