#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

inline int dist(pii& a, pii b) { return abs(a.x - b.x) + abs(a.y - b.y); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, S, P;
    cin >> R >> S >> P;
    pii door = {R - 1, S};
    int mxdist = -1;
    map<int, int> mmap;

    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (y >= S) y++;
        int d = dist(door, make_pair(x, y));
        mmap[d]++;
        mxdist = max(mxdist, d);
    }
    mxdist++;
    
    int lsx = 0;
    int conf = 0;
    for (auto& p : mmap) {
        if (p.x > lsx + conf) conf = 0;
        conf += p.y - 1;
        lsx = p.x;
    }
    cout << mxdist + conf << endl;

    return 0;
}