#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> grid;
#define x first
#define y second
const int E = 6;

class car {
   public:
    bool horizon;
    int length;
    int x, y;

    car(bool h, int l, int x, int y) : horizon(h), length(l), x(x), y(y) { assert(length == 2 or length == 3); }
    car() {}
    bool occupy(int xx, int yy) const {
        if (horizon) {
            if (x != xx) return 0;
            return y <= yy and yy < y + length;
        }  //
        else {
            if (y != yy) return 0;
            return x <= xx and xx < x + length;
        }
    }
    bool operator<(const car& c) const {
        if (horizon != c.horizon) return horizon < c.horizon;
        if (length != c.length) return length < c.length;
        if (x != c.x) return x < c.x;
        return y < c.y;
    }
};

typedef vector<car> state;

inline bool is_valid(int ex, const state& cc, const pii& loc) {
    for (int i = 1; i < cc.size(); i++) {
        if (i == ex) continue;
        if (cc[i].occupy(loc.x, loc.y)) return 0;
    }
    return 1;
}

void expand(int i, const state& cc, int s, map<state, int>& m, queue<state>& q) {
    const car& c = cc[i];
    vector<pair<pii, pii>> loc_candidates;
    if (c.horizon) {
        if (c.y > 0) loc_candidates.push_back({{c.x, c.y - 1}, {c.x, c.y - 1}});
        if (c.y + c.length < E) loc_candidates.push_back({{c.x, c.y + 1}, {c.x, c.y + c.length}});
    }  //
    else {
        if (c.x > 0) loc_candidates.push_back({{c.x - 1, c.y}, {c.x - 1, c.y}});
        if (c.x + c.length < E) loc_candidates.push_back({{c.x + 1, c.y}, {c.x + c.length, c.y}});
    }

    for (const auto& cloc : loc_candidates) {
        if (!is_valid(i, cc, cloc.y)) continue;
        state updatedCar = cc;
        updatedCar[i].x = cloc.x.x, updatedCar[i].y = cloc.x.y;
        if (!m.count(updatedCar)) {
            m[updatedCar] = s;
            q.push(updatedCar);
        }
    }
}

state get_cars(grid& g, int ncar) {
    state ret(ncar + 1);
    vector<int> vis(ncar + 1);
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < E; j++) {
            int carId = g[i][j];
            if (carId == 0 or vis[carId]) continue;
            if (i <= 3 and g[i + 1][j] == carId and g[i + 2][j] == carId)
                ret[carId] = car(0, 3, i, j);
            else if (i <= 4 and g[i + 1][j] == carId)
                ret[carId] = car(0, 2, i, j);
            else if (j <= 3 and g[i][j + 1] == carId and g[i][j + 2] == carId)
                ret[carId] = car(1, 3, i, j);
            else if (j <= 4 and g[i][j + 1] == carId)
                ret[carId] = car(1, 2, i, j);
            vis[carId] = 1;
        }
    }
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    grid g(E, vector<int>(E));
    int ncar = 0;
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < E; j++) {
            cin >> g[i][j];
            ncar = max(g[i][j], ncar);
        }
    }

    queue<state> q;
    map<state, int> m;
    state src = get_cars(g, ncar);
    q.push(src);
    m[src] = 0;

    while (!q.empty()) {
        state v = q.front();
        q.pop();
        int s = m[v];
        if (s + 2 > 10) {
            cout << -1 << endl;
            return 0;
        }
        if (v[1].x == 2 and v[1].y == 4) {
            cout << s + 2 << endl;
            return 0;
        }
        for (int i = 1; i <= ncar; i++) expand(i, v, s + 1, m, q);
    }
    cout << -1 << endl;
    return 0;
}
