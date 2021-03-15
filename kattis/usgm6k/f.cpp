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
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    int q;
    cin >> q;
    while (q--) {
        int T;
        cin >> T;
        int q;
        cin >> q;
        vector<pii> go;
        while (q--) {
            int l, r;
            cin >> l >> r;
            go.push_back({l, r});
        }

        vector<int> canbe(T + 1, 1);
        for (auto& p : go) {
            int du = p.y - p.x;
            vector<int> nxt(T + 1);
            for (int i = 0; i <= T; i++) {
                if (!canbe[i]) continue;
                if (i + du <= T) nxt[i + du] = 1;
                if (i - du >= 0) nxt[i - du] = 1;
            }
            canbe.swap(nxt);
        }
        int has1 = 0;
        for (int i = 0; i <= T; i++)
            if (canbe[i]) has1 = 1;
        if (!has1) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    return 0;
}