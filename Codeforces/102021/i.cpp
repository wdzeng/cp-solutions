#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int main() {
    int n;
    scanf("%d", &n);
    int h[maxn];
    int v[maxn];
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    int low = 0, high = 1000;
    int ans = high;
    while (low <= high) {
        int hmax = 0;
        int vmax = 0;
        int last = 1;
        int mid = (low + high) >> 1;
        for (int i = n - 1; i >= 0; i--) {
            int hh = h[i] + mid;
            if (hh > v[i]) {
                hmax = max(hmax, hh);
                last = 1;
            } else if (hh < v[i]) {
                vmax = max(vmax, v[i]);
                last = -1;
            } else {
                if (last == 1) {
                    hmax = max(hmax, hh);
                } else if (last == -1) {
                    vmax = max(vmax, v[i]);
                }
            }
        }
        // printf("(%d,%d,%d)\n",mid,hmax,vmax);
        if (last == 1) {
            ans = min(ans, mid);
            high = mid - 1;
        } else
            low = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}