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

string A, B;
int dp[4010][4010];
vector<int> a[2], b[2];

pii next(const pii& p, int v) {
    pii ret = {A.size(), B.size()};
    if (p.x < A.size()) {
        auto it = upper_bound(iter(a[v]), p.x);
        if (it != a[v].end()) ret.x = *it;
    }
    if (p.y < B.size()) {
        auto it = upper_bound(iter(b[v]), p.y);
        if (it != b[v].end()) ret.y = *it;
    }
    return ret;
}

int bfs(const pii& p) {
    if (dp[p.x][p.y] == -1) dp[p.x][p.y] = min(bfs(next(p, 0)), bfs(next(p, 1))) + 1;
    return dp[p.x][p.y];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> A >> B;
    A = " " + A, B = " " + B;

    for (int i = 1; i < A.size(); i++) a[A[i] - '0'].push_back(i);
    for (int i = 1; i < B.size(); i++) b[B[i] - '0'].push_back(i);

    mss(dp);
    dp[A.size()][B.size()] = 0;
    bfs({0, 0});

    pii p = {0, 0};
    pii dst = {A.size(), B.size()};
    while (p != dst) {
        pii next0 = next(p, 0);
        pii next1 = next(p, 1);
        if (dp[next0.x][next0.y] <= dp[next1.x][next1.y]) {
            cout << 0;
            p = next0;
        } //
        else {
            cout << 1;
            p = next1;
        }
    }
    cout << endl;
    return 0;
}