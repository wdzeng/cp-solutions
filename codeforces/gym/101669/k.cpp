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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.emplace_back(a, i);
    }
    sort(all(v));
    int ans[n];
    int g = n;
    for (auto& p : v) {
        ans[p.y] = g--;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}