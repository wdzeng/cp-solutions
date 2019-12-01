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

int nday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
    int m, d;
    date(int m, int d) : m(m), d(d) {}
    int operator-(const date& o) {
        int ret = 0;
        int mm = m;
        while (o.m != mm) {
            mm = (mm - 1 + 12) % 12;
            ret += nday[mm];
        }
        ret += d - o.d;
        if (ret < 0) ret += 365;
        return ret;
    }
    bool operator<(const date& b) {
        if (m == b.m) return d < b.d;
        return m < b.m;
    }
    bool operator--() {
        d--;
        if (d < 1) {
            m = (m - 1 + 12) % 12;
            d = nday[m];
        }
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<date> vec;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> s;
        int idx = s.find_first_of('-');
        int m = stoi(s.substr(0, idx));
        int d = stoi(s.substr(idx + 1));
        m--;  //, d--;
        vec.emplace_back(m, d);
    }

    sort(iter(vec));

    int mx = 0;
    vector<date> cand;
    for (int i = 0; i < n; i++) {
        int diff = vec[i] - vec[(i - 1 + n) % n];
        if (diff > mx) {
            mx = diff;
            cand.clear();
        }
        if (diff == mx) {
            date d = vec[i];
            --d;
            cand.push_back(d);
        }
    }

    date today(9, 28);
    date ans = *min_element(iter(cand), [&](date& a, date& b) { return (a - today) < (b - today); });

    printf("%02d-%02d\n", ans.m + 1, ans.d);
    return 0;
}