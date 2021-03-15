#include <cstdio>
using namespace std;
int n, a[50000][10], e, b[50000][10], e2;
int main() {
    scanf("%d", &n);
    if (n == 1) {
        puts("1");
        return 0;
    }
    e = 1;
    a[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        e2 = 0;
        for (int j = 1; j <= e; ++j) {
            if (j % 2 == 1) {
                for (int k = i; k >= 1; --k) {
                    int cnt = 0;
                    ++e2;
                    if (k == 1) {
                        ++cnt;
                        b[e2][cnt] = i;
                        if (i == n) printf("%d%c", b[e2][cnt], cnt == i ? '\n' : ' ');
                    }
                    for (int l = 1; l < i; ++l) {
                        ++cnt;
                        b[e2][cnt] = a[j][l];
                        if (i == n) printf("%d%c", b[e2][cnt], cnt == i ? '\n' : ' ');
                        if (l == k - 1) {
                            ++cnt;
                            b[e2][cnt] = i;
                            if (i == n) printf("%d%c", b[e2][cnt], cnt == i ? '\n' : ' ');
                        }
                    }
                }
            } else {
                for (int k = 1; k <= i; ++k) {
                    int cnt = 0;
                    ++e2;
                    if (k == 1) {
                        ++cnt;
                        b[e2][cnt] = i;
                        if (i == n) printf("%d%c", b[e2][cnt], cnt == i ? '\n' : ' ');
                    }
                    for (int l = 1; l < i; ++l) {
                        ++cnt;
                        b[e2][cnt] = a[j][l];
                        if (i == n) printf("%d%c", b[e2][cnt], cnt == i ? '\n' : ' ');
                        if (l == k - 1) {
                            ++cnt;
                            b[e2][cnt] = i;
                            if (i == n) printf("%d%c", b[e2][cnt], cnt == i ? '\n' : ' ');
                        }
                    }
                }
            }
        }
        e = e2;
        for (int j = 1; j <= e2; ++j) {
            for (int k = 1; k <= i; ++k) {
                a[j][k] = b[j][k];
            }
        }
    }
    return 0;
}