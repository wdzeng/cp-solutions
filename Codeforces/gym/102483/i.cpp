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
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    sort(all(v));
    v.insert(v.begin(), -1);
    double ans = 1.0;
    for (int i = 1; i <= n; i++) {
        if(v[i] > i) {
            cout << -1 << endl;
            return 0;
        }
        ans = min(ans, 1.0 * v[i] / i);
    }
    printf("%.18f\n", ans);


    return 0;
}