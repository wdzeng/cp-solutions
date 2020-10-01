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
int g[N][N];
vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int x, y;
    cin >> x >> y;
    vector<string> mmap;

    string b;
    for (int i = 0; i < y + 2; i++) {
        b.push_back('.');
    }

    mmap.push_back(b);
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        string ss = ".";
        ss += s;
        ss += ".";
        mmap.push_back(ss);
    }
    mmap.push_back(b);
    x += 2;
    y += 2;

    mss(g);
    queue<pii> q;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (mmap[i][j] == '.') {
                g[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (nx < 0 or nx >= x or ny < 0 or ny >= y) continue;
            int sc = g[u.x][u.y] + 1;
            if (g[nx][ny] != -1) continue;
            g[nx][ny] = sc;
            q.emplace(nx, ny);
        }
    }

    int mxx = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            mxx = max(mxx, g[i][j]);
        }
    }

    for (int i = 1; i + 1 < x; i++) {
        for (int j = 1; j + 1 < y; j++) {
            if (mxx < 10) {
                if (g[i][j] == 0)
                    printf("..");
                else
                    printf(".%d", g[i][j]);
            } else {
                if (g[i][j] == 0)
                    printf("...");
                else if (g[i][j] < 10)
                    printf("..%d", g[i][j]);
                else if (g[i][j] < 100)
                    printf(".%d", g[i][j]);
                else
                    printf("%d", g[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}