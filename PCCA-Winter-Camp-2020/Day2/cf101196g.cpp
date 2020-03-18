#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

inline void foul() {
    cout << "No\n";
    exit(0);
}

inline void require_sorted(const deque<int>& v) {
    auto copy = v;
    sort(all(copy));
    reverse(all(copy));
    if (v != copy) foul();
}

ll solve(int rem, deque<int>& l, deque<int>& m, deque<int>& r) {
    if (rem == 0) return 0;
    if (!l.empty() and l.front() == rem) {
        l.pop_front();
        return solve(rem - 1, l, r, m) + (1ll << (rem - 1));
    }
    if (!r.empty() and r.front() == rem) {
        r.pop_front();
        return solve(rem - 1, m, l, r);
    }
    foul();
    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n = 0;
    deque<int> l, m, r;
    int c;
    cin >> c;
    n += c;
    while (c--) {
        int a;
        cin >> a;
        l.push_back(a);
    }
    require_sorted(l);
    cin >> c;
    n += c;
    while (c--) {
        int a;
        cin >> a;
        m.push_back(a);
    }
    require_sorted(m);
    cin >> c;
    n += c;
    while (c--) {
        int a;
        cin >> a;
        r.push_back(a);
    }
    require_sorted(r);

    cout << solve(n, l, m, r) << endl;
    return 0;
}