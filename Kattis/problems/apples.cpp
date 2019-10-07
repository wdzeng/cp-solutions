#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char arr[n][m + 1];
    char ans[n][m];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int c = 0; c < m; c++) {
        int nApple = 0;
        for (int r = 0; r < n; r++) {
            if (arr[r][c] == 'a')
                nApple++;
            else if (arr[r][c] == '#') {
                int x = r - 1;
                for (int i = 0; i < nApple; i++, x--) {
                    ans[x][c] = 'a';
                }
                nApple = 0;
            }
        }
        int x = n - 1;
        for (int i = 0; i < nApple; i++, x--) {
            ans[x][c] = 'a';
        }
        nApple = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 'a')
                cout << 'a';
            else if (arr[i][j] == '#')
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
    }
    return 0;
}