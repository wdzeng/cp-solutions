#pragma GCC optimize("unroll-loops", "Ofast")
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

const int N = 2e5 + 5;
int ans[N];

const int A = N * 2;
int a[A * 4];
vector<int> nums;
int l;
void add(int x, int i = 1, int cl = 0, int cr = A) {
    if (cr <= x || cl >= x + 1) return;
    if (cl + 1 == cr) {
        assert(cl == x);
        a[i]++;
        return;
    }
    int cm = (cl + cr) >> 1;
    add(x, i * 2, cl, cm);
    add(x, i * 2 + 1, cm, cr);
    a[i] = a[i * 2] + a[i * 2 + 1];
}

int sum(int l, int r, int i = 1, int cl = 0, int cr = A) {
    if (cl >= r || cr <= l) return 0;
    if (cl >= l && cr <= r) {
        return a[i];
    }
    int cm = (cl + cr) >> 1;
    return sum(l, r, i * 2, cl, cm) + sum(l, r, i * 2 + 1, cm, cr);
}

void solve(vector<pii> fs, vector<pii> ps, int leftbound) {
    ms(a);
    while (!ps.empty()) {
        auto p = ps.back();
        ps.pop_back();
        int id = p.y;
        int x = p.x;
        int lim = leftbound ? x : x + 1;
        while (!fs.empty() && (fs.back().x >= lim)) {
            auto f = fs.back();
            fs.pop_back();
            int index = lower_bound(all(nums), f.x + f.y) - nums.begin();
            assert(nums[index] == f.x + f.y);
            add(index);
        }
        int lb = lower_bound(all(nums), leftbound ? x : (x + 1)) - nums.begin();
        int rb = upper_bound(all(nums), x + l) - nums.begin();
        int added = sum(lb, rb);
        ans[id] += added;
    }
}

const int inf = 1e9 + 5;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m >> l;
    vector<pii> fs(n), ps(m);

    for (auto& a : fs) cin >> a.x >> a.y;
    for (int i = 0; i < m; i++) {
        cin >> ps[i].x;
        ps[i].y = i;
    }
    for (auto& a : fs) nums.push_back(a.x + a.y), nums.push_back(inf - a.x + a.y);
    // for (auto& a : ps) nums.push_back(a.x), nums.push_back(inf - a.x), nums.push_back(a.x + l), nums.push_back(inf - a.x + l);
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());

    sort(all(fs));
    sort(all(ps));
    solve(fs, ps, 0);
    for (auto& a : fs) a.x = inf - a.x;
    for (auto& a : ps) a.x = inf - a.x;
    sort(all(fs));
    sort(all(ps));
    solve(fs, ps, 1);

    for (int i = 0; i < m; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}