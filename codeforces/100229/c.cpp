#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

#define flg(a) floor(log2(a))
struct SparseTable {
    vector<vector<ll>> a;
    SparseTable(vector<ll>& data) {
        int n = data.size();
        a.assign(flg(n) + 1, vector<ll>(n));
        a[0] = data;
        for (int i = 1; (1 << i) <= n; i++)
            for (int j = 0, k = n - (1 << i); j <= k; j++)
                a[i][j] = __gcd(a[i - 1][j],
                                a[i - 1][j + (1 << (i - 1))]);
    }
    ll q(int l, int r) {  // [l, r], 0/1-based
        int k = flg(r - l + 1);
        return __gcd(a[k][l], a[k][r - (1 << k) + 1]);
    }
};

int main() {
    fastio();

    int t;
    cin >> t;
    while (t--) {
        ll maxans = 0;

        int n;
        cin >> n;
        vector<ll> vec(n);

        for (auto& val : vec) cin >> val;
        // vec.push_back(1); // dummy end
        SparseTable sp(vec);

        for (int l = 0; l < n; l++) {
            // cout << "L " << l << endl;
            debug(l);
            int curr = l;
            ll curg = vec[l];

            while (curr < n) {
                // cout << "?" << curr << endl;
                int rl = curr, rr = n - 1;
                while (rl <= rr) {
                    // cout << rl << ' ' << rr << endl;
                    int rm = (rl + rr) >> 1;
                    ll g = sp.q(l, rm);
                    if (g == curg) {
                        rl = rm + 1;
                    } else {
                        rr = rm - 1;
                    }
                }

                // cout << l << ' ' << rl << ' ' << curr << endl;
                // rl--;
                // ass(rl < n);
                debug(rl);
                ass(rl > curr);
                ass(rl <= n);

                if (rl == n) {
                    ll ansg = sp.q(l, n - 1);
                    maxans = max(maxans, (n - l) * ansg);
                    break;
                }  //
                else {
                    // rl--;
                    maxans = max(maxans, (rl - l) * sp.q(l, rl - 1));
                    curr = rl;
                    curg = sp.q(l, rl);
                }
            }

            // ll lgg = sp.q(l, n - 1);
            // maxans = max(maxans, (n - l) * lgg);
        }

        cout << maxans << endl;
    }
}
