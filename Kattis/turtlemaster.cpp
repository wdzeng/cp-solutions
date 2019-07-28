#include <bits/stdc++.h>
using namespace std;
#define top 0
#define right 1
#define down 2
#define left 3

char mapp[8][9];

char& c(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) throw "";
    return mapp[y][x];
}

void laser(int tx, int ty, int dir) {
    /* switch (dir) {
        case top:
            for (int y = ty - 1;; y--) {
                if (c(tx, y) == 'I') {
                    c(tx, y) = '.';
                    return;
                }
                if (c(tx, y) != '.') throw "";
            }
            break;
        case down:
            for (int y = ty + 1;; y++) {
                if (c(tx, y) == 'I') {
                    c(tx, y) = '.';
                    return;
                }
                if (c(tx, y) != '.') throw "";
            }
            break;
        case right:
            for (int x = tx + 1;; x++) {
                if (c(x, ty) == 'I') {
                    c(x, ty) = '.';
                    return;
                }
                if (c(x, ty) != '.') throw "";
            }
            break;
        case left:
            for (int x = tx - 1;; x--) {
                if (c(x, ty) == 'I') {
                    c(x, ty) = '.';
                    return;
                }
                if (c(x, ty) != '.') throw "";
            }
            break;
    }
    throw ""; */
    int tarx, tary;
    switch (dir) {
        case top:
            tarx = tx;
            tary = ty - 1;
            break;
        case down:
            tarx = tx;
            tary = ty + 1;
            break;
        case left:
            tarx = tx - 1;
            tary = ty;
            break;
        case right:
            tarx = tx + 1;
            tary = ty;
            break;
    }
    if (c(tarx, tary) == 'I')
        c(tarx, tary) = '.';
    else
        throw "";
}

bool solve() {
    for (int i = 0; i < 8; i++) cin >> mapp[i];
    string inst;
    cin >> inst;
    int dir = right;
    int x = 0, y = 7;

    int dx, dy;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (c(i, j) == 'D') {
                dx = i;
                dy = j;
                c(i, j) = '.';
            }

    c(0, 7) = '.';

    for (char i : inst) {
        if (i == 'F') {
            switch (dir) {
                case top:
                    y--;
                    break;
                case left:
                    x--;
                    break;
                case down:
                    y++;
                    break;
                case right:
                    x++;
                    break;
            }
            if (c(x, y) != '.') throw "";
        } else if (i == 'R') {
            dir = (dir + 1) % 4;
        } else if (i == 'L') {
            dir = (dir - 1 + 4) % 4;
        } else if (i == 'X') {
            laser(x, y, dir);
        }
    }

    return x == dx && y == dy;
}

int main() {
    try {
        cout << (solve() ? "Diamond!" : "Bug!") << endl;
    } catch (...) {
        cout << "Bug!\n";
    }
    return 0;
}