#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int maxn = 3e5, maxm = 8;
int arr[maxn][maxm];
int n, m;

pii check(int c) {
    vector<int> vis(1 << m, -1);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] >= c) mask |= (1 << j);
        }
        vis[mask] = i;
    }

    for (int i = 0; i < (1 << m); i++) {
        if (vis[i] == -1) continue;
        for (int j = 0; j < (1 << m); j++) {
            if (vis[j] == -1) continue;
            if ((i | j) == (1 << m) - 1) return {vis[i], vis[j]};
        }
    }
    return {-1, -1};
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int l = 0, r = 1e9;
    pii ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        pii ret = check(mid);
        if (ret.x != -1)
            l = mid + 1, ans = ret;
        else
            r = mid - 1;
    }
    
    if (ans.x > ans.y) swap(ans.x, ans.y);
    cout << ans.x + 1 << ' ' << ans.y + 1 << endl;
    return 0;
}