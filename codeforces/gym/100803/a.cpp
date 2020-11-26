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

int one(const vector<int>& v) {
    int ret = 0;
    for (int i : v) ret += (i == 1);
    return ret;
}

int firstone(vector<int>& v, int i) {
    for (; i < v.size(); i++)
        if (v[i] == 1) return i;
    throw "";
}

int firstzero(vector<int>& v, int i) {
    for (; i < v.size(); i++)
        if (v[i] == 0) return i;
    throw "";
}

int cal(const vector<int>& v, vector<int>& u) {
    if (one(v) != one(u)) return 1e9;
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
        int r;
        if (v[i] == 1)
            r = firstone(u, i);
        else
            r = firstzero(u, i);
        ret += r - i;
        swap(u[r], u[i]);
    }
    return ret;
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    while (n--) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> seq1;
    vector<int> seq0;
    while (m--) {
        int a;
        cin >> a;
        int c = 1, d = 0;
        if (m % 2) swap(c, d);
        while (a--) seq1.push_back(c), seq0.push_back(d);
    }

    int s1 = 0, s2 = 0;
    for (int i = 0; i < v.size(); i++) {
        int val = v[i];
        if (val != seq1[i])
            s1++;
        else
            s2++;
    }
    cout << min(cal(v, seq1), cal(v, seq0)) << endl;
    return 0;
}
