#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
const int maxn = 302;
int n, k;
int edge[maxn][maxn];

vector<int> flow() {
    queue<int> q;
    q.push(n);
    vector<int> path(n + 2, -1);
    path[n] = -2;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = 0; j < n + 2; j++) {
            if (edge[i][j] && path[j] == -1) {
                path[j] = i;
                if (j == n + 1) return path;
                q.push(j);
            }
        }
    }
    return {};
}

pii hothot(const string& state) {
    for (int i = 0; i < n; i++) {
        if (state[i] == '.') continue;
        for (int j = 0; j < n; j++) {
            if (edge[i][j] && state[j] != '+') return {i, j};
        }
    }
    throw "";
}

list<pii> solve(const string& s0, const string& s1) {
    int edgecpy[maxn][maxn];
    memcpy(edgecpy, edge, sizeof(edge));

    vector<int> path;
    int nflow = 0;
    while (!(path = flow()).empty()) {
        for (int i = n + 1; i != n; i = path[i]) {
            edge[i][path[i]]++;
            edge[path[i]][i]--;
        }
        nflow++;
    }
    if (nflow != k) return {};

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            edge[i][j] = max(0, edgecpy[i][j] - edge[i][j]);
        }
    }

    list<pii> ret;
    string state = s0;
    while (state != s1) {
        pii p = hothot(state);
        swap(state[p.first], state[p.second]);
        ret.push_back(p);
        edge[p.first][p.second]--;
    }
    if (ret.empty()) throw "";
    return ret;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    cin >> n >> k;
    string s0, s1;
    for (int i = 0; i < n; i++) {
        s0.push_back('.'), s1.push_back('.');
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        s0[x] = '+';
        edge[n][x] = 1;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        s1[x] = '+';
        edge[x][n + 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') edge[i][j] = k;
        }
    }

    if (s0 == s1) {
        cout << "YES\n0\n";
        return 0;
    }
    auto ls = solve(s0, s1);
    if (ls.empty()) {
        cout << "NO\n";
        return 0;
    } else {
        cout << "YES\n";
        cout << ls.size() << "\n";
        for (pii& p : ls) cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
    return 0;
}