#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

struct pC {
    const int N;
    const int T;
    const double R = 1.0 / 6;
    unordered_set<int> pause;
    unordered_set<int> back;

    double ans = 0;
    vector<double> rate;
    vector<double> rate_pause;

    pC(int n, int t, int nl, int nb) : N(n), T(t) {
        while (nl--) {
            int x;
            cin >> x;
            pause.insert(x);
        }
        while (nb--) {
            int x;
            cin >> x;
            back.insert(x);
        }
        rate.assign(N, 0.0);
        rate[0] = 1.0;
        rate_pause.assign(N, 0.0);
    }
    void next() {
        vector<double> u = rate_pause;
        vector<double> u_pause(N, 0.0);
        for (int loc = 0; loc < N; loc++) {
            if (rate[loc] == 0.0) continue;
            for (int d = 1; d <= 6; d++) {
                int newloc = loc + d;
                if (newloc == N) {
                    ans += rate[loc] * R;
                    continue;
                }
                if (newloc > N) {
                    int exc = newloc - N;
                    newloc = N - exc;
                }

                if (back.count(newloc)) {
                    u[0] += rate[loc] * R;
                }  //
                else if (pause.count(newloc)) {
                    u_pause[newloc] += rate[loc] * R;
                }  //
                else {
                    u[newloc] += rate[loc] * R;
                }
            }
        }
        rate.swap(u);
        rate_pause.swap(u_pause);
    }
    double solve() {
        for (int t = 0; t < T; t++) next();
        return ans;
    }
};

int main() {
    freopen("C.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int n, t, l, b;
    while (cin >> n >> t >> l >> b && n) {
        cout << pC(n, t, l, b).solve() << endl;
    }
    return 0;
}