#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int maxn = 5e4 + 5;
unordered_map<int, int> adj[maxn];
unordered_map<int, int> adj2[maxn];
int N;

int dfs(int src, int dad) {
    // cout << src << flush;
    unordered_set<int> s, du;
    for (auto& p : adj[src]) {
        // if (p.x == dad) continue;
        int col = p.y;
        if (s.count(col)) du.insert(col);
        s.insert(col);
    }
    vector<int> pass;
    vector<int> del;
    for (auto& p : adj[src]) {
        int col = p.y;
        int i = p.x;
        // if (i == dad) continue;
        if (du.count(col)) {
            del.push_back(i);
        } else {
            pass.push_back(i);
        }
    }
    for (int d : del) {
        adj[src].erase(d);
        adj[d].erase(src);
    }
    int ret = src;
    for (int p : pass)
        if (p != dad) ret = dfs(p, src);
    return ret;
}

void check(int root) {
    vector<pii> k;
    unordered_set<int> vis;

    k.emplace_back(root, -1);
    while (k.size()) {
        int v = k.back().x;
        int dad = k.back().y;
        int col = dad == -1 ? -1 : adj2[v][dad];
        k.pop_back();

        if (vis.count(v)) continue;
        vis.insert(v);

        // cout << "! " << v << endl;
        for (auto& p : adj2[v]) {
            if (!vis.count(p.x)) {
                if (p.y == col) {
                    // cout << p.x << ' ' << p.y << ' ' << col << "!" << endl;
                    cout << 0 << endl;
                    exit(0);
                }
                k.emplace_back(p.x, v);
            }
        }
    }
}

vector<int> safe(int src) {
    vector<int> k;
    unordered_set<int> vis;
    vector<int> ret;

    k.push_back(src);
    while (k.size()) {
        int v = k.back();
        k.pop_back();
        if (vis.count(v)) continue;
        // cout << v << endl;
        vis.insert(v);
        ret.push_back(v);

        for (auto& a : adj[v]) {
            if (vis.count(a.x)) continue;
            k.push_back(a.x);
        }
    }

    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj2[a][b] = c;
        adj[b][a] = c;
        adj2[b][a] = c;
    }
    int root = dfs(1, -1);
    // cout << endl;
    // cout << root << endl;
    check(root);
    auto v = safe(root);
    sort(all(v));
    cout << v.size() << endl;
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}