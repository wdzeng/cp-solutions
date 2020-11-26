#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

map<vector<int>, ll> rec;
ll search(vector<int>& q) {
    auto a = rec.find(q);
    if (a != rec.end()) return a->second;

    ll ret = 1;
    for (int i = 0; i < q.size(); i++) {
        if (q[i] > 1) {
            auto qq = q;
            qq[i]--;
            ret += search(qq);
        }
    }
    rec[q] = ret;
    return ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> q;
    while (k--) {
        int a;
        cin >> a;
        q.push_back(a);
    }
    cout << search(q) << endl;
    return 0;
}