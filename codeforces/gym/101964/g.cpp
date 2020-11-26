#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = (1 << 20) + 5;
ll coldp[N << 2], rowdp[N << 2];
int colcol[N << 2], rowcol[N << 2];
ll w[30], h[30], dup = 0;
int W;

void update(int x, int i, int cl, int cr, int isrow) {
    ll* dp = isrow ? rowdp : coldp;
    int* color = isrow ? rowcol : colcol;

    if (x >= cr || x < cl)
        return;
    if (cl + 1 == cr) {
        assert(x == cl);
        color[i] = !color[i];
        return;
    }

    int cm = (cl + cr) >> 1;
    update(x, i * 2 + 1, cl, cm, isrow);
    update(x, i * 2 + 2, cm, cr, isrow);
    int len = __lg(cr - cl);

    if (color[i * 2 + 1] == color[i * 2 + 2] && ~color[i * 2 + 1]) {
        if (color[i] == -1) {
            if (isrow) {
                h[len]--;
                dup -= w[len];
            } else {
                w[len]--;
                dup -= h[len];
            }
        }
        color[i] = color[i * 2 + 1];
        dp[i] = 0;
    }  //
    else {
        if (~color[i]) {
            if (isrow) {
                h[len]++;
                dup += w[len];
            } else {
                w[len]++;
                dup += h[len];
            }
        }
        color[i] = -1;
        dp[i] = dp[i * 2 + 1] + dp[i * 2 + 2] + W / (cr - cl);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int q;
    cin >> W >> q;
    W = 1 << W;
    while (q--) {
        int s, t;
        cin >> s >> t;
        t--;
        update(t, 0, 0, W, s == 0);
        ll b = rowdp[0] + coldp[0] - dup;
        cout << b * 4 + 1 << endl;
    }
    return 0;
}