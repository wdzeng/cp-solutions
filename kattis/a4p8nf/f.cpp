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

int X, Y;
string g[105];
int vis[105][105];

void dfs(int x, int y) {
    if (vis[x][y]) return;
    if(g[x][y] != '#') return;
    vis[x][y] = 1;
    dfs(x-1, y); 
    dfs(x+1, y); 
    dfs(x-1, y-1); 
    dfs(x, y-1); 
    dfs(x+1, y-1); 
    dfs(x-1, y+1); 
    dfs(x, y+1); 
    dfs(x+1, y+1); 
}

int main() {
    fastio();
    cin >> X >> Y;
    for (int i = 1; i <= X; i++) {
        string s;
        cin >> s;
        s = " " + s + " ";
        g[i] = s;
    }
    int ans = 0;
    for(int i=1; i<=X; i++) {
        for(int j=1; j<=Y; j++) {
            if(!vis[i][j] && g[i][j] == '#') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}