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

int n;
const int maxn = 505;
bool e[maxn][maxn];
int deg[maxn];
int m;

void task(int i, int k) {
    vector<int> next;
    for (int j = 0; j < n; j++) {
        if (e[i][j] || i == j) continue;
        if (deg[i] + deg[j] >= k) {
            e[i][j] = e[j][i] = 1;
            m++;
            next.push_back(j);
            deg[i]++, deg[j]++;
        }
    }
    if (!next.empty()) next.push_back(i);
    for (int c : next) task(c, k);
}

void task(int k) {
    for (int i = 0; i < n; i++) {
        task(i, k);
    }
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    int M = n * (n - 1) / 2;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a][b] = e[b][a] = 1;
        deg[a]++, deg[b]++;
    }

    int mx = *max_element(deg, deg + maxn);
    int k = mx * 2 + 1;
    while (m < M) k--, task(k);
    cout << k << '\n';
    return 0;
}