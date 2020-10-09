#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int n;
const int N = 30;
int g[N][N];
vector<pii> ans;

inline int id(const pii& p) {
    return p.x * n + p.y;
}

inline pii pd(int l) {
    return {l / n, l % n};
}

inline int samegroup(const pii& a, const pii& b) {
    return ((a.x + a.y) % 4 == (b.x + b.y) % 4) and (a.x % 2 == b.x % 2);
}

inline pii getsrc(const pii& p) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (samegroup({x, y}, p))
                return {x, y};
        }
    }
    assert(0);
    return {0, 0};
}

void solve(pii src) {
    src = getsrc(src);

    pii one;
    bool flag = 0;
    set<pii> bks;
    vector<pii> adj[N][N];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (g[x][y] == 'W') {
                assert(x > 0 and x + 1 < n and y > 0 and y + 1 < n);
                pii na, nb;
                if (getsrc({x - 1, y - 1}) == src)
                    na = {x - 1, y - 1}, nb = {x + 1, y + 1};
                else
                    na = {x - 1, y + 1}, nb = {x + 1, y - 1};

                if (g[na.x][na.y] == 'W') {
                    // cout << "Bad White" << endl;
                    return;
                }

                vector<pii> cand = {na, nb};
                for (const pii& ca : cand) {
                    if (g[ca.x][ca.y] == 'W') {
                        // cout << "Bad white" << endl;
                        return;
                    }
                    if (g[ca.x][ca.y] != 'B') continue;
                    if (flag and one != ca) {
                        // cout << "Bad black" << endl;
                        return;
                    }
                    flag = 1;
                    one = ca;
                }
                adj[na.x][na.y].push_back(nb);
                adj[nb.x][nb.y].push_back(na);
                bks.insert(na);
                bks.insert(nb);
            }
        }
    }

    assert(flag);
    set<pii> vis;
    vector<pii> k = {one};
    vis.insert(one);
    while (!k.empty()) {
        auto u = k.back();
        k.pop_back();
        for (auto a : adj[u.x][u.y]) {
            if (vis.count(a)) continue;
            vis.insert(a);
            k.push_back(a);
        }
    }

    if (vis.size() != bks.size()) return;

    vector<pii> odds;
    for (auto& b : bks) {
        if (adj[b.x][b.y].size() % 2) odds.push_back(b);
    }
    if (odds.size() > 2) {
        // cout << "odds.size() > 2" << endl;
        return;
    }
    if (odds.size() == 1) {
        // cout << "odds.size() == 1" << endl;
        return;
    }
    if (odds.size() == 2) {
        if (odds[0] == one or odds[1] == one) {
            ans.push_back(one);
        } else {
            // cout << "odds.size() == 2 and BAD" << endl;
        }
        return;
    }
    ans.push_back(one);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'W')
                g[i][j] = 'W';
            else if (str[j] == 'B')
                g[i][j] = 'B';
        }
    }

    for (int i = 0; i < n; i++) {
        if (g[i][0] == 'W' or g[i][n - 1] == 'W' or g[0][i] == 'W' or g[n - 1][i] == 'W') {
            // cout << "Edge W" << endl;
            cout << "None" << endl;
            return 0;
        }
    }

    set<pii> vis;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (g[x][y] != 'B') continue;
            pii src = getsrc({x, y});
            if (vis.count(src)) continue;
            vis.insert(src);
            // cout << "Solve " << x << ',' << y << endl;
            solve(src);
        }
    }

    if (ans.empty())
        cout << "None" << endl;
    else if (ans.size() == 2)
        cout << "Multiple" << endl;
    else {
        assert(ans.size() == 1);
        pii p = ans[0];
        cout << (char)('a' + p.y) << n - p.x << endl;
    }
    return 0;
}