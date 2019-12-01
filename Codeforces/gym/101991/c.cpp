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

void solve() {
    int nc, np;
    cin >> nc >> np;
    unordered_map<string, int> s, m, l;

    int fee = 100 / np;
    for (int i = 0; i < nc; i++) {
        string name;
        cin >> name;
        int ps, pm, pl;
        cin >> ps >> pm >> pl;
        s[name] = ps, m[name] = pm, l[name] = pl;
    }

    vector<string> cus;
    for(int i=0;i<np;i++) {
        string name; cin >> name;
        string sz; cin >> sz;
        string cofname; cin >> cofname;
        int total;
        if(sz == "small") total = s[cofname];
        else if(sz == "medium") total = m[cofname];
        else total = l[cofname];
        total += fee;
        if(total%5==4) total++;
        else if(total%5==1) total--;
        cout << name << ' ' << total << '\n';
    }
}

int main() {
    freopen("coffee.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}