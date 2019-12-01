#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

class BIT {
   private:
    int n;
    vector<int> a;

    int query(int i) {
        i++;
        int r = 0;
        while (i > 0) r += a[i], i -= i & -i;
        return r;
    }

   public:
    BIT(int n) : n(n) { a.resize(n + 1); }
    void add(int i, int v) {
        i++;
        while (i <= n) a[i] += v, i += i & -i;
    }

    int query(int l, int r) { return query(r) - query(l - 1); }
};

int n;

int solve(string s) {
    int l = s.size();
    BIT a(l), b(l), c(l);
    int counter[3];
    ms(counter);
    for (int i = 1; i <= 2 * n; i++) {
        if (s[i] == 'A')
            a.add(i, 1);
        else if (s[i] == 'B')
            b.add(i, 1);
        else
            c.add(i, 1);
        if (i <= n) counter[s[i] - 'A']++;
    }
    int mindiff = 1e9;
    for (int i = 1; i <= n; i++) {
        int da = abs(a.query(i, i + counter[0] - 1) - counter[0]);
        int db = abs(b.query(i + counter[0], i + counter[0] + counter[1] - 1) - counter[1]);
        int dc = abs(c.query(i + counter[0] + counter[1], i + counter[0] + counter[1] + counter[2] - 1) - counter[2]);
        mindiff = min(mindiff, da + db + dc);
    }
    return mindiff;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    string s; cin >> s;
    int ans1 = solve(" " + s + s);
    reverse(iter(s));
    int ans2 = solve(" " + s + s);
    cout << min(ans1, ans2) << '\n';
    return 0;
}