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

const ll M = 1e9;
int fab[] = {1, 1, 2, 3, 5, 8, 13, 21, 34};
int h;
ll solve(ll w, int l = 0, int r = 0) {
    if (w == 0) return (l == r) ? 1 : 0;

    static unordered_map<ll, ll> rec[256][256];
    if (l > r) swap(l, r);
    if (rec[l][r].count(w)) return rec[l][r][w];

    if (w == 1) {
        if (l & r) return rec[l][r][w] = 0;
        vector<int> ones = {-1};
        for (int i = 0; i < h; i++)
            if ((l | r) & (1 << i))
                ones.push_back(i);
        ones.push_back(h);
        ll ret = 1;
        for (int i = 1; i < ones.size(); i++) {
            ret *= fab[ones[i] - ones[i - 1] - 1];
            ret %= M;
        }

        // cout << w << ' ' << l << ' ' << r << ' ' << ret << endl;
        return rec[l][r][w] = ret;
    }

    ll ret = 0;
    for (int i = 0; i < (1 << h); i++) {
        ret += solve(w / 2, l, i) * solve(w - w / 2, i, r);
        ret %= M;
    }

    // cout << w << ' ' << l << ' ' << r << ' ' << ret << endl;
    return rec[l][r][w] = ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    ll w;
    cin >> h >> w;
    cout << solve(w) << endl;
    return 0;
}