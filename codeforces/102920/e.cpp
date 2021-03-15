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
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

int main() {
    fastio();
    int n;
    cin >> n;
    vector<int> q(n);
    for (auto& val : q) cin >> val;
    if (q[0] > 1 || q.back() > 1) {
        cout << "NO" << endl;
        return 0;
    }

    int falseJudge = q[0] == 1;
    for (int i = 1; i < n; i++) {
        if (q[i] > 2) {
            cout << "NO" << endl;
            return 0;
        }

        if (falseJudge) {
            // miss compare prev
            if (q[i] == 0) {
                falseJudge = true;
                // miss compare next
            } else if (q[i] == 1) {
                falseJudge = false;
                // good compare next
            } else {
                // miss compare next
                falseJudge = true;
            }
        } else {
            if (q[i] == 0) {
                falseJudge = false;
            } else if (q[i] == 1) {
                falseJudge = true;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << (falseJudge ? "NO" : "YES") << endl;
    return 0;
}