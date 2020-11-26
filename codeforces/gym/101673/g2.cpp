
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define lowbit(x) x&(-x)
#define PII  pair<int, int> 
#define all(x) x.begin(), x.end()
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e5 + 5;
using namespace std;
 
int n, m;
int a[105], val[105];
int dp[105][105];
 
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
	}
	val[1] = m;
	for(int i = 2; i <= n; i++){
		val[i] = val[i-1] * 2 / 3;
	}
	for(int i = 1; i <= n; i++){
		dp[i][1] = min(a[i], val[1]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(i >= 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + min(val[j], a[i]));
			if(i >= 2) dp[i][j] = max(dp[i][j], dp[i-2][j] + min(val[j], a[i]));
			if(i >= 3) dp[i][1] = max(dp[i][1], dp[i-3][j] + min(val[1], a[i]));
			ans = max(ans, dp[i][j]);
		}
		ans = max(ans, dp[i][1]);
	}
	printf("%d\n", ans);
	return 0;
}