#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
 
const int maxn = 100001;
int n;
vector<int> prv[maxn], nxt[maxn];
int cup[maxn];
int before[maxn];
 
void update(int& v, int u) {
    if (v == -1)
        v = u;
    else if (v != u)
        v = -2;
    else
        v = u;
}
 
void backtrack(int src, int v, vector<bool>& visited) {
    for (int x : nxt[src]) {
        update(before[x], v);
        if (x != src && cup[x] == 0 && !visited[x]) {
            visited[x] = true;
            backtrack(x, v, visited);
        }
        visited[x] = true;
    }
}
 
void output(int x) {
    if (x == 0)
        cout << "sober";
    else if (x == -2)
        cout << "unknown";
    else if (x > 0)
        cout << x;
    else
        throw "";
}
 
int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cup[i];
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            nxt[i].push_back(x);
            prv[x].push_back(i);
        }
    }
    mss(before);
    before[1] = 0;
 
    for (int i = 1; i <= n; i++) {
        if (!cup[i] && i != 1) continue;
        vector<bool> visited(n + 1, false);
        backtrack(i, cup[i], visited);
    }
 
    for (int i = 1; i <= n; i++) {
        output(before[i]); cout << " "; output(cup[i]? cup[i]: before[i]); cout << "\n";
    }
    return 0;
}