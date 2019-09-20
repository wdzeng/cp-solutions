#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

inline void foul() {
    cout << "impossible\n";
    exit(0);
}

struct puzzle {
    const int index;
    int top, left, bottom, right;
    puzzle *nextline = NULL, *next = NULL;

    puzzle(int i, int t, int l, int b, int r) : index(i), top(t), left(l), bottom(b), right(r) {}

    inline void rotate() {
        int tmp = top;
        top = right;
        right = bottom;
        bottom = left;
        left = tmp;
    }

    inline void concat_right(puzzle* pz) {
        while (pz->left != right) pz->rotate();
        next = pz;
    }

    inline void concat_bottom(puzzle* pz) {
        while (pz->top != bottom) pz->rotate();
        nextline = pz;
    }
};

const int maxn = 3e5 + 10;
bitset<maxn> vis;
vector<puzzle*> puzzles;
vector<pii> edges;

int N, R = 0, C;
puzzle* root = NULL;

inline void add_edge(int e, int i) {
    if (e == 0) return;
    if (e >= edges.size()) foul();
    (edges[e].x == -1 ? edges[e].x : edges[e].y) = i;
}

void set_root_if_valid(puzzle* pz) {
    for (int j = 0; j < 3; j++) {
        if (pz->left == 0 && pz->top == 0) {
            root = pz;
            vis[pz->index] = 1;
            break;
        }
        pz->rotate();
    }
}

void get_input() {
    cin >> N;
    edges.assign(N * 2, {-1, -1});
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        puzzle* pz = new puzzle(i, a, b, c, d);
        add_edge(a, i);
        add_edge(b, i);
        add_edge(c, i);
        add_edge(d, i);
        puzzles.push_back(pz);
        if (root == NULL) set_root_if_valid(pz);
    }
}

void assemble_puzzles() {
    auto linkright = [&](puzzle* src) -> puzzle* {
        int e = src->right;
        if (!e) return NULL;
        auto& e2 = edges[e];
        if (vis[e2.x] && vis[e2.y]) foul();
        int v = vis[e2.x] ? e2.y : e2.x;
        vis[v] = 1;
        src->concat_right(puzzles[v]);
        return src->next;
    };
    auto linkbottom = [&](puzzle* src) -> puzzle* {
        int e = src->bottom;
        if (!e) return NULL;
        auto& e2 = edges[e];
        if (vis[e2.x] && vis[e2.y]) foul();
        int v = vis[e2.x] ? e2.y : e2.x;
        vis[v] = 1;
        src->concat_bottom(puzzles[v]);
        return src->nextline;
    };

    auto topleft = root;
    while (topleft) {
        if (topleft->left != 0) foul();
        R++;
        auto bottomright = topleft;
        int counter = 1;
        while (bottomright = linkright(bottomright)) {
            if (topleft == root && bottomright->top != 0) foul();
            counter++;
        }
        if (topleft == root) C = counter;
        if (C != counter) foul();
        topleft = linkbottom(topleft);
    }
    if (R * C != N) foul();
}

void check_edges() {
    puzzle* upper = root;
    puzzle* lower;
    while (upper) {
        lower = upper->nextline;
        puzzle* r1 = upper;
        puzzle* r2 = lower;
        while (r1) {
            if (r2) {
                if (r1->bottom == 0) foul();
                if (r1->bottom != r2->top) foul();
                r2 = r2->next;
            }  //
            else {
                if (r1->bottom != 0) foul();
            }
            r1 = r1->next;
        }
        upper = lower;
    }
}

void print_puzzles() {
    cout << R << ' ' << C << '\n';
    auto topleft = root;
    while (topleft) {
        auto bottomright = topleft;
        while (bottomright) {
            cout << bottomright->index + 1 << ' ';
            bottomright = bottomright->next;
        }
        cout << '\n';
        topleft = topleft->nextline;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    get_input();
    assemble_puzzles();
    check_edges();
    print_puzzles();
    return 0;
}