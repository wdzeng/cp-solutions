#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int x;
    cin >> x;
    string s;
    cin >> s;

    stack<pair<int, char>> sc;
    vector<int> ans(x);
    int lw = 0, up = 0;
    for (const char c : s) {
        if (!sc.empty() && (sc.top().second ^ ' ') == c) {
            if (isupper(c)) {
                ans[up++] = sc.top().first;
            } else {
                ans[sc.top().first] = lw++;
            }
            sc.pop();
        } else {
            if (islower(c))
                sc.push({lw++, c});
            else
                sc.push({up++, c});
        }
    }

    if (sc.empty()) {
        for (int i : ans) cout << i + 1 << " ";
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}