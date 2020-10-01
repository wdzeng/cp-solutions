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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& val : a) cin >> val;
    for (auto& val : b) cin >> val;

    int maxdiff = 0;
    for (auto val : a) {
        int mindiff = 1e9;
        for (auto vel : b) {
            int d = abs(val - vel);
            mindiff = min(mindiff, d);
        }
        maxdiff = max(maxdiff, mindiff);
    }

    cout << maxdiff << endl;

    return 0;
}