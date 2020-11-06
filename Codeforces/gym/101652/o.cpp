#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;

    while (cin >> n) {
        vector<string> g(n);
        for (auto& s : g) {
            cin >> s;
            for (char& c : s)
                if (c >= '0' && c <= '9')
                    c -= '0';
                else
                    c = c - 'A' + 10;
        }
        int ok = 1;
        for (int i = 0; i < n; i++) {
            unordered_set<int> ss;
            for (int j = 0; j < n; j++) ss.insert(g[i][j]);
            if (ss.size() != n) ok = 0;
        }
        for (int i = 0; i < n; i++) {
            unordered_set<int> ss;
            for (int j = 0; j < n; j++) ss.insert(g[j][i]);
            if (ss.size() != n) ok = 0;
        }
        if (!ok) {
            cout << "No" << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (g[0][i] != i) ok = 0;
            if (g[i][0] != i) ok = 0;
        }
        if (ok)
            cout << "Reduced" << endl;
        else
            cout << "Not Reduced" << endl;
    }
    return 0;
}