#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<pii> o1, o2;
    while (true) {
        string o;
        cin >> o;
        if (o == "E") break;
        if (o == "I") {
            ll loc;
            string ins;
            cin >> loc >> ins;
            o1.emplace_back((int)(ins[0]), loc);
        } else {
            ll loc;
            cin >> loc;
            o1.emplace_back(-1, loc);
        }
    }
    while (true) {
        string o;
        cin >> o;
        if (o == "E") break;
        if (o == "I") {
            ll loc;
            string ins;
            cin >> loc >> ins;
            o2.emplace_back((int)ins[0], loc);
        } else {
            ll loc;
            cin >> loc;
            o2.emplace_back(-1, loc);
        }
    }

    set<ll> s;
    for (auto& p : o1) {
        s.insert(p.y);
    }
    for (auto& p : o2) {
        s.insert(p.y);
    }
    unordered_map<ll, int> m;
    for (int i : s) m[i] = m.size();
    for (auto& p : o1) {
        p.y = m[p.y];
    }
    for (auto& p : o2) {
        p.y = m[p.y];
    }

    vector<int> tested;
    for (int i = 0; i < 9100; i++) {
        tested.push_back(300 + i);
    }

    vector<int> ta = tested, tb = tested;
    for (auto& p : o1) {
        if (p.x == -1) {
            ta.erase(ta.begin() + p.y);
        } else {
            ta.insert(ta.begin() + p.y, p.x);
        }
    }

    for (auto& p : o2) {
        if (p.x == -1) {
            tb.erase(tb.begin() + p.y);
        } else {
            tb.insert(tb.begin() + p.y, p.x);
        }
    }

    cout << (ta == tb ? '0' : '1') << endl;
    return 0;
}