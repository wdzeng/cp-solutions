#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
 
string solve() {
    int n;
    cin >> n;
    vector<pair<pii, string>> v;
    while (n--) {
        int w, p;
        string s;
        cin >> s >> w >> p;
        v.push_back({{w, p}, s});
    }
    pair<pii, string> e = *min_element(iter(v), [](const pair<pii, string>& a, const pair<pii, string>& b) {
        if (a.first.first != b.first.first) {
            return a.first.first > b.first.first;
        }
        return a.first.second < b.first.second;
    });
    return e.second;
}
 
int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << solve() << endl;
    }
    return 0;
}