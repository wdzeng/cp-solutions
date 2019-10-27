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
    deque<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(iter(v));

    ll l = 0;
    for (int i = 0; i < n / 2; i++) l += v.front(), v.pop_front();
    ll r = 0;
    while (v.size()) r += v.back(), v.pop_back();

    cout << l*l+r*r << endl;
    return 0;
}
