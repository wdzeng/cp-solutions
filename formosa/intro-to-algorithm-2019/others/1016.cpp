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
    deque<pii> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        q.emplace_back(d, s);
    }

    sort(iter(q), [](pii& a, pii& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });
    
    int t = 0;
    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (!q.empty()) {
        t++;
        while (!q.empty() and q.front().x < t) {
            int s = q.front().y;
            if (!pq.empty() and pq.top() < s) {
                ans -= pq.top();
                ans += s;
                pq.pop();
                pq.push(s);
            }
            q.pop_front();
        }
        if (!q.empty() and q.front().x >= t) {
            int s = q.front().y;
            q.pop_front();
            pq.push(s);
            ans += s;
        }
    }
    cout << ans << '\n';
    return 0;
}
