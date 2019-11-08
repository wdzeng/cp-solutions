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

const int x1 = 1e6 + 99, x2 = 2e6 + 3;
const int m1 = 1e9 + 7, m2 = 1e9 + 87;

string a, b;
bool judge(int len) {
    unordered_set<int> s1, s2;
    vector<int> freq(26);
    for (int i = 0; i < len; i++) freq[a[i] - 'a']++;
    for (int i = 0; i + len <= a.size(); i++) {
        ll h1 = 0, h2 = 0;
        for (int f : freq) h1 = (h1 * x1 + f) % m1, h2 = (h2 * x2 + f) % m2;
        s1.insert(h1), s2.insert(h2);
        if (i + len < a.size()) freq[a[i] - 'a']--, freq[a[i + len] - 'a']++;
    }

    freq.assign(26, 0);
    for (int i = 0; i < len; i++) freq[b[i] - 'a']++;
    for (int i = 0; i + len <= b.size(); i++) {
        ll h1 = 0, h2 = 0;
        for (int f : freq) h1 = (h1 * x1 + f) % m1, h2 = (h2 * x2 + f) % m2;
        if (s1.count(h1) && s2.count(h2)) return 1;
        if (i + len < b.size()) freq[b[i] - 'a']--, freq[b[i + len] - 'a']++;
    }
    return 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> a >> b;
    for (int len = min(a.size(), b.size()); len > 0; len--) {
        if (judge(len)) {
            cout << len << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
