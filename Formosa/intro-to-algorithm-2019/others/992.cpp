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

bool collide(pii& a, pii& b) {
    if (a.x == b.x || a.x == b.y || a.y == b.x || a.y == b.y) return 1;
    return 0;
}

bool solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<pii> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s.emplace_back(i, j);
        }
    }

    sort(iter(s), [&v](pii& i, pii& j) { return v[i.x] + v[i.y] < v[j.x] + v[j.y]; });

    int l = 0, r = s.size() - 1;
    while (l < r) {
        int sum = v[s[l].x] + v[s[l].y] + v[s[r].x] + v[s[r].y];
        if (sum == 0 && !collide(s[l], s[r])) return 1;
        if (sum < 0)
            l++;
        else
            r--;
    }
    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cout << solve() << endl;
    return 0;
}
