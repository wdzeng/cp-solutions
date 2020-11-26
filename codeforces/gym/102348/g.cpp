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
    string a, b;
    cin >> a >> b;
    vector<int> ab, ba;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (a[i] == 'a')
            ab.push_back(i);
        else
            ba.push_back(i);
    }
    vector<int> ans;
    while (ab.size() > 1) {
        ans.push_back(ab.back());
        ab.pop_back();
        ans.push_back(ab.back());
        ab.pop_back();
    }
    while (ba.size() > 1) {
        ans.push_back(ba.back());
        ba.pop_back();
        ans.push_back(ba.back());
        ba.pop_back();
    }
    if (ab.size() == ba.size()) {
        if (ab.size()) {
            ans.push_back(ab[0]);
            ans.push_back(ab[0]);
            ans.push_back(ab[0]);
            ans.push_back(ba[0]);
        }
        cout << ans.size() / 2 << endl;
        for (int i = 0; i < ans.size(); i += 2) cout << ans[i] + 1 << ' ' << ans[i + 1] + 1 << '\n';

    } else {
        cout << -1 << endl;
    }

    return 0;
}