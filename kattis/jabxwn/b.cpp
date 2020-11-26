#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

void solve() {
    int n;
    cin >> n;
    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        rank[a] = i;
    }

    int ifislessthan = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (rank[i] < i) {
            ans.push_back(i);
            continue;
        }
        if (rank[i] < ifislessthan) {
            ans.push_back(i);
            continue;
        }
        if (rank[i] > i)
            ifislessthan = max(ifislessthan, rank[i]);
    }

    cout << ans.size() << '\n';
    for (int w : ans) cout << w + 1 << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}