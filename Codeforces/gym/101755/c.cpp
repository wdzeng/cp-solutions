#include <bits/stdc++.h>
#define index first
#define loc second
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({i, l});
        segs.push_back({i, -r});
    }
    sort(segs.begin(), segs.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (abs(a.loc) == abs(b.loc)) return a.loc > b.loc;
        return abs(a.loc) < abs(b.loc);
    });

    int ncut = 0;
    int group[n];
    vector<int> ans;
    for (auto& p : segs) {
        if (p.loc > 0) {
            group[p.index] = ncut + 1;
        }  //
        else {
            if (group[p.index] <= ncut) continue;
            ans.push_back(-p.loc);
            ncut++;
        }
    }

    cout << ans.size() << endl;
    for (int a : ans) cout << a << " ";
    cout << endl;
    return 0;
}