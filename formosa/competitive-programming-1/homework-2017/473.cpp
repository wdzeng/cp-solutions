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

vector<int> split(string& s) {
    vector<int> ret;
    int v = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i % 10 == 0)
            ret.push_back(v), v = 0;
        else
            v = v * 10 + (s[i] - '0');
    }
    return ret;
}

bool solve() {
    string s;
    getline(cin, s);
    if (s.empty()) return 0;
    assert((s.size() - 1) % 10 == 0);
    int n = (s.size() - 1) / 10;
    getline(cin, s);

    unordered_map<int, int> x, y;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        auto a = split(s);
        for (int j = 0; j < n; j++) /*cout << a[j] << ' ',*/ x[a[j]] = i, y[a[j]] = j;
        getline(cin, s);
    }

    int h[n], v[n]; ms(h), ms(v);
    int lh = 0, lv = 0;
    while (getline(cin, s) && s.size() && s.size() < 11) {
        int e = stoi(s);
       // cout << e << "!\n";
        if (!x.count(e)) continue;
        int xx = x[e], yy = y[e];
       // cout << xx << ' ' << yy << "@\n";
        if (++h[xx] == n) lh++;
        if (++v[yy] == n) lv++;
        cout << lh << ' ' << lv << endl;
    }
    return 1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    getline(cin, s);
    while (solve())
        ;
    return 0;
}