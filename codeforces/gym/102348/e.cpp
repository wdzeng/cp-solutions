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
    int n, c, l;
    cin >> n >> c >> l;
    priority_queue<pii> q;
    for (int i = 0; i < c; i++) {
        int val;
        cin >> val;
        q.emplace(val, i + 1);
    }

    vector<int> ans;
    int conn = 0;
    for (int i = 0; i < n and !q.empty(); i++) {
        assert(!q.empty());
        auto u = q.top();
        q.pop();
        if (!ans.empty() && ans.back() == u.y) {
            if (conn == l) {
                if (q.empty()) {
                    cout << -1 << endl;
                    return 0;
                }
                auto v = q.top();
                q.pop();
                ans.push_back(v.y);
                if (v.x > 1) q.emplace(v.x - 1, v.y);
                q.push(u);
                conn = 1;
            } else {
                ans.push_back(u.y);
                if (u.x > 1) q.emplace(u.x - 1, u.y);
                conn++;
            }
        } else {
            ans.push_back(u.y);
            if (u.x > 1) q.emplace(u.x - 1, u.y);
            conn = 1;
        }
    }

    if(ans.size() < n) cout << - 1 << endl;
    else {
        for (auto a : ans) cout << a << ' ';
        cout << endl;
    }
    return 0;
}