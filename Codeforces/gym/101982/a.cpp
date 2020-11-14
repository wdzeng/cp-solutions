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
    int k;
    cin >> k;
    string a, b;
    cin >> a >> b;
    int same = 0, diff = 0;
    for (int i = 0; i < a.size(); i++) same += a[i] == b[i], diff += a[i] != b[i];
    int ik = a.size() - k;
    int ans = 0;
    ans += min(same, k);
    ans +=min(diff, ik);
    cout << ans << endl;
    return 0;
}