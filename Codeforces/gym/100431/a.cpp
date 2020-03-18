#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

vector<int> dfs2(int n) {
    if (n == 4) {
        return {1, 2, 3, 4, 1, 3, 2, 4};
    }
    auto v = dfs2(n - 2);
    v.push_back(1);
    v.push_back(n - 1);
    bool is_n = 1;
    for (int i = 2; i <= n - 2; i++) {
        v.push_back(is_n ? n : (n - 1));
        is_n = !is_n;
        v.push_back(i);
    }
    v.push_back(n - 1);
    v.push_back(n);
    return v;
}

vector<int> dfs1(int n) {
    if (n == 3) {
        return {1, 2, 3};
    }
    auto v = dfs1(n - 2);
    bool is_n = 1;
    for (int i = 1; i <= n - 2; i++) {
        v.push_back(i);
        v.push_back(is_n ? n : (n - 1));
        is_n = !is_n;
    }
    v.push_back(n - 1);
    return v;
}

int tt(int n) {
    int total = n * (n - 1) / 2;
    if (n % 2 == 0) total += n / 2;
    return total;
}

int solve(int n) {
    if (n == 4) {
        cout << "2\n1 2 1 2\n";
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i % 2 == 1) {
            if (i * (i - 1) / 2 <= n) ans = max(ans, i);
        } else {
            if (i * (i - 1) / 2 + i / 2 <= n) ans = max(ans, i);
        }
    }

    int total = tt(ans);
    if (tt(ans) == n - 1)
        ans--;
    cout << ans << endl;
    vector<int> v;

    // if (ans % 2 == 0) {
    v = ans % 2 ? dfs1(ans) : dfs2(ans);
    // for (int val : v) cout << val << ' ';
    //  }  //
    /*  else {
        for (int s = 1; s * 2 < ans; s++) {
            int pos = 0;
            for (int i = 0; i < ans; i++) {
                v.push_back(pos + 1);
                pos = (pos + s) % ans;
            }
        }
    }
    */
    for (int i = 0; i < n - tt(ans); i++) {
        if (i == 0)
            v.push_back(1);
        else
            v.push_back(i % 2 ? 2 : 3);
    }

    set<pii> ss;
    assert(v.size() == n);
    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
        pii put;
        put.x = v[i];
        put.y = v[(i + 1) % n];
        assert(put.x != put.y);
        if (put.x > put.y) swap(put.x, put.y);
        ss.insert(put);
    }

    assert(ss.size() == ans * (ans - 1) / 2);
    for (int i = 1; i <= ans; i++) {
        for (int j = i + 1; j <= ans; j++) {
            if (!ss.count({i, j})) throw "";
        }
    }
    cout << endl;
}

int main() {
    //freopen("achromatic.in", "r", stdin);
    //freopen("achromatic.out", "w", stdout);
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    // for (int n = 3; n <= 1000; n++) 
        solve(n);
    return 0;
}