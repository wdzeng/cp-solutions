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
    string s;
    getline(cin, s);
    stringstream ss(s);
    string d;
    int k = 0;
    while (ss >> d) k++;

    int n;
    cin >> n;
    list<string> kid;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        kid.push_back(name);
    }

    auto a = kid.begin();
    vector<string> u, v;
    while (kid.size()) {
        for (int c = 1; c < k; c++) {
            if (++a == kid.end()) a = kid.begin();
        }
        u.push_back(*a);
        a = kid.erase(a);
        if (a == kid.end()) a = kid.begin();
        u.swap(v);
    }

    if (n % 2 == 1) u.swap(v);
    cout << u.size() << '\n';
    for (string name : u) cout << name << '\n';
    cout << v.size() << '\n';
    for (string name : v) cout << name << '\n';
    return 0;
}