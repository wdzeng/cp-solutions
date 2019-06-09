#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
unordered_map<string, int> record[2];
list<pair<string, int>> queue[2];

// AC
// To decrease the code length, a string is used to represent a state.

inline int row(int index) { return index / 5; }
inline int col(int index) { return index % 5; }
inline int idx(int r, int c) { return r * 5 + c; }

bool expand(int src, int rd, int cd, int cid, string state, int step, int& flag) {
    if (rd < 0 || rd > 4 || cd < 0 || cd > 4) return false;

    int dst = idx(rd, cd);
    char tmp = state[dst];
    state[dst] = 'W';
    state[src] = tmp;

    auto mit = record[1 - cid].find(state);
    if (mit != record[1 - cid].end()) {
        flag = step + mit->second;
        return true;
    }

    auto cit = record[cid].find(state);
    if (cit != record[cid].end()) return false;

    queue[cid].push_back({state, dst});
    record[cid][state] = step;
    return false;
}

int next(int cid) {
    auto nxt = queue[cid].front();
    queue[cid].pop_front();

    int src = nxt.second, r = row(src), c = col(src);
    string state = nxt.first;
    int step = record[cid][state] + 1;
    int flag;

    if (expand(src, r + 2, c - 1, cid, state, step, flag) || expand(src, r + 2, c + 1, cid, state, step, flag) ||
        expand(src, r - 2, c - 1, cid, state, step, flag) || expand(src, r - 2, c + 1, cid, state, step, flag) ||
        expand(src, r + 1, c - 2, cid, state, step, flag) || expand(src, r + 1, c + 2, cid, state, step, flag) ||
        expand(src, r - 1, c - 2, cid, state, step, flag) || expand(src, r - 1, c + 2, cid, state, step, flag)) {
        return flag;
    }
    return -1;
}

int update(string& s) {
    s = "";
    string a;
    int ret;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        s += a;
        for (int j = 0; j < 5; j++) {
            if (a[j] == 'W') ret = idx(i, j);
        }
    }
    return ret;
}

int solve() {
    string src, dst;
    int w0 = update(src);
    int w1 = update(dst);
    if (src == dst) return 0;

    record[0].clear();
    record[1].clear();
    queue[0].clear();
    queue[1].clear();
    queue[0].push_back({src, w0});
    queue[1].push_back({dst, w1});

    int flag;
    while (true) {
        flag = next(0);
        if (flag != -1) break;
        flag = next(1);
        if (flag != -1) break;
    }
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}