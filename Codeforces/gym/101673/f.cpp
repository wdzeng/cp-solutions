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

const int N = 1e4 + 5;
int sz[N];
vector<int> adj[N];
ll w[N];
ll ans[N];
int n;

void dfsS(int v, int p) {
    for (int a : adj[v])
        if (a != p) dfsS(a, v), sz[v] += sz[a];
    sz[v]++;
}

void dfsW(int v, int p) {
    vector<ll> vec;
    if(p != -1) vec.push_back(n - sz[v]);
    for (int a : adj[v])
        if (a != p) dfsW(a, v), vec.push_back(sz[a]);
    sort(all(vec));
    if (vec.size() > 1) {
        reverse(all(vec));
        ans[v] = vec[0] * vec[1];
    }
    for(int i=0 ; i<zz(vec); i++)
    for(int j=i+1 ; j<zz(vec); j++) w[v] += vec[i] * vec[j];
    // cout << v << ": "; for(int val: vec) cout << val << ' '; cout << endl;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int m;
    cin >> m;
    n = m + 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsS(0, -1);
    dfsW(0, -1);
    int maxW = 0;
    for (int i = 0; i < n; i++)
        if (w[i] > w[maxW]) maxW = i;
    cout << w[maxW] << ' ' << w[maxW] - ans[maxW] << endl;
    return 0;
}