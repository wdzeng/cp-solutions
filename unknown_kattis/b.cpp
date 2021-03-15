#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;
const int N = 510;
int sc[N][N];
int d[N][N];
int w[N][N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int c, e;
    cin >> c >> e;
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < c; j++) {
            cin >> sc[i][j];
            if (!sc[i][j]) sc[i][j] = inf;
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = i + 1; j < c; j++) {
            for (int a = 0; a < e; a++) {
                int sci = sc[a][i], scj = sc[a][j];
                if (sci < scj)
                    d[i][j]++;
                else if (scj < sci)
                    d[j][i]++;
            }
            if (d[i][j] > d[j][i])
                w[i][j] = d[i][j];
            else if (d[i][j] < d[j][i])
                w[j][i] = d[j][i];
        }
    }

    for (int i = 0; i < c; i++) w[i][i] = inf;
    for (int k = 0; k < c; k++)
        for (int i = 0; i < c; i++)
            for (int j = 0; j < c; j++)
                w[i][j] = max(w[i][j], min(w[i][k], w[k][j]));

    for (int i = 0; i < c; i++) {
        int ok = 1;
        for (int j = 0; j < c; j++)
            if (w[i][j] < w[j][i])
                ok = 0;
        if (ok) cout << i + 1 << ' ';
    }
    cout << '\n';

    return 0;
}