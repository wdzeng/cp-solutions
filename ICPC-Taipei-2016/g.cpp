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

string tmp;
int N;
const int maxn = 105;
vector<int> adj[maxn];

int solve(int src) {
    int dist[maxn];
    int dad[maxn];
    ms(dist);
    mss(dad);
    dad[src] = -2;

    queue<int> k;
    k.push(src);
    while (k.size()) {
        int v = k.front();
        k.pop();
        assert(dad[v] != -1);
        for (int e : adj[v]) {
            if (e != dad[v] and e == src) return dist[v] + 1;
            if (dad[e] != -1) continue;
            dad[e] = v;
            dist[e] = dist[v] + 1;
            k.push(e);
        }
    }

    return 1e9;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);

    while (cin >> N and N) {
        for (auto& a : adj) a.clear();
        getline(cin, tmp);
        for (int i = 0; i < N; i++) {
            getline(cin, tmp);
            // cout << tmp << endl;
            stringstream ss(tmp);
            int a;
            while (ss >> a) {
                a--;
                adj[a].push_back(i);
            }
        }
        int ans = 1e9;
        for (int i = 0; i < N; i++) ans = min(ans, solve(i));
        if (ans == 1e9) ans = 0;
        cout << ans << endl;
    }

    return 0;
}
