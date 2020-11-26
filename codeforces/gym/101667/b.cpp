#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

ll g[4][4];

inline int win(int c) {
    for (int i = 0; i < 4; i++) {
        if (g[i][0] == c && g[i][1] == c && g[i][2] == c) return 1;
        if (g[i][3] == c && g[i][1] == c && g[i][2] == c) return 1;
        if (g[0][i] == c && g[1][i] == c && g[2][i] == c) return 1;
        if (g[3][i] == c && g[1][i] == c && g[2][i] == c) return 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (g[i + 0][j + 0] == c && g[i + 1][j + 1] == c && g[i + 2][j + 2] == c) return 1;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 2; j < 4; j++) {
            if (g[i + 0][j - 0] == c && g[i + 1][j - 1] == c && g[i + 2][j - 2] == c) return 1;
        }
    }
    return 0;
}

inline int lose() {
    return win(1);
}

inline int win() {
    return win(2);
}

ll h() {
    ll ret = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            ret <<= 2;
            ret |= g[i][j];
        }
    return ret;
}

void print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << (g[j][3 - i] ? (g[j][3 - i] == 1 ? 'O' : 'X') : ' ');
        }
        cout << endl;
    }
}

int C, R;
int len[4];
unordered_set<ll> ans;
void dfs(int k, int col) {
    int row = len[col];
    if (row == 4) return;

    g[col][row] = k;
    len[col]++;
    if (col == C && row == R) {
        if (win()) {
            // print();
            ans.insert(h());
        }
    } else {
        if (!win() && !lose()) {
            dfs(3 - k, 0);
            dfs(3 - k, 1);
            dfs(3 - k, 2);
            dfs(3 - k, 3);
        } else {
            // print();
            // ans.insert(h());
        }
    }
    len[col]--;
    g[col][row] = 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int x;
    cin >> x >> R >> C;
    x--;
    R--, C--;
    dfs(1, x);
    cout << ans.size() << endl;
    return 0;
}