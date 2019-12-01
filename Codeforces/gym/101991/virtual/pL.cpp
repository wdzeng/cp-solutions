#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    int c = 0;
    int s = 0;
    while(c<k && v.size()) {
        int o = s | v.back();
        if(o!=s) c++;
        s=o;
        v.pop_back();
    }
    return s;
}

int main() {
    freopen("looking.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0); 
    int t; cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
