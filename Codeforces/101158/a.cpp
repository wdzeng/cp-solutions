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
    int n;
    int m;
    cin >> n >> m;
    unordered_set<int> has;
    list<int> ls;
    while (m--) {
        int x;
        cin >> x;
        ls.push_front(x);
    }
    for (int i : ls) {
        if (!has.count(i)) cout << i << ' ', has.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!has.count(i)) cout << i << ' ';
    }
    cout << endl;
    return 0;
}
