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

const int N = 32;
int g[N][N];
int X, Y;

ll rect(int x, int y) {
    static int init = 0;
    static ll c[61][31];
    if (!init) {
        for (int i = 0; i < 61; i++) {
            for (int j = 0; j * 2 <= i; j++) {
                ll num = 1;
                for (int k = 2; k <= j; k++) num *= k;
                ll den = 1;
                for (int k = 2; k <= i; k++) {
                    den *= k;
                    ll g = __gcd(num, den);
                    den /= g;
                    num /= g;
                }
                assert(num == 1);
                c[i][j] = den;
            }
        }
        init = 1;
    }
    if (x > y) swap(x, y);
    return c[x + y][y];
}

void paint(int x, int y, int c) {
    if (g[x][y] == -c) {
        cout << 0 << endl;
        exit(0);
    }
    g[x][y] = c;
}

ll dp[N][N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> X >> Y;
    vector<pii> Bs, Rs;
    for (int i = 0; i < X; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < Y; j++)
            if (s[j] == 'R') Rs.emplace_back(i + 1, j + 1);
        for (int j = 0; j < Y; j++)
            if (s[j] == 'B') Bs.emplace_back(i + 1, j + 1);
    }
    for (auto& p : Bs) {
        for (int i = 1; i <= p.x; i++)
            for (int j = 1; j <= p.y; j++) paint(i, j, 1);
    }
    for (auto& p : Rs) {
        for (int i = p.x; i <= X; i++)
            for (int j = p.y; j <= Y; j++) paint(i, j, -1);
    }

    Bs.emplace_back(0, Y);
    Bs.emplace_back(X, 0);
    sort(all(Bs));
    vector<pii> B;
    for (auto& p : Bs) {
        while (!B.empty() && p.y >= B.back().y) B.pop_back();
        B.push_back(p);
    }
    Bs.swap(B);

    for (auto& p : Bs) {
        for (int i = 0; i < p.x; i++) {
            for (int j = 0; j < p.y; j++) g[i][j] = -1;
        }
    }

    pii src = {0, Y}, dst = {X, 0};
    ms(dp);
    dp[src.x][src.y] = 1;
    for (int x = src.x; x <= dst.x; x++) {
        for (int y = src.y; y >= dst.y; y--) {
            if (~g[x + 1][y]) dp[x + 1][y] += dp[x][y];
            if (~g[x][y - 1]) dp[x][y - 1] += dp[x][y];
        }
    }
    cout << dp[X][0] << endl;
    return 0;
}