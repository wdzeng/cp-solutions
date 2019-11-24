#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> Table;
#define x first
#define y second

class Car {
   public:
    bool horizon;
    int length;
    int x, y;

    Car(bool h, int l, int x, int y) : horizon(h), length(l), x(x), y(y) { assert(length == 2 or length == 3); }
    Car() : Car(0, 0, 0, 0) {}
    bool at(int xx, int yy) const {
        if (horizon) {
            if (x != xx) return 0;
            return y <= yy and yy < y + length;
        } else {
            if (y != yy) return 0;
            return x <= xx and xx < x + length;
        }
    }
    bool operator<(const Car& c) const {
        if (horizon != c.horizon) return horizon < c.horizon;
        if (length != c.length) return length < c.length;
        if (x != c.x) return x < c.x;
        return y < c.y;
    }
};

typedef vector<Car> CarVec;

bool is_space_empty(int ex, const CarVec& cc, const pii& loc) {
    for (int i = 1; i < cc.size(); i++) {
        if (i == ex) continue;
        if (cc[i].at(loc.x, loc.y)) return 0;
    }
    return 1;
}

void expand(int i, const CarVec& cc, int s, map<CarVec, int>& m, queue<CarVec>& q) {
    const Car& c = cc[i];
    vector<pair<pii, pii>> clocs;
    if (c.horizon) {
        if (c.y > 0) clocs.push_back({{c.x, c.y - 1}, {c.x, c.y - 1}});
        if (c.y + c.length < 6) clocs.push_back({{c.x, c.y + 1}, {c.x, c.y + c.length}});
    }  //
    else {
        if (c.x > 0) clocs.push_back({{c.x - 1, c.y}, {c.x - 1, c.y}});
        if (c.x + c.length < 6) clocs.push_back({{c.x + 1, c.y}, {c.x + c.length, c.y}});
    }

    for (auto& cloc : clocs) {
        if (!is_space_empty(i, cc, cloc.y)) continue;
        CarVec updatedCar = cc;
        updatedCar[i].x = cloc.x.x, updatedCar[i].y = cloc.x.y;
        if (!m.count(updatedCar)) {
            m[updatedCar] = s;
            q.push(updatedCar);
        }
    }
}

CarVec makecar(Table& arr, int ncar) {
    CarVec ret(ncar + 1);
    vector<int> vis(ncar + 1);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int carId = arr[i][j];
            if (carId == 0 or vis[carId]) continue;
            if (i <= 3 and arr[i + 1][j] == carId and arr[i + 2][j] == carId)
                ret[carId] = Car(0, 3, i, j);
            else if (i <= 4 and arr[i + 1][j] == carId)
                ret[carId] = Car(0, 2, i, j);
            else if (j <= 3 and arr[i][j + 1] == carId and arr[i][j + 2] == carId)
                ret[carId] = Car(1, 3, i, j);
            else if (j <= 4 and arr[i][j + 1] == carId)
                ret[carId] = Car(1, 2, i, j);
            vis[carId] = 1;
        }
    }
    assert(vis.size() == ncar);
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    Table g(6, vector<int>(6));
    int ncar = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> g[i][j];
            ncar = max(g[i][j], ncar);
        }
    }

    queue<CarVec> q;
    map<CarVec, int> m;
    CarVec src = makecar(g, ncar);
    q.push(src);
    m[src] = 0;

    while (!q.empty()) {
        CarVec v = q.front();
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

/*
2 2 0 0 0 7
3 0 0 5 0 7
3 1 1 5 0 7
3 0 0 5 0 0
4 0 0 0 8 8
4 0 6 6 6 0

0 2 0 6 6 0
0 2 0 0 7 0
0 3 1 1 7 0
0 3 4 4 8 0
0 5 5 5 8 0
0 0 0 0 0 0
*/
