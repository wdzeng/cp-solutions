#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxk = 10005;
const int mod = 1000000007;

int dp[2][maxk][3];

int main() {
    cin.tie(0), ios::sync_with_stdio(0); 
    int N,K,L,R;
    cin >> N >> K >> L >> R;
    int cnt[3];
    cnt[0] = (r/3) - (l-1)/3;
    cnt[1] = f1(R) - f1(L-1);
    cnt[2] = f2(R) - f2(L-1);
    dp[0][0][0] = 0;
    dp[0][0][1] = cnt[1];
    dp[0][0][2] = cnt[2];
    dp[0][1][0] = cnt[0];
    for(int i=1; i<n; i++)
    {
        for(int k=K; k>0; k--)
        {
            dp[i&2][k][0] = dp[(i+1)&2][k-1][0]*cnt[0] + dp[(i+1)&2][k-1][1]*cnt[2] + dp[(i+1)&2][k-1][2]*cnt[1];
            dp[i&2][k][1] = dp[(i+1)&2][k][0]*cnt[1] + dp[(i+1)&2][k][2]*cnt[2];
            dp[i&2][k][2] = dp[(i+1)&2][k][0]*cnt[2] + dp[(i+1)&
        }
    }
    return 0;
}
