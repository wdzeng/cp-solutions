#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

vector<vector<int>> paradox;
vector<int> color;
int N;

void suspect(int i) {
    vector<int> next;
    for (int px : paradox[i]) {
        if (color[px] == 0) {
            color[px] = -color[i];
            next.push_back(px);
        }
    }
    for (int px : next) suspect(px);
}

void join(vector<int>& v) {
    vector<int> p, n;
    for (int i = 0; i < N; i++) {
        if (color[i] == -1) {
            n.push_back(i);
            color[i] *= 2;
        } else if (color[i] == 1) {
            p.push_back(i);
            color[i] *= 2;
        }
    }
    if (p.size() < n.size())
        v.insert(v.end(), iter(p));
    else
        v.insert(v.end(), iter(n));
}

vector<int> solve() {
    vector<int> ret;
    for (int i = 0; i < N; i++) {
        if (color[i]) continue;
        color[i] = -1;
        suspect(i);
        join(ret);
    }
    if (ret.empty()) ret = {0};
    return ret;
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    cin >> N;
    vector<pair<string, int>> seen[N];
    paradox.resize(N), color.resize(N);
    for (int i = 0; i < N; i++) {
        string loc;
        cin >> loc;
        seen[i].emplace_back(loc, i);
        int nn;
        cin >> nn;
        for (int sn = 0; sn < nn; sn++) {
            int x;
            cin >> x;
            x--;
            seen[x].emplace_back(loc, i);
        }
    }
    for (int i = 0; i < N; i++) {
        for (auto& p : seen[i])
            for (auto q : seen[i])
                if (p.first != q.first) paradox[p.second].push_back(q.second), paradox[q.second].push_back(p.second);
    }

    auto murderer = solve();
    cout << murderer.size() << endl;
    for (int m : murderer) cout << m + 1 << " ";
    cout << endl;
    return 0;
}