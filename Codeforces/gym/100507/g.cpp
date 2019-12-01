#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

const int MOD = 1000000007;

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> dpa(a + 1, 0), dpb(b + 1, 0);
    dpa[1] = dpb[1] = 1;
    for (int i = 2; i <= n; i++) {
        vector<int> ndpa (a+1, 0), ndpb(b+1, 0);
        for (int na = 1; na <= a; na++) {
            if (na != 1) ndpa[na] = (ndpa[na] + dpa[na - 1]) % MOD; 
            ndpb[1] = (ndpb[1] + dpa[na]) % MOD;                    
        }
        for (int nb = 1; nb <= b; nb++) {
            ndpa[1] = (ndpa[1] + dpb[nb]) % MOD; 
            if (nb != 1) ndpb[nb]= (ndpb[nb] + dpb[nb - 1]) % MOD;
        }
        ndpa.swap(dpa), ndpb.swap(dpb);
    }

    ll ans = 0;
    for (int i = 1; i <= a; i++) ans = (ans + dpa[i]) % MOD;
    for (int i = 1; i <= b; i++) ans = (ans + dpb[i]) % MOD;
    cout << ans << endl;
    return 0;
}