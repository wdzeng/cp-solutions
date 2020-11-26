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

class BIT {
   private:
    int n;
    vector<ll> a;

    ll sum(int i) {
        ll r = 0;
        while (i > 0) assert(0 <= i && i < a.size()), r += a[i], i -= i & -i;
        return r;
    }

   public:
    BIT(int n) : n(n) { a.resize(n + 1); }
    void add(int i, ll q) {
        while (i <= n) assert(0 <= i && i < a.size()), a[i] += q, i += i & -i;
    }
    ll sum(int l, int r) {
        if (r < l) return 0;
        return sum(r) - sum(l - 1);
    }
};

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);

    int n;
    cin >> n;
    deque<pii> q;
    BIT b(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q.emplace_back(x, i);
        b.add(i, 1);
    }
    sort(iter(q));

    ll ans = 0;
    while (!q.empty()) {
        int val = -1;
        vector<int> v;
        while (!q.empty() && (val == -1 || q.front().x == val)) {
            v.push_back(q.front().y);
            val = q.front().x;
            q.pop_front();
        }

        for (int i : v) {
            b.add(i, -1);
        }

        for (int i : v) {
            int l = b.sum(1, i - 1);
            int r = b.sum(i + 1, n);
            ans += min(l, r);
        }
    }

    cout << ans << endl;
    return 0;
}