#include <bits/stdc++.h>
using namespace std;

struct piece {
    int x, y;
    bool hor;
    int v1, v2;
};

vector<piece> pieces;
int table[6][6];
bool have[7][7];

int& t(int x, int y) { return table[y][x]; }

pair<int, int> next_empty() {
    for (int y = 1; y <= 5; y++)
        for (int x = 1; x <= 5; x++)
            if (t(x, y) == 0) return {x, y};
    throw "";
}

bool& h(int v1, int v2) { return have[min(v1, v2)][max(v1, v2)]; }

vector<int> row(int r) {
    vector<int> ret;
    for (int i = 1; i <= 5; i++) ret.push_back(table[r][i]);
    return ret;
}

vector<int> col(int c) {
    vector<int> ret;
    for (int i = 1; i <= 5; i++) ret.push_back(table[i][c]);
    return ret;
}

vector<int> dia1() {
    vector<int> ret;
    for (int i = 1; i <= 5; i++) ret.push_back(table[i][i]);
    return ret;
}

vector<int> dia2() {
    vector<int> ret;
    for (int i = 1; i <= 5; i++) ret.push_back(table[i][6 - i]);
    return ret;
}

int k3(const vector<int>& v) {
    for (int i = 1; i <= 6; i++) {
        int tt = 0;
        for (int x : v)
            if (x == i) tt++;
        if (tt == 3) return i * 3;
    }
    return 0;
}

int k4(const vector<int>& v) {
    for (int i = 1; i <= 6; i++) {
        int tt = 0;
        for (int x : v)
            if (x == i) tt++;
        if (tt == 4) return i * 4;
    }
    return 0;
}

int k5(const vector<int>& v) {
    for (int i = 1; i < 5; i++)
        if (v[i] != v[0]) return 0;
    return 50;
}

int fh(vector<int> v) {
    sort(v.begin(), v.end());
    return (v[1] == v[0] && v[4] == v[3] && (v[2] == v[0] || v[2] == v[3])) ? 25 : 0;
}

int ss(const vector<int>& v) {
    static set<int> ans1 = {1, 2, 3, 4};
    static set<int> ans2 = {2, 3, 4, 5};
    static set<int> ans3 = {3, 4, 5, 6};
    set<int> sset(v.begin(), v.end());
    return (includes(sset.begin(), sset.end(), ans1.begin(), ans1.end()) ||
            includes(sset.begin(), sset.end(), ans2.begin(), ans2.end()) ||
            includes(sset.begin(), sset.end(), ans3.begin(), ans3.end()))
               ? 30
               : 0;
}

int ls(const vector<int>& v) {
    static set<int> ans1 = {1, 2, 3, 4, 5};
    static set<int> ans2 = {2, 3, 4, 5, 6};
    set<int> sset(v.begin(), v.end());
    return (sset == ans1 || sset == ans2) ? 40 : 0;
}

int cal_score(vector<int> v, int& nk5) {
    if (k5(v)) return (++nk5 > 1) ? 100 : 50;
    if (ls(v)) return 40;
    if (ss(v)) return 30;
    if (fh(v)) return 25;
    int s;
    if (s = k4(v)) return s;
    if (s = k3(v)) return s;
    return 0;
}

int total_score() {
    int ret = 0;
    int nk5 = 0;
    for (int r = 1; r <= 5; r++) ret += cal_score(row(r), nk5);
    for (int c = 1; c <= 5; c++) ret += cal_score(col(c), nk5);
    ret += cal_score(dia1(), nk5);
    ret += cal_score(dia2(), nk5);
    return ret;
}

int solve() {
    memset(table, 0, sizeof(table));
    memset(have, false, sizeof(have));
    pieces.clear();

    for (int i = 0; i < 13; i++) {
        char c;
        cin >> c;
        auto p = next_empty();
        if (c == 'S') {
            cin >> t(p.first, p.second);
        }  //
        else if (c == 'H') {
            piece pc;
            pc.hor = true;
            cin >> pc.v1 >> pc.v2;
            t(p.first, p.second) = pc.v1;
            t(p.first + 1, p.second) = pc.v2;
            pc.x = p.first;
            pc.y = p.second;
            h(pc.v1, pc.v2) = true;
            pieces.push_back(pc);
        }  //
        else {
            piece pc;
            pc.hor = false;
            cin >> pc.v1 >> pc.v2;
            t(p.first, p.second) = pc.v1;
            t(p.first, p.second + 1) = pc.v2;
            pc.x = p.first;
            pc.y = p.second;
            h(pc.v1, pc.v2) = true;
            pieces.push_back(pc);
        }
    }

    vector<pair<int, int>> unused;
    for (int i = 1; i <= 6; i++)
        for (int j = i; j <= 6; j++)
            if (!h(i, j)) unused.push_back({i, j});

    int max_score = total_score();
    for (auto pc : pieces) {
        for (auto u : unused) {
            if (pc.hor) {
                t(pc.x, pc.y) = u.first;
                t(pc.x + 1, pc.y) = u.second;
                max_score = max(max_score, total_score());
                t(pc.x, pc.y) = u.second;
                t(pc.x + 1, pc.y) = u.first;
                max_score = max(max_score, total_score());
            }  //
            else {
                t(pc.x, pc.y) = u.first;
                t(pc.x, pc.y + 1) = u.second;
                max_score = max(max_score, total_score());
                t(pc.x, pc.y) = u.second;
                t(pc.x, pc.y + 1) = u.first;
                max_score = max(max_score, total_score());
            }
        }
        if (pc.hor) {
            t(pc.x, pc.y) = pc.v1;
            t(pc.x + 1, pc.y) = pc.v2;
        }  //
        else {
            t(pc.x, pc.y) = pc.v1;
            t(pc.x, pc.y + 1) = pc.v2;
        }
    }

    return max_score;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) printf("Case %d: %d\n", i, solve());
    return 0;
}