#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

void solve() {
    int n;
    cin >> n;
    unordered_set<string> words;
    vector<string> vwords;
    int w00 = 0, w01 = 0, w10 = 0, w11 = 0;
    while (n--) {
        string w;
        cin >> w;
        words.insert(w);
        vwords.push_back(w);
        if (w[0] == '0' and w.back() == '0') w00++;
        if (w[0] == '0' and w.back() == '1') w01++;
        if (w[0] == '1' and w.back() == '0') w10++;
        if (w[0] == '1' and w.back() == '1') w11++;
    }
    if (w01 == 0 and w10 == 0) {
        if (w00 > 0 and w11 > 0)
            cout << -1 << endl;
        else
            cout << 0 << endl << endl;
        return;
    }

    vector<int> c01, c10;
    for (int i = 0; i < vwords.size(); i++) {
        const auto& w = vwords[i];
        if (w[0] == w.back()) continue;
        string c = w;
        reverse(all(c));
        if (!words.count(c)) {
            if (w[0] == '0')
                c01.push_back(i);
            else
                c10.push_back(i);
        }
    }

    if (w01 > w10) {
        int diff = (w01 - w10) / 2;
        if (c01.size() >= diff) {
            cout << diff << endl;
            for (int i = 0; i < diff; i++) cout << c01[i] + 1 << ' ';
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (w10 > w01) {
        int diff = (w10 - w01) / 2;
        if (c10.size() >= diff) {
            cout << diff << endl;
            for (int i = 0; i < diff; i++) cout << c10[i] + 1 << ' ';
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        cout << 0 << endl
             << endl;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}