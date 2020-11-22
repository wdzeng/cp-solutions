#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifndef hy
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#else
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#endif

inline int leap(int y) {
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    if (y % 4 == 0) return 1;
    return 0;
}

int mxd[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
    int y, m, d;
    int isvalid() const {
        if (m < 1 || m > 12 || d < 1 || y < 2000) return 0;
        if (m == 2) {
            if (leap(y)) return d <= 29;
            return d <= 28;
        } else {
            return d <= mxd[m];
        }
    }
    bool operator<(const date& o) const {
        if (y != o.y) return y < o.y;
        if (m != o.m) return m < o.m;
        return d < o.d;
    }
};

int main() {
    fastio();
    int t;
    cin >> t;
    date maxdate = {10000, 100, 100};
    while (t--) {
        int nans = 0;
        date ans = maxdate;
        vector<int> v;
        string a, b, c;
        cin >> a >> b >> c;
        for (char c : a) v.push_back(c - '0');
        for (char c : b) v.push_back(c - '0');
        for (char c : c) v.push_back(c - '0');
        sort(all(v));
        do {
            int y = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
            int m = v[4] * 10 + v[5];
            int d = v[6] * 10 + v[7];
            date dt = {y, m, d};
            if (dt.isvalid()) {
                ans = min(dt, ans);
                nans++;
            }
        } while (next_permutation(all(v)));
        if (!nans)
            printf("%d\n", nans);
        else {
            printf("%d %02d %02d %4d\n", nans, ans.d, ans.m, ans.y);
        }
    }
    return 0;
}