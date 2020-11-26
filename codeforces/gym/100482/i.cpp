#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))

vector<string> vec;
unordered_set<string> sset;

bool d1(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            if (++diff > 1) return false;
    }
    return true;
}

bool match(const string& s) {
    if(sset.count(s)) return true;
    int matched = 0;
    for (const string& m : vec) {
        if (d1(m, s))
            if (++matched > 1) return false;
    }
    return matched;
}

void solve() {
    vec.clear(), sset.clear();
    int n, q;
    cin >> n >> q;
    while(n--) {
        string s;
        cin >> s;
        vec.push_back(s), sset.insert(s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << (match(s) ? "yes" : "no") << endl;
    }
}

int main() {
   // cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}