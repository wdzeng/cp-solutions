#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    ll s;
    cin >> n >> s;
    vector<pii> vec;
    for (int i = 0; i < n; i++) {
        pii p;
        cin >> p.x >> p.y;
        vec.push_back(p);
    }
    vector<int> order;
    for (int i = 0; i < n; i++) order.push_back(i);
    sort(iter(order), [&](int i, int j) { return vec[i] > vec[j]; });

    int atleast = 0;
    ll total = 0;
    for (int i : order) {
        total += vec[i].x;
        atleast++;
        if (total >= s) break;
    }

    vector<int> good, bad;
    for (int i = 0; i < n; i++) {
        auto& which = vec[order[i]].y == 1 ? good : bad;
        which.push_back(order[i]);
    }

    list<int> ans;
    total = 0;
    int badcursor = 0;
    int ngood = min((int)good.size(), atleast);
    for (int i = 0; i < ngood; i++) {
        ans.push_back(good[i]);
        total += vec[good[i]].x;
    }
    for (int i = good.size(); i < atleast; i++) {
        int idx = bad[i - good.size()];
        ans.push_front(idx);
        total += vec[idx].x;
        badcursor++;
    }

    while (total < s) {
        assert(ngood > 0);
        assert(badcursor < bad.size());
        ngood--;
        total -= vec[ans.back()].x;
        ans.pop_back();
        int putid = bad[badcursor++];
        ans.push_front(putid);
        total += vec[putid].x;
    }

    cout << ans.size() << ' ' << ngood << endl;
    for (int i : ans) cout << i + 1 << ' ';
    cout << endl;
    return 0;
}