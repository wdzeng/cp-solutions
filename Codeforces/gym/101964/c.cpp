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

const int N = 105;
int col[N];
vector<int> adj[N];
int len[N][N];

int findlen(int v, int p, int dst) {
    if (v == dst) return 0;
    int ret = 1000;
    for (int a : adj[v])
        if (a != p)
            ret = min(findlen(a, v, dst) + 1, ret);
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        len[i][i] = 0;
        for (int j = i + 1; j <= n; j++) {
            len[i][j] = len[j][i] = findlen(i, 0, j);
        }
    }

    int ans = 500;
    for (int i = 1; i <= n; i++) {
        int cnt[205] = {0};
        for (int j = 1; j <= n; j++) {
            if (col[j]) {
                int l = len[i][j];
                cnt[l]++;
            }
        }
        int s = 0;
        int x = 0;
        for (; x < 205; x++) {
            s += cnt[x];
            if (s >= k) break;
        }
        ans = min(ans, x * 2);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (j < i) continue;
            int cnt[205] = {0};
            for (int a = 1; a <= n; a++) {
                if (col[a]) {
                    int l = min(len[a][i], len[a][j]);
                    cnt[l]++;
                }
            }
            int s = 0;
            int x = 0;
            for (; x < 205; x++) {
                s += cnt[x];
                if (s >= k) break;
            }
            ans = min(ans, x * 2 + 1);
        }
    }

    cout << ans << endl;
    return 0;
}