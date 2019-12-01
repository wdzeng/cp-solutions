#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))

const int maxn = 51;
int rec[maxn];
int k;

int judge(int n) {
    if (rec[n] != -1) return rec[n];
    unordered_set<int> sset;
    for (int i = 0; i <= n - k; i++) {
        sset.insert(judge(i) ^ judge(n - k - i));
    }
    int v = 0;
    while (sset.count(v)) v++;
    return rec[n] = v;
}

bool solve() {
    int n;
    cin >> n >> k;
    return judge(n);
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        mn(rec);
        printf("Case %d: %s\n", i, solve() ? "Winning" : "Losing");
    }
    return 0;
}