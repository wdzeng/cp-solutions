#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const int N = 1e6 + 5;
const int M = 1e7 + 7;
int sum[N];
int isnotprime[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<ll> primes;
    for (int i = 2; i < N; i++) {
        if (isnotprime[i]) continue;
        primes.push_back(i);
        for (int a = i << 1; a < N; a += i) isnotprime[a] = 1;
    }

    for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + i, sum[i] %= M;

    ll n;
    while (cin >> n && n) {
        ll ans = 1;
        for (ll p : primes) {
            if (p > n) break;
            int a = 0;
            for (ll i = p; i <= n; i *= p) a += n / i;
            ans *= sum[a + 1];
            ans %= M;
        }
        cout << ans << '\n';
    }
    return 0;
}