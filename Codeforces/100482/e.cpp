#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mn(x) memset(x, -1, sizeof(x))

const int X = 31, MOD = 1013;

int xx(int n) {
    static vi rec = []() {
        vi v = {0};
        for (int i = 0; i < 10020; i++) v.push_back(v.back() * X % MOD);
        return v;
    }();
    return rec[n];
}

void solve() {
    unordered_map<int, ll> hmap;
    hmap[0] = 1;

    int hash;
    cin >> hash;
    string s;
    cin >> s;
    reverse(iter(s));

    int x = 1;
    vi un;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != '?') {
            hash -= x * c;
            hash = (hash % MOD + MOD) % MOD;
        } else {
            un.push_back(x);
        }
        x = x * X % MOD;
    }

    unordered_map<int, string> hsmap;
    unordered_map<int, ll> hcmap;
    hcmap[0] = 1;
    hsmap[0] = "";
    for (int co : un) {
        unordered_map<int, ll> updated;
        unordered_map<int, string> updatedstring;
        for (char c = 'a'; c <= 'z'; c++) {
            for (auto& p : hcmap) {
                int h = (p.first + co * c) % MOD;
                updatedstring[h] = hsmap[h] + c;
                updated[h] += p.second;
            }
        }
        hcmap = updated;
        hsmap = updatedstring;
    }

    if (hcmap[hash] == 1) {
        string filled = hsmap[hash];
        reverse(iter(s));
        for (char c : s)
            if (c != '?')
                cout << c;
            else {
                cout << filled.back();
                filled.pop_back();
            }
    } else
        cout << hcmap[hash];
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    return 0;
}