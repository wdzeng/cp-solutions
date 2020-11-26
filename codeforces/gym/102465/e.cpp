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
#ifndef hy
#define endl '\n'
#endif

int main() {
#ifndef hy
    cin.tie(0), ios::sync_with_stdio(0);
#endif
    int n;
    cin >> n;
    string dump;
    int lsum = 0, rsum = 0;
    vector<int> p;
    vector<string> name;
    for (int i = 0; i < n; i++) {
        cin >> dump;
        name.push_back(dump);
        int x;
        cin >> x;
        lsum += min(10000, x * 100 - 50);
        rsum += max(0, x * 100 + 49);
        p.push_back(x * 100);
    }
    if (rsum < 10000 || lsum > 10000) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%s ", name[i].c_str());
        int minn = max(0, max(p[i] - 50, 10000 - (rsum - (p[i] + 49))));
        printf("%d.%02d ", minn / 100, minn % 100);
        int maxx = min(10000, min(p[i] + 49, 10000 - (lsum - (p[i] - 50))));
        printf("%d.%02d\n", maxx / 100, maxx % 100);
    }
    return 0;
}