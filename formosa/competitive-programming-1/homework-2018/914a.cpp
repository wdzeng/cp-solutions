#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>
#define x first
#define y second
#define W 0
using namespace std;
typedef unsigned long state;
typedef pair<int, int> point;
typedef unordered_map<state, int> record;
typedef pair<state, point> board;
list<board> q[2];
record r[2];

// AC
// To save memory usage, a long integer is used to represent a state.

inline int idx(point& p) { return p.x * 5 + p.y; }

int lget(state s, int index) { return (s >> ((24 - index) * 2)) & 0b11; }
void lset(state& s, int index, unsigned long c) {
    int sh = (24 - index) * 2;
    unsigned long eraser = 0b11UL << sh;
    s &= (~eraser);
    c <<= sh;
    s |= c;
}
int h(char c) {
    switch (c) {
        case 'W':
            return 0b00;
        case 'P':
            return 0b01;
        case 'Y':
            return 0b10;
    }
    return 0b11;
}

bool add_state(point& org, point dst, state s, int step, int t, int& ans) {
    if (dst.x < 0 || dst.x > 4 || dst.y < 0 || dst.y > 4) return false;

    int tmp = lget(s, idx(dst));
    lset(s, idx(dst), W);
    lset(s, idx(org), tmp);
    int m = 1 - t;

    // Check match
    auto mit = r[m].find(s);
    if (mit != r[m].end()) {
        ans = step + mit->second;
        return true;
    }

    // Check unique
    auto checker = r[t].find(s);
    if (checker != r[t].end()) return false;

    r[t][s] = step;
    q[t].push_back({s, dst});
    return false;
}

int expand(int t) {
    board b = q[t].front();
    q[t].pop_front();
    state s = b.first;

    int step = r[t][s] + 1;
    if (step > 11) exit(-1);
    point src = b.second;
    int x = src.x, y = src.y;
    int ans;
    if (add_state(src, {x + 2, y + 1}, s, step, t, ans) || add_state(src, {x + 2, y - 1}, s, step, t, ans) ||
        add_state(src, {x + 1, y + 2}, s, step, t, ans) || add_state(src, {x + 1, y - 2}, s, step, t, ans) ||
        add_state(src, {x - 1, y + 2}, s, step, t, ans) || add_state(src, {x - 1, y - 2}, s, step, t, ans) ||
        add_state(src, {x - 2, y + 1}, s, step, t, ans) || add_state(src, {x - 2, y - 1}, s, step, t, ans)) {
        return ans;
    }
    return -1;
}

void update_board(board& b) {
    state s = 0;
    string a;
    point ret;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        for (int j = 0; j < 5; j++) {
            s <<= 2;
            s |= h(a[j]);
            if (a[j] == 'W') {
                b.second = {i, j};
            }
        }
    }
    b.first = s;
}

int solve() {
    board b0, b1;
    update_board(b0);
    update_board(b1);
    if (b0.first == b1.first) {
        return 0;
    }

    r[0].clear();
    r[1].clear();
    q[0].clear();
    q[1].clear();

    q[0].push_back(b0);
    q[1].push_back(b1);
    r[0][b0.first] = 0;
    r[1][b1.first] = 0;

    int ans;
    while (true) {
        ans = expand(0);
        if (ans != -1) return ans;
        ans = expand(1);
        if (ans != -1) return ans;
    }
    // Never reach here
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}