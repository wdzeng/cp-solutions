#include <bits/stdc++.h>
using namespace std;

struct bit {
    int n;
    vector<int> arr;
    bit(int n) : n(n) { arr.resize(n + 1, 0); }
    int query(int idx) {
        idx = n - idx + 1;
        int ret = 0;
        while (idx > 0) {
            ret += arr[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
    void incfrom(int idx) {
        idx = n - idx + 1;
        while (idx <= n) {
            arr[idx]++;
            idx += idx & -idx;
        }
    }
};

struct T {
    int a, b, c;
};

vector<T> teams;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        T t;
        cin >> t.a >> t.b >> t.c;
        teams.push_back(t);
    }

    long long hitab = 0, hitac = 0, hitbc = 0;
    sort(teams.begin(), teams.end(), [](T& t1, T& t2) { return t1.a < t2.a; });

    bit treeab(n), treeac(n);
    for (int i = 0; i < n; i++) {
        hitab += treeab.query(teams[i].b);
        hitbc += treeac.query(teams[i].c);
        treeab.incfrom(teams[i].b);
        treeac.incfrom(teams[i].c);
    }

    sort(teams.begin(), teams.end(), [](T& t1, T& t2) { return t1.b < t2.b; });
    bit treebc(n);
    for (int i = 0; i < n; i++) {
        hitbc += treebc.query(teams[i].c);
        treebc.incfrom(teams[i].c);
    }

    cout << (hitab + hitbc + hitac) / 2 << endl;
    return 0;
}