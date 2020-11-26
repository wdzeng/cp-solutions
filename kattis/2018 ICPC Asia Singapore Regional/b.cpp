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

vector<vector<int>> adj;
vector<int> aff;
int n;

bool odd_ring(int i) {
    for (int a : adj[i]) {
        if (aff[a] == aff[i]) return 1;
        if (aff[a] == aff[i] * -1) continue;
        aff[a] = aff[i] * -1;
        bool b = odd_ring(a);
        if (b) return 1;
    }
    return 0;
}

bool odd_ring() {
    aff.assign(n, 0);
    for (int i = 0; i < aff.size(); i++) {
        if (aff[i]) continue;
        aff[i] = 1;
        bool b = odd_ring(i);
        if (b) return 1;
    }
    return 0;
}


int packets() {
    aff.assign(n, 0);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (aff[i]) continue;
        stack<int> k;
        k.push(i);
        while (k.size()) {
            int v = k.top();
            k.pop();
            aff[v] = 1;
            for (int e : adj[v]) {
                if (aff[e]) continue;
                k.push(e);
            }
        }
        ret++;
    }
    return ret;
}

int link() {
    aff.assign(n, 0);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (aff[i]) continue;
        if (adj[i].empty()) {
            aff[i] = 1;
            continue;
        }

        stack<int> k;
        k.push(i);
        while (k.size()) {
            int v = k.top();
            aff[v] = 1;
            for (int e : adj[v]) {
                if (aff[e]) continue;
                k.push(e);
            }
        }
        ret++;
    }
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    if (odd_ring()) {
        int p = packets();
        cout << p - 1 << endl;
        return 0;
    }

    int p = packets();
    cout << p << endl;
    return 0;
}