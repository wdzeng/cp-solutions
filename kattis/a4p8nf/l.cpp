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
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    string line;
    vector<string> vec;
    while (getline(cin, line)) {
        stringstream ss(line);
        string tok;
        while (ss >> tok) vec.push_back(tok);
    }
    set<string> ans;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (i == j) continue;
            ans.insert(vec[i] + vec[j]);
        }
    }
    for (auto& a : ans) cout << a << endl;
    return 0;
}