#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int p, l;
    cin >> p >> l;
    vector<piii> iv(p);
    for (int i = 0; i < p; i++) {
        auto& v = iv[i];
        cin >> v.x.x >> v.x.y;
        v.y = i;
    }
    sort(all(iv), [](piii& aa, piii& bb) {
        auto &a = aa.x, &b = bb.x;
        if (a.x == b.x) {
            return a.y > b.y;
        }
        return a.x < b.x;
    });

    int req = 1;
    vector<int> ans;
    for (int i = 0; i < iv.size() && req <= l;) {
        auto vv = iv[i];
        auto v = vv.x;
        if (v.x > req) {
            cout << "NO" << endl;
            return 0;
        }
        int far = -1;
        int fi;
        while (i < iv.size()) {
            vv = iv[i];
            v = vv.x;
            if (v.x > req) break;
            if (v.y > far) {
                far = v.y;
                fi = vv.y;
            }
            i++;
        }
        // cout << i << ' ' << far << endl;
        req = far + 1;
        ans.push_back(fi);
    }
    if (req <= l) {
        cout << "NO\n";
        return 0;
    }

    sort(all(ans));
    cout << "YES\n"
         << ans.size() << '\n';
    for (auto a : ans) cout << a + 1 << ' ';
    cout << '\n';

    return 0;
}