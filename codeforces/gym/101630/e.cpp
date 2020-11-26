#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cout << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    queue<int> q;
    vector<int> vec(1050);
    int n;
    cin >> n;
    int z = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            x = -x;
            if (vec[x] > 0)
                vec[x]--;
            else {
                if (z == 0) {
                    cout << "No" << endl;
                    return 0;
                }
                ans.push_back(x);
                z--;
            }
        } else if (x > 0) {
            vec[x]++;
        } else
            z++;
    }
    while(z--) ans.push_back(1);
    cout << "Yes" << endl;
    for(auto val: ans) cout << val << ' ';
    cout << endl;
    return 0;
}