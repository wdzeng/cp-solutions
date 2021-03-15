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

inline void bad() {
    cout << "-1\n";
    exit(0);
}

const int N = 4010;
int need[N];
int most[N];
int active[N];
vector<int> ans[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, w, h;
    cin >> m >> n >> w >> h;
    for (int i = 0; i < m; i++) cin >> most[i];
    for (int i = 0; i < n; i++) cin >> need[i];
    for (int i = 0; i < m; i++)
        if (most[i] % w) bad();
    int s = 0;
    for (int i = 0; i < m; i++) s += most[i];
    for (int i = 0; i < n; i++) s -= need[i];
    if (s) bad();

    for (int i = 0; i < m; i++) most[i] /= w;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < w; j++) need[i + j] -= need[i];
    }
    for (int i = 0; i < N; i++)
        if (need[i] < 0) bad();
    for (int i = n; i < N; i++)
        if (need[i] > 0) bad();

    vector<int> req;
    for (int i = 0; i < n; i++)
        for (int a = 0; a < need[i]; a++) req.push_back(i);
    queue<pii> rest;
    priority_queue<pii> workers;
    for (int i = 0; i < m; i++) workers.emplace(most[i], i);
    for (int d : req) {
        while (!rest.empty()) {
            auto& u = rest.front();
            int id = u.y;
            if (active[id] <= d) {
                workers.push(u);
                rest.pop();
                continue;
            }
            break;
        }
        if (workers.empty()) bad();
        auto u = workers.top();
        workers.pop();
        int id = u.y;
        int rem = u.x;
        active[id] = d + w + h;
        ans[id].push_back(d);
        if (rem - 1 > 0)
            rest.emplace(rem - 1, id);
    }

    cout << "1\n";
    for (int i = 0; i < m; i++) {
        for (int a : ans[i]) cout << a + 1 << ' ';
        cout << '\n';
    }

    return 0;
}