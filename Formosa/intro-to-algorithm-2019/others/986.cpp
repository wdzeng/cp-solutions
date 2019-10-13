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
    priority_queue<int> q;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        q.push(-x);
    }

    int ans = 0;

    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push(a + b);
        ans -= (a + b);
        ans %= 524287;
    }

    cout << ans << endl;
    return 0;
}