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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, l, k;
    cin >> n >> l >> k;
    deque<char> q;
    string str;
    cin >> str;
    q.insert(q.end(), iter(str));
    sort(iter(q));

    vector<string> ss(n);
    for (int i = 0; i < k; i++) {
        ss[i].push_back(q.front());
        q.pop_front();
    }

    while (ss[k - 1].size() < l) {
        for (int i = 0; i < k; i++) {
            if (ss[i].back() == ss[k - 1].back()) {
                ss[i].push_back(q.front());
                q.pop_front();
            }
        }
    }

    for (string& s : ss) {
        while (s.size() < l) {
            assert(!q.empty());
            s.push_back(q.front());
            q.pop_front();
        }
    }

    for (auto& s : ss) cout << s << '\n';
    return 0;
}
