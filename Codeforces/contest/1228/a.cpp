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

bool check(int i) {
    unordered_set<int> s;
    while (i) {
        if (s.count(i % 10)) return false;
        s.insert(i % 10);
        i /= 10;
    }
    return 1;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int l;
    int r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        if (check(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}