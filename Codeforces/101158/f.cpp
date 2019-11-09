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

vector<vector<pair<string, string>>> vdd;
map<pair<string, string>, vector<int>> mention;
vector<bool> fake;
set<pair<string, string>> validated;
unordered_map<string, unordered_set<string>> sons;

bool updated = 1;
void fix(const string& d, const string& s) {
    if (validated.count(mp(d, s))) return;
    validated.insert(mp(d, s));
    for (int id : mention[mp(d, s)]) {
        if (!fake[id]) continue;
        fake[id] = 0;
        updated = 1;
        for (auto& p : vdd[id]) sons[p.x].insert(p.y);
    }
}

void check(const string& p) {
    stack<string> k;
    unordered_set<string> vis;
    k.push(p);
    vis.insert(p);
    while (k.size()) {
        string v = k.top();
        k.pop();
        for (auto& e : sons[v]) {
            if (e == p) throw "";
            if (!validated.count(mp(p, e))) fix(p, e);
            else continue;
            if (vis.count(e)) continue;
            vis.insert(e);
            k.push(e);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string dad, son;
    cin >> dad >> son;
    int dd;
    cin >> dd;
    fake.assign(dd, 1);
    unordered_set<string> names;

    for (int i = 0; i < dd; i++) {
        int n;
        cin >> n;
        vector<pair<string, string>> data;
        while (n--) {
            string d, s;
            cin >> d >> s;
            names.insert(d);
            names.insert(s);
            data.emplace_back(d, s);
            mention[mp(d, s)].push_back(i);
        }
        vdd.push_back(data);
    }

    sons[dad].insert(son);
    try {
        while (updated) {
            updated = 0;
            for (auto& name : names) check(name);
        }
        cout << "Yes" << endl;
    } catch (...) {
        cout << "No" << endl;
    }
    return 0;
}
