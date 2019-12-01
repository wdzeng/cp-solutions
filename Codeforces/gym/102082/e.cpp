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
vector<vector<bool>> e;
vector<int> deg;
vector<pii> ans;

void foul() {
    cout << -1 << endl;
    exit(0);
}

void link(int a, int b) {
    if (a == b) {
        cout << a << ',' << b << endl;
    }
    if (a > b) swap(a, b);
    deg[a]++, deg[b]++;
    e[a][b] = e[b][a] = 1;
    ans.push_back({a, b});
}

vector<vector<int>> get_packets() {
    bool vis[N];
    ms(vis);
    vector<vector<int>> packets;
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        packets.push_back({i});
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int a = 0; a < N; a++) {
                if (!e[a][v] || vis[a]) continue;
                vis[a] = 1;
                q.push(a);
                packets.back().push_back(a);
            }
        }
    }
    return packets;
}

void link_dots() {
    auto packets = get_packets();

    vector<int> dots;
    for (int i = 0; i < packets.size(); i++) {
        auto& p = packets[i];
        if (p.size() == 1) dots.push_back(p[0]);
    }

    if (dots.empty())
        return;
    else if (dots.size() == 1) {
        const int d = dots[0];
        for (int i = 0; i < N; i++) {
            if (deg[i] % 2 == 1) {
                link(i, d);
                return;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (!e[i][j] && d != i && d != j) {
                    link(d, i);
                    link(d, j);
                    link(i, j);
                    return;
                }
            }
        }
        foul();
    }  //
    else if (dots.size() == 2) {
        link(dots[0], dots[1]);
    }  //
    else {
        for (int i = 0; i < dots.size(); i++) {
            link(dots[i], dots[(i + 1) % dots.size()]);
        }
    }
}

void euler_add_edges(int p, int c, bool* vis) {
    for (int a = 0; a < N; a++) {
        if (vis[a] || e[a][c]) continue;
        vis[a] = 1;
        euler_add_edges(c, a, vis);
    }
    if (deg[c] % 2 == 1) {
        if (p == -1) foul();
        link(p, c);
    }
}

void euler_add_edges() {
    bool vis[N];
    ms(vis);
    for (int i = 0; i < N; i++)
        if (!vis[i]) {
            vis[i] = 1;
            euler_add_edges(-1, i, vis);
        }
}

void link_packets() {
    auto packets = get_packets();
    vector<pii> pairs;
    for (auto& p : packets) {
        pairs.push_back({p[0], p[1]});
    }

    for (int i = 1; i < pairs.size(); i++) {
        link(pairs.front().x, pairs[i].x);
        link(pairs.front().x, pairs[i].y);
        link(pairs.front().y, pairs[i].x);
        link(pairs.front().y, pairs[i].y);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N;
    e.assign(N, vector<bool>(N, 0));
    deg.assign(N, 0);

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a][b] = e[b][a] = 1;
        deg[a]++, deg[b]++;
    }

    link_dots();
    euler_add_edges();
    link_packets();

    cout << ans.size() << endl;
    for (pii& p : ans) {
        cout << p.x + 1 << ' ' << p.y + 1 << endl;
    }
    return 0;
}