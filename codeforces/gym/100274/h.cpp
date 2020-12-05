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
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const int N = 1e5 + 5;
vector<int> p;
vector<int> bb;
vector<int> be;
vector<int> eb;
vector<int> ee;
ll lim;
int n;
const ll inf = 1e12 + 100;

ll solve(int isb, string& ans) {
    vector<ll> dpb(n);
    vector<ll> dpe(n);
    vector<char> cdpb(n);
    vector<char> cdpe(n);
    dpb[0] = isb ? inf : p[0];
    dpe[0] = isb ? p[0] : inf;
    for (int i = 1; i < n; i++) {
        // goto begin
        if (dpb[i - 1] + be[i - 1] < dpe[i - 1] + ee[i - 1]) {
            dpb[i] = dpb[i - 1] + be[i - 1];
            cdpb[i] = 'B';
        } else {
            dpb[i] = dpe[i - 1] + ee[i - 1];
            cdpb[i] = 'F';
        }
        dpb[i] += p[i];
        // goto end
        if (dpb[i - 1] + bb[i - 1] < dpe[i - 1] + eb[i - 1]) {
            dpe[i] = dpb[i - 1] + bb[i - 1];
            cdpe[i] = 'B';
        } else {
            dpe[i] = dpe[i - 1] + eb[i - 1];
            cdpe[i] = 'F';
        }
        dpe[i] += p[i];
    }

    ll ret;
    if (isb) {
        // loop to begin
        // debug(dpe[n-1]);
        // debug(eb[n-1]);
        // debug(dpb[n-1]);
        if (dpe[n - 1] + eb[n - 1] < dpb[n - 1] + bb[n - 1]) {
            ret = dpe[n - 1] + eb[n - 1];
            ans = "F";
            for (int i = n - 2; i > 0; i--) {
                if (ans.back() == 'F')
                    ans.push_back(cdpe[i+1]);
                else
                    ans.push_back(cdpb[i+1]);
            }
            ans.push_back(isb ? 'F' : 'B');
        } else {
            ret = dpb[n - 1] + bb[n - 1];
            ans = "B";
            for (int i = n - 2; i > 0; i--) {
                if (ans.back() == 'F')
                    ans.push_back(cdpe[i+1]);
                else
                    ans.push_back(cdpb[i+1]);
            }
            ans.push_back(isb ? 'F' : 'B');
        }
        reverse(all(ans));
        return ret;
    } else {
        // return to end
        if (dpe[n - 1] + ee[n - 1] < dpb[n - 1] + be[n - 1]) {
            ret = dpe[n - 1] + ee[n - 1];
            ans = "F";
            for (int i = n - 2; i > 0; i--) {
                if (ans.back() == 'F')
                    ans.push_back(cdpe[i+1]);
                else
                    ans.push_back(cdpb[i+1]);
            }
            ans.push_back(isb ? 'F' : 'B');
        } else {
            ret = dpb[n - 1] + be[n - 1];
            ans = "B";
            for (int i = n - 2; i > 0; i--) {
                if (ans.back() == 'F')
                    ans.push_back(cdpe[i+1]);
                else
                    ans.push_back(cdpb[i+1]);
            }
            ans.push_back(isb ? 'F' : 'B');
        }
        reverse(all(ans));
        return ret;
    }
}

void solve() {
    cin >> n >> lim;
    p.resize(n);
    bb.resize(n);
    be.resize(n);
    eb.resize(n);
    ee.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i] >> bb[i] >> be[i] >> eb[i] >> ee[i];
    string seqb, seqe;
    ll ansb = solve(1, seqb);
    ll anse = solve(0, seqe);
    // cout << ansb << ' ' << seqb << ' ' << anse << ' ' << seqe << endl;
    if (ansb > lim && anse > lim) {
        cout << "IMPOSSIBLE" << endl;
    } else if (ansb < anse) {
        cout << seqb << endl;
    } else {
        cout << seqe << endl;
    }
}

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}