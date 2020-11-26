#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 105;
int lft[N][N], frt[N][N];
int X, Y, Z;

struct piii {
    int x, y, z;
    bool operator<(const piii& o) const {
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        return z < o.z;
    }
};

bool solve1() {
    vector<piii> ans;
    int lv[N][N], fv[N][N];
    ms(lv);
    ms(fv);
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            if (!lft[x][y]) continue;
            for (int z = 0; z < Z; z++) {
                if (!frt[x][z]) continue;
                ans.push_back({x, y, z});
                lv[x][y] = 1;
                fv[x][z] = 1;
            }
        }
    }

    bool ok = 1;
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < Y; y++) {
            if (lft[x][y] and !lv[x][y]) ok = 0;
        }
        for (int z = 0; z < Z; z++) {
            if (frt[x][z] and !fv[x][z]) ok = 0;
        }
    }

    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << '\n';
    for (auto& p : ans) cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
    return 1;
}

bool solve2() {
    vector<piii> ans;
    for (int x = 0; x < X; x++) {
        vector<int> yy, zz;
        for (int y = 0; y < Y; y++)
            if (lft[x][y]) yy.push_back(y);
        for (int z = 0; z < Z; z++)
            if (frt[x][z]) zz.push_back(z);

        if (yy.empty() and zz.empty()) continue;
        assert(!yy.empty() and !zz.empty());

        if (yy.size() <= zz.size()) {
            int yyy = yy[0];
            while (!zz.empty()) {
                ans.push_back({x, yy.empty() ? yyy : yy.back(), zz.back()});
                if (!yy.empty()) yy.pop_back();
                zz.pop_back();
            }
        } else {
            int zzz = zz[0];
            while (!yy.empty()) {
                ans.push_back({x, yy.back(), zz.empty() ? zzz : zz.back()});
                yy.pop_back();
                if (!zz.empty()) zz.pop_back();
            }
        }
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto& p : ans) cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> X >> Y >> Z;
    for (int x = 0; x < X; x++) {
        string str;
        cin >> str;
        for (int y = 0; y < Y; y++) {
            lft[x][y] = str[y] == '1';
        }
    }

    for (int x = 0; x < X; x++) {
        string str;
        cin >> str;
        for (int z = 0; z < Z; z++) {
            frt[x][z] = str[z] == '1';
        }
    }

    solve1() and solve2();
    return 0;
}