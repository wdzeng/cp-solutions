#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<ll> h(n + 1);
    for (auto& val : h) cin >> val;

    while (q--) {
        double c;
        cin >> c;
        ll k = round(c * 10);

        vector<pair<ll, int>> v;
        for (auto val : h) v.emplace_back(val - k * v.size(), (int)v.size());
        sort(all(v));
        int minval = 1e6;
        int w = 0;
        for (int i = 0; i < h.size(); i++) {
            minval = min(minval, v[i].y);
            w = max(w, v[i].y - minval);
        }

        double maxdw = 0;
        for (int i = 0; i + w + 1 < v.size(); i++) {
            // dw
            double dw = double(h[i + w] - h[i] - k * w) / (k + h[i + w] - h[i + w + 1]);
            if (dw > 0 and dw < 1) {
                maxdw = max(maxdw, dw);
            }
        }
        for (int i = v.size() - 1; i - w - 1 >= 0; i--) {
            // dw
            double dw = double(h[i] - h[i - w] - k * w) / (k + h[i - w - 1] - h[i - w]);
            if (dw > 0 and dw < 1) {
                maxdw = max(maxdw, dw);
            }
        }

        double ans = w + maxdw;
        if (ans == 0)
            printf("-1\n");
        else
            printf("%.12f\n", ans);
    }

    return 0;
}