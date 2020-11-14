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

const int N = 1e6 + 5;
int cnt[N], s[N], rem[N];
int szs, szrem;
const int inf = 1e9;

void vecins(int* v, int i, int& sz) {
    if (v[i] == 0) sz++;
    v[i] = 1;
}

void vecerase(int* v, int i, int& sz) {
    if (v[i]) sz--;
    v[i] = 0;
}

int solve(int n, int k) {
    ms(cnt);
    ms(s), szs = 0;

    vector<vector<int>> v(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        total += c;
        while (c--) {
            int x;
            cin >> x;
            v[i].push_back(x);
            vecins(s, x, szs);
        }
    }
    if (szs < k) return -1;
    if (n == 1) return total;

    ms(s), szs = 0;
    ms(rem), szrem = 0;
    int l = 0, r = 0;
    int ans = total;
    total = 0;

    // init
    for (int i : v[0]) vecins(s, i, szs), vecins(rem, i, szrem);
    total += v[0].size();
    if (szs == k) ans = min(ans, total);
    int flag = 0;

    while (l || !flag) {
        // cout << endl;
        if (l) flag = 1;
        // cout << l << ' ' << r << ' ' << szs << ' ' << szrem << ' ';
        if (szs == k) ans = min(ans, total);

        if (szrem == 0 && szs == k) {
            for (int i : v[l]) total--;
            l++;
            l %= n;
            for (int i : v[l]) cnt[i]--;
            for (int i : v[l])
                if (!cnt[i]) vecins(rem, i, szrem);
            // cout << '*' << ' ' << total << ' ';
            continue;
        }

        r++;
        r %= n;
        for (int i : v[r]) cnt[i]++, vecerase(rem, i, szrem), vecins(s, i, szs), total++;
    }

    return ans;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    while (cin >> n >> k) cout << solve(n, k) << '\n';
    return 0;
}