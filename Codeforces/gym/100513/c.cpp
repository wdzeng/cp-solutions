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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

vector<pii> dfsorder;
vector<vector<int>> sons;
vector<vector<pair<int, string>>> prop;

const string NA = "N/A";
#define key first
#define val second

inline pair<string, string> delim(string& p) {
    int eqindex = p.find('=');
    return {p.substr(0, eqindex), p.substr(eqindex + 1)};
}

int keyid(string& k) {
    static unordered_map<string, int> mmap;
    if (!mmap.count(k)) {
        mmap[k] = mmap.size();
        prop.resize(mmap.size());
    }
    return mmap[k];
}

void dfs_serach(int v) {
    static int counter = 0;
    dfsorder[v].x = counter++;
    for (int s : sons[v]) dfs_serach(s);
    dfsorder[v].y = counter++;
}

void optprop(int kid) {
    map<int, string> mmap;
    for (auto& a : prop[kid]) {
        auto& dfsindex = dfsorder[a.x];
        mmap[dfsindex.x - 1] = "";
        mmap[dfsindex.y - 1] = "";
    }
    for (auto& a : prop[kid]) {
        auto& dfsindex = dfsorder[a.x];
        mmap[dfsindex.x] = a.y;
        mmap[dfsindex.y] = NA;
    }

    stack<string> q;
    vector<pair<int, string>> opt;
    for (auto& a : mmap) {
        int index = a.x;
        string val = a.y;
        if (val != "" && val != NA) q.push(val);
        string added = q.empty() ? NA : q.top();
        while (!opt.empty() && opt.back().y == added) opt.pop_back();
        opt.emplace_back(index, added);
        if (val == NA) q.pop();
    }
    prop[kid].swap(opt);
}

string query(int v, string k) {
    int kid = keyid(k);
    if (kid >= prop.size()) return NA;
    auto a = lower_bound(iter(prop[kid]), dfsorder[v].x, [](const auto& p, int i) { return p.x < i; });
    if (a == prop[kid].end()) return NA;
    return a->y;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    dfsorder.resize(n);
    sons.resize(n);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        if (p != -1) sons[p].push_back(i);
        int q;
        cin >> q;
        while (q--) {
            string p;
            cin >> p;
            auto kvpair = delim(p);
            prop[keyid(kvpair.key)].emplace_back(i, kvpair.val);
        }
    }

    // Determines all indexes of vertices by dfs.
    dfs_serach(0);

    // Optimizes all properties to enable quick binary search.
    for (int kid = 0; kid < prop.size(); kid++) {
        optprop(kid);
    }

    int q;
    cin >> q;
    while (q--) {
        int v;
        string k;
        cin >> v >> k;
        v--;
        cout << query(v, k) << endl;
    }
    return 0;
}