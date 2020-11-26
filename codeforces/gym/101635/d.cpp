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

int TZ = 400 * 50;
int t[TZ][26];
int w[TZ];
int cnt = 0;
void add(string s, int W) {
    int p = 0;
    for (int c : s) {
        if (t[p][c] == -1) t[p][c] == ++cnt;
        p = t[p][c];
    }
    w[cnt] = W;
}

const int N = 51;
int dp[N][N];
int el[N][N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    mss(t);
    mss(w);
    mss(dp);
    mss(el);

    string C;
    cin >> C;
    for (char& c : C) c -= 'a';
    int m;
    cin >> m;
    while (m--) {
        string x;
        cin >> x;
        for (char& c : x) c -= 'a';
        int w;
        cin >> w;
        add(x, w);
        reverse(all(x));
        add(x, w);
    }

    int L = zz(C);

    for (int r = 0; r <= L; r++) {
        el[r][r] = 0;

        int ls[N][TZ];
        mss(ls);
        for (int i = 0; i < N; i++) ls[i][0] = 0;

        for (int l = r; l >= 0; l--) {
            int mx = -1;
            // when k is 0
            for (int ll = 0; ll <= l; ll++) {
                if (~el[ll][l]) mx = max(mx, el[ll][l]);
            }

            // else
            for (int k = 1; k <= cnt; k++) {
                if (ls[l][k] == -1) continue;
                for (int ll = 0; ll <= l; ll++) {
                    if (~el[ll][l]) mx = max(mx, el[ll][l] + ls[l][k]);
                }
            }
        }
    }
    return 0;
}