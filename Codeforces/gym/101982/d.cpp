#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define size(v) int(v.size())

const int N = 130, K = 1010;
const ll M = 1e9 + 9;

ll one[N][K];
ll cnt[N][K];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> k >> n;
    cnt[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            // shift left
            int rem0 = j * 2 % k;
            one[i + 1][rem0] += one[i][j];
            cnt[i + 1][rem0] += cnt[i][j];
            one[i + 1][rem0] %= M;
            cnt[i + 1][rem0] %= M;
            // shift left and add 1
            int rem1 = (j * 2 + 1) % k;
            one[i + 1][rem1] += one[i][j] + cnt[i][j];
            cnt[i + 1][rem1] += cnt[i][j];
            one[i + 1][rem1] %= M;
            cnt[i + 1][rem1] %= M;
        }
    }
    cout << one[n][0] << endl;
    return 0;
}