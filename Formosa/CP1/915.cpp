#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
int record[32][32][16][16];

// AC

int query(int m, int n, int x, int y) {
    x = min(x, m - 1 - x);
    y = min(y, n - 1 - y);
    return record[m - 1][n - 1][x][y];
}

void insert(int m, int n, int x, int y, bool b) {
    x = min(x, m - 1 - x);
    y = min(y, n - 1 - y);
    record[m - 1][n - 1][x][y] = (b ? 1 : -1);
}

bool solve(int, int, int, int);

bool find(int m, int n, int x, int y) {
    for (int i = y; i < n - 1; i++) {
        if (!solve(m, i + 1, x, y)) return true;
    }
    for (int i = y; i > 0; i--) {
        if (!solve(m, n - i, x, y - i)) return true;
    }
    for (int i = x; i < m - 1; i++) {
        if (!solve(i + 1, n, x, y)) return true;
    }
    for (int i = x; i > 0; i--) {
        if (!solve(m - i, n, x - i, y)) return true;
    }
    return false;
}

bool solve(int m, int n, int x, int y) {
    if (n > m) {
        swap(m, n);
        swap(x, y);
    }
    if (n == 0) return true;
    x = min(x, m - 1 - x);
    y = min(y, n - 1 - y);

    int r = query(m, n, x, y);
    if (r != 0) return r == 1;

    bool res = find(m, n, x, y);
    insert(m, n, x, y, res);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x--;
        y--;
        cout << (solve(m, n, x, y) ? "Taberu\n" : "Tabehen\n");
    }
    return 0;
}