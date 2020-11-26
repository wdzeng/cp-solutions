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

int solve() {
    int n;
    cin >> n;
    deque<pair<char, int>> q;
    while (n--) {
        char c;
        int i;
        cin >> c >> i;
        q.emplace_back(c, i);
    }

    deque<pair<char, int>> d;
    while (q.size()) {
        auto a = q.front();
        q.pop_front();
        int put = a.y / 3;
        if (put) {
            if (q.size() && q.back().x == a.x)
                q.back().y += put;
            else
                q.emplace_back(a.x, put);
        }

        int tail = a.y % 3;
        if (tail)
            d.emplace_back(a.x, tail);
        else {
            if (q.size() && d.size() && q.front().x == d.back().x) {
                q.front().y += d.back().y;
                d.pop_back();
            }
        }
    }

    ll ans = 0;
    for (auto& p : d) ans += p.y;
    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}
