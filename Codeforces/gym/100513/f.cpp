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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if (n <= 2 * k) {
        int sum = 0, x;
        while (n--) {
            cin >> x;
            sum += x;
        }
        cout << sum << endl;
        return 0;
    }

    priority_queue<int> q;
    vector<int> sum;
    list<int> element;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
        element.push_back(x);
        if (element.size() > k) {
            s -= element.front();
            element.pop_front();
        }
        sum.push_back(s);
    }

    int ans = 0;
    for (int i = 2 * k - 1; i < n; i++) {
        q.push(sum[i - k]);
        ans = max(sum[i] + q.top(), ans);
    }
    cout << ans << endl;
    return 0;
}