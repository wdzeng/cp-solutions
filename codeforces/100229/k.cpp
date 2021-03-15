#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

const int C = 26;
const int REV = 1;
int g[C][C];
int deg[C];

void solve() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int x = s[0] - 'a';
        int y = s[1] - 'a';
        g[x][y] = REV ? 1 : 0;
    }

    // find aa
    for (int i = 0; i < C; i++) {
        if (g[i][i]) {
            for (int x = 0; x < 20; x++) {
                for (int y = 0; y < 20; y++) {
                    cout << (char)(i + 'a');
                }
                cout << endl;
            }
            return;
        }
    }

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            if (g[i][j]) deg[i]++;
        }
    }

    // find ring
    queue<int> q;
    pair<int, int> qd[C];
    for (int i = 0; i < C; i++) {
        qd[i] = {i, 0};
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < C; i++) {
            if (g[i][u]) {
                g[i][u] = 0;

                int newdist = qd[u].y + 1;
                if (newdist > qd[i].y) {
                    qd[i].y = newdist;
                    qd[i].x = u;
                    //cout << (char)(i + 'a') << " follows " << (char)(u + 'a') << ' ' << newdist << endl;
                }

                deg[i]--;
                assert(deg[i] >= 0);
                if (deg[i] == 0) {
                    q.push(i);
                }
            }
        }
    }

    int isdag = 1;
    for (int i = 0; i < C; i++) {
        if (deg[i]) isdag = 0;
    }

    if (isdag) {
        //cout << "DAG" << endl;
        int fsIndex = 0;
        for (int i = 1; i < C; i++) {
            if (qd[i].y > qd[fsIndex].y) fsIndex = i;
        }
        vector<int> link = {fsIndex};
        int cur = fsIndex;
        while (qd[cur].x != cur) {
            cur = qd[cur].x;
            link.push_back(cur);
        }
        //cout << ">>"; for(int l: link) cout << (char)(l + 'a'); cout << endl;

        int len = link.size();
        assert(len == qd[fsIndex].y + 1);
        int ans;
        if (len % 2 == 1) {
            ans = (len / 2) + 1;
        } else {
            ans = (len / 2);
        }

        for (int i = 0; i < ans; i++) {
            for (int j = 0; j < ans; j++) {
                int index = i + j;
                assert(index < link.size());
                cout << (char)(link[index] + 'a');
            }
            cout << endl;
        }
        return;
    }

    //cout << "RING" << endl;

    // has ring
    int start = -1;
    for (int i = 0; i < C; i++)
        if (deg[i]) start = i;
    assert(start != -1);

    // start is on a ring
    int prev[C];
    mss(prev);
    prev[start] = start;
    //int end = -1;

    vector<int> ring;
    auto ringFinder = [&](int u, auto self) -> bool {
        for (int i = 0; i < C; i++) {
            if (g[u][i]) {
                if (prev[i] != -1) {
                    // find a ring
                    ring.push_back(u);
                    return true;
                } else {
                    prev[i] = u;
                    bool ret = self(i, self);
                    if (ret) {
                        ring.push_back(u);
                        return true;
                    }
                }
            }
        }
        return false;
    };
    ringFinder(start, ringFinder);

    //debug((char)(start + 'a'));
    //d/ebug((char)(end + 'a'));
    //assert(start != end);
    //assert(end != -1);
    // vector<int> ring = {end};
    // while (ring.back() != start) ring.push_back(prev[ring.back()]);
    reverse(all(ring));
    // cout << ">> "; for (int r : ring) cout << (char)('a' + r); cout << endl;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            int index = i + j;
            char c = ring[index % ring.size()] + 'a';
            cout << c;
        }
        cout << endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++) g[i][j] = REV ? 0 : 1;
        ms(deg);
        solve();
    }
    return 0;
}