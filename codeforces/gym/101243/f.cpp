#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1e3 + 5;
vector<int> altb[N];
vector<int> agtb[N];
char ans[N];

int sz[N], fa[N];
int par(int v) {
    if (v == fa[v]) return v;
    return fa[v] = par(fa[v]);
}
int join(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += b, fa[b] = a;
    return 1;
}

pair<int, int> split(string s, int index) {
    assert(~index);
    int a = stoi(s.substr(0, index));
    int b = stoi(s.substr(index + 1, s.size()));
    return {a, b};
}

int main() {
#ifndef hy
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 0; i < N; i++) sz[i] = 1, fa[i] = i;
    int n, m;
    cin >> n >> m;
    while (m--) {
        string s;
        cin >> s;

        int lt = 0, eq = 0, gt = 0;
        int index = s.find_first_of('<');
        if (~index)
            lt = 1;
        else {
            index = s.find_first_of('=');
            if (~index)
                eq = 1;
            else {
                index = s.find_first_of('>');
                assert(~index);
                gt = 1;
            }
        }
        int a, b;
        tie(a, b) = split(s, index);
        a--, b--;
        if (lt)
            altb[a].push_back(b), agtb[b].push_back(a);
        else if (eq)
            join(a, b);
        else {
            assert(gt);
            altb[b].push_back(a), agtb[a].push_back(b);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == par(i)) continue;
        for (int a : altb[i]) altb[par(i)].push_back(a);
        for (int a : agtb[i]) agtb[par(i)].push_back(a);
    }
    for (int i = 0; i < n; i++) ans[i] = '?';
    for (int i = 0; i < n; i++) {
        if (ans[par(i)] != '?') continue;
        if (!altb[par(i)].empty() && !agtb[par(i)].empty()) {
            ans[par(i)] = 'R';
            for (int w : altb[par(i)]) ans[par(w)] = 'W';
            for (int b : agtb[par(i)]) ans[par(b)] = 'B';
        }
    }
    for (int i = 0; i < n; i++) cout << ans[par(i)];
    cout << endl;
    return 0;
}