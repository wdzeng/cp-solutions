#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

inline void setmin(ll& val, ll c) {
    val = min(val, c);
}

struct mission {
    int e1;
    ll t1;
    int e2;
    ll t2;
};

const ll INF = 1e15;
ll dp[501][501];
ll newdp[501][501];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int q, s1, s2;
    cin >> q >> s1 >> s2;
    vector<mission> msss(q);
    for (auto& m : msss) cin >> m.e1 >> m.t1 >> m.e2 >> m.t2;
    sort(all(msss), [](const auto& a, const auto& b) { return a.e1 < b.e1; });

    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; j++) {
            dp[i][j] = newdp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    newdp[0][0] = 0;

    for (int t = 0; t < q; t++) {
        for (int i = 0; i <= s1; i++) {
            for (int j = 0; j <= s2; j++) {
                if (i < s1) {
                    int anewe1 = i + msss[t].e1;
                    int anewe2 = j;
                    if (anewe1 > s1) {
                        anewe2 += (anewe1 - s1);
                        anewe1 = s1;
                    }
                    anewe2 = min(anewe2, s2);
                    ll ares = dp[i][j] + msss[t].t1;
                    setmin(newdp[anewe1][anewe2], ares);
                }

                int bnewe1 = i;
                int bnewe2 = min(s2, j + msss[t].e2);
                ll bres = dp[i][j] + msss[t].t2;
                setmin(newdp[bnewe1][bnewe2], bres);
            }
        }
        memcpy(dp, newdp, sizeof(dp));
    }

    cout << (dp[s1][s2] == INF ? -1 : dp[s1][s2]) << endl;
    return 0;
}