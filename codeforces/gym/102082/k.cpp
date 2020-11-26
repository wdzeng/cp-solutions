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

vector<int> he;
multiset<int> she;

int maxwin() {
    auto her = she;
    int ret = 0;
    for (int i : he) {
        auto a = her.upper_bound(i);
        if (a != her.end()) {
            her.erase(a);
            ret++;
        }
    }
    return ret;
}

bool canwinfor(int i, int n) {
    vector<int> popped;
    for (; i < he.size(); i++) {
        auto a = she.upper_bound(he[i]);
        if (a != she.end()) {
            popped.push_back(*a);
            she.erase(a);
        }
    }
    she.insert(iter(popped));
    return popped.size() >= n;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    he.resize(n);

    for (int i = 0; i < n; i++) cin >> he[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        she.insert(x);
    }

    int win = maxwin();

    int ans[n];
    int rem = win;
    // cout << win << endl;
    vector<int> her(iter(she));
    for (int i = 0; i < n; i++) {
        if (!rem) {
            ans[i] = *prev(she.end());
            she.erase(prev(she.end()));
            continue;
        }
        multiset<int> popped;
        for (int j = i + 1; j < n && popped.size() < rem; j++) {
            assert(j < n);
            auto a = she.upper_bound(he[j]);
            if (a != she.end()) {
                popped.insert(*a);
                she.erase(a);
            }
        }
        assert(popped.size() >= rem - 1);
        if (popped.size() == rem - 1) {
            int g = *prev(she.end());
            if (g > he[i]) {
                ans[i] = g;
                she.erase(prev(she.end()));
            } else {
                popped.insert(g);
                assert(!she.empty());
                ans[i] = *prev(she.end());
                she.erase(prev(she.end()));
            }
        } else if (*prev(she.end()) > *prev(popped.end()) || *(prev(popped.end())) <= he[i]) {
            ans[i] = *prev(she.end());
            she.erase(prev(she.end()));
        } else {
            ans[i] = *prev(popped.end());
            popped.erase(prev(popped.end()));
        }
        she.insert(iter(popped));
        if (ans[i] > he[i]) rem--;
        // cout << ans[i] << ' ' << flush;
    }

    for (int a : ans) cout << a << ' ';
    cout << endl;
    return 0;
}