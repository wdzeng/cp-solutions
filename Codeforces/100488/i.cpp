#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int n, m, k;
bool edge[1001][1001];
int color[1001];

void foul() {
    cout << "-1\n";
    exit(0);j 
}

void setcol(int i, int col) {
    if (col > k) foul();
    if (color[i] == 0)
        color[i] = col;
    else if (color[i] != col)
        foul();
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edge[x][y] = edge[y][x] = 1;
    }

    for (int i = 1, c = 0; i <= n; i++) {
        int cc = color[i] ? color[i] : (++c);
        color[i] = cc;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int e = 1; e <= n; e++) {
                if (edge[x][e]) {
                    if(color[e] == cc) foul();
                    continue;
                }
                if (!color[e]) q.push(e);
                setcol(e, cc);
            }
        }
    }

    for(int i=1;i<=n;i++) cout << color[i] << " ";
    cout << endl;
    return 0;
}