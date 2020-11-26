#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<bool> vis(1e6 + 10);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.size() > 6) continue;
        int a = stoi(s);
        if (a >= 0 and a < vis.size()) vis[a] = 1;
    }
    for (int a = 0; a < vis.size(); a++) {
        if (!vis[a]) {
            cout << a << endl;
            return 0;
        }
    }

    return 0;
}