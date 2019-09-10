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

int N;
int d1[100][100], d2[100][100], d[100][100];

int test(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int e = 0; e < N; e++) {
        if (d1[src][e] == -1) continue;
        q.emplace(d1[src][e], e);
    }
    bool vis[N];
    ms(vis);
    while (!q.empty()) {
        int v = q.top().second;
        int p = q.top().first;
        q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        d[src][v] = p;
        for (int e = 0; e < N; e++) {
            if (d2[v][e] == -1) continue;
            if (vis[e]) continue;
            q.emplace(p + d2[v][e], e);
        }
    }
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    mss(d1);
    mss(d2);
    mss(d);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> d1[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (d1[i][j] != -1) {
                //  d2[i][j] = 0;
                // continue;
            }
            for (int k = 0; k < N; k++) {
                if (d1[i][k] == -1 || d1[k][j] == -1) continue;

                int sum = d1[i][k] + d1[k][j];
                if (d2[i][j] == -1)
                    d2[i][j] = sum;
                else
                    d2[i][j] = min(d2[i][j], sum);
            }
        }
    }

    for (int i = 0; i < N; i++) test(i);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}