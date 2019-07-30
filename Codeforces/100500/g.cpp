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
            /* if (is_valid({x - 1, y}, c, table) || is_valid({x + 1, y}, c, table) || is_valid({x, y - 1}, c, table) ||
                is_valid({x, y + 1}, c, table)) {
                  q.push({x, y});
            }  //
            else {
                continue;
            } */
            q.push({x, y});

            vector<point> ret;
            while (!q.empty()) {
                // cout << q.size() << endl;
                point p = q.front();
                // cout << p.x << p.y << endl;
                q.pop();
                ret.push_back(p);

                if (is_valid({p.x - 1, p.y}, c, table) && !visited[p.x - 1][p.y]) {
                    visited[p.x - 1][p.y] = true;
                    q.push({p.x - 1, p.y});
                };
                if (is_valid({p.x + 1, p.y}, c, table) && !visited[p.x + 1][p.y]) {
                    visited[p.x + 1][p.y] = true;
                    q.push({p.x + 1, p.y});
                };
                if (is_valid({p.x, p.y - 1}, c, table) && !visited[p.x][p.y - 1]) {
                    visited[p.x][p.y - 1] = true;
                    q.push({p.x, p.y - 1});
                };
                if (is_valid({p.x, p.y + 1}, c, table) && !visited[p.x][p.y + 1]) {
                    visited[p.x][p.y + 1] = true;
                    q.push({p.x, p.y + 1});
                };
            }
            // for (auto p : ret) cout << p.x << p.y << " ";
            // cout << endl;
            if (ret.size() > 1) found.push_back(ret);
        }
    return found;
}

bool clear(const vector<string>& table) {
    for (int i = 0; i < 5; i++)
        if (table[i] != "......") return false;
    return true;
}

string strtable(const vector<string>& table) {
    string s = "";
    for (string a : table) s += a;
    return s;
}

bool judge(const vector<string>& table) {
    // string s;
    // getline(cin, s);

    auto v = find(table);
    // cout << v.size() << endl;
    // while (!v.empty()) {
    // for (string s : table) cout << s << endl;
    // cout << endl;

    // cout << v.size() << endl;
    for (auto& p : v) {
        auto tt = table;
        for (auto& loc : p) tt[loc.x][loc.y] = '.';
        for (int y = 0; y < 6; y++) {
            for (int x = 4; x > -1; x--) {
                if (tt[x][y] != '.') continue;
                for (int u = x - 1; u > -1; u--) {
                    if (tt[u][y] != '.') {
                        tt[x][y] = tt[u][y];
                        tt[u][y] = '.';
                        break;
                    }
                }
            }
        }

        bool cleared[6] = {false};
        for (int y = 0; y < 6; y++) {
            cleared[y] = [&] {
                for (int x = 0; x < 5; x++) {
                    if (tt[x][y] != '.') return false;
                }
                return true;
            }();
        }
        for (int y = 0; y < 6; y++) {
            if (!cleared[y]) continue;
            int r = -1;
            for (int u = y + 1; u < 6; u++) {
                if (!cleared[u]) {
                    r = u;
                    break;
                }
            }
            if (r == -1) break;
            for (int x = 0; x < 5; x++) {
                tt[x][y] = tt[x][r];
                tt[x][r] = '.';
            }
            cleared[r] = true;
        }

      //  for(string s: tt) cout << s << endl;
      //  cout << endl;

        if (clear(tt)) return true;
        string h = strtable(tt);
        // cout << h << endl;
        if (record.count(h)) continue;
        record.insert(h);
        if (judge(tt)) return true;
        //}

        // v = find(tt);
    }

    return false;
}

bool solve() {
    vector<string> table(5);
    for (int i = 0; i < 5; i++) cin >> table[i];
    // for (string s : table) cout << s << endl;
    // cout << endl;
    record.clear();
    record.insert(strtable(table));
    return judge(table);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) printf("Case %d: %s\n", i, solve() ? "Yes" : "No");
    return 0;
}