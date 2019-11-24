#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 50 + 5;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    int a[maxn];
    bool flag = 1;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (i == j || j == k || k == i)
                    continue;
                else
                    flag &= ((a[i] - a[j]) % a[k] == 0);
    printf("%s\n", flag ? "yes" : "no");
    return 0;
}
