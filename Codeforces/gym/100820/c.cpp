#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
typedef unsigned long long ull;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> names;
    vector<vector<int>> vv;
    vector<ull> l;
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string w;
        int j = 0;
        vector<int> v;
        while (ss >> w) {
            if (j == 0)
                names.push_back(w.substr(0, w.size() - 1));
            else if (w == "class")
                break;
            else if (w == "upper")
                v.push_back(0);
            else if (w == "lower")
                v.push_back(2);
            else
                v.push_back(1);
            j++;
        }
        reverse(all(v));
        vv.push_back(v);
    }

    vector<pair<ull, string>> ans;
    int maxl = 0;
    for (int i = 0; i < n; i++) maxl = max(maxl, (int)vv[i].size());
    for (int i = 0; i < n; i++) {
        ull val = 0;
        for (int j = 0; j < maxl; j++) {
            int tv;
            if (j >= vv[i].size())
                tv = 1;
            else
                tv = vv[i][j];
            val <<= 2;
            val |= tv;
        }
        ans.emplace_back(val, names[i]);
    }

    sort(all(ans));
    for (auto& p : ans) cout << p.y << '\n';
    return 0;
}