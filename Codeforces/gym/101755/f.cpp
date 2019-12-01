#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

unordered_set<int> moms[1001];
bool momson[1001][1001];
int n;
int root = -1;
int ans[1001];

bool no_ring() {
    for (int i = 1; i <= n; i++) {
        bool m[n + 1];
        memset(m, false, sizeof(m));
        int mom = ans[i];
        while (mom != 0) {
            m[mom] = true;
            mom = ans[mom];
        }
        for (mom = 1; mom <= n; mom++)
            if (momson[mom][i] != m[mom]) return false;
    }
    return true;
}

int find_empty() {
    int ret = -1;
    for (int i = 1; i <= n; i++) {
        if (moms[i].empty()) {
            if (ret != -1) return -1;
            ret = i;
        }
    }
    return ret;
}

vector<int> remove_mom(int x) {
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (moms[i].empty()) continue;
        moms[i].erase(x);
        if (moms[i].empty()) ret.push_back(i);
    }
    return ret;
}

bool check_all_empty() {
    for (int i = 1; i <= n; i++)
        if (!moms[i].empty()) return false;
    return true;
}

void get_input() {
    cin >> n;
    for (int mom = 1; mom <= n; mom++) {
        int nson;
        cin >> nson;
        if (nson == n) throw "";
        for (int j = 0; j < nson; j++) {
            int son;
            cin >> son;
            if (son == mom) throw "";
            moms[son].insert(mom);
            momson[mom][son] = true;
        }
    }
}

void solve() {
    get_input();

    root = find_empty();
    if (root == -1) throw "";
    ans[root] = 0;

    list<int> rem;
    rem.push_back(root);
    int found = 0;
    while (!rem.empty()) {
        int i = rem.back();
        rem.pop_back();
        auto ret = remove_mom(i);
        for (int x : ret) {
            rem.push_back(x);
            ans[x] = i;
            found++;
        }
    }

    if (found != n - 1) throw "";
    if (!no_ring()) throw "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(momson, false, sizeof(momson));
    try {
        solve();
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            if (ans[i] != 0) cout << ans[i] << " " << i << "\n";
    } catch (...) {
        cout << "NO\n";
    }
    return 0;
}