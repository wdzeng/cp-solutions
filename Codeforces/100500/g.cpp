#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;
#define x first
#define y second

bool is_valid(point p, char c, const vector<string>& table) {
    if (p.x < 0 || p.x >= 5 || p.y < 0 || p.y >= 6) return false;
    return table[p.x][p.y] == c;
}

unordered_set<string> record;

vector<vector<point>> find(const vector<string>& table) {
    bool visited[5][6];
    memset(visited, false, sizeof(visited));
    vector<vector<point>> found;
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 6; y++) {
            if (visited[x][y]) continue;
            visited[x][y] = true;

            const char c = table[x][y];
            if (c == '.') continue;

            queue<point> q;
            q.push({x, y});

            auto test = [&](int x, int y) {
                if (is_valid({x, y}, c, table) && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            };

            vector<point> ret;
            while (!q.empty()) {
                point p = q.front();
                q.pop();
                ret.push_back(p);
                test(p.x - 1, p.y);
                test(p.x + 1, p.y);
                test(p.x, p.y - 1);
                test(p.x, p.y + 1);
            }
            if (ret.size() > 1) found.push_back(ret);
        }
    return found;
}

bool is_stage_clear(const vector<string>& table) {
    for (int i = 0; i < 5; i++)
        if (table[i] != "......") return false;
    return true;
}

string table2str(const vector<string>& table) {
    string s = "";
    for (string a : table) s += a;
    return s;
}

bool judge(const vector<string>& table) {
    auto v = find(table);
    for (auto& p : v) {
        auto tt = table;
        for (auto& loc : p) tt[loc.x][loc.y] = '.';
        for (int y = 0; y < 6; y++) {
            for (int x = 4; x > -1; x--) {
                if (tt[x][y] != '.') continue;
                for (int u = x - 1; u > -1; u--) {
                    if (tt[u][y] != '.') {
                        swap(tt[x][y], tt[u][y]);
                        break;
                    }
                }
            }
        }

        bool cleared[6] = {false};
        for (int y = 0; y < 6; y++) {
            cleared[y] = [&] {
                for (int x = 0; x < 5; x++)
                    if (tt[x][y] != '.') return false;
                return true;
            }();
        }
        for (int y = 0; y < 6; y++) {
            if (!cleared[y]) continue;
            int r = [&]() {
                for (int u = y + 1; u < 6; u++)
                    if (!cleared[u]) return u;
                return -1;
            }();
            if (r == -1) break;
            for (int x = 0; x < 5; x++) swap(tt[x][y], tt[x][r]);
            cleared[r] = true;
        }

        if (is_stage_clear(tt)) return true;
        string h = table2str(tt);
        if (record.count(h)) continue;
        record.insert(h);
        if (judge(tt)) return true;
    }

    return false;
}

bool solve() {
    vector<string> table(5);
    for (int i = 0; i < 5; i++) cin >> table[i];
    record.clear();
    record.insert(table2str(table));
    return judge(table);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) printf("Case %d: %s\n", i, solve() ? "Yes" : "No");
    return 0;
}