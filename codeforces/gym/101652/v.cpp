#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const ll inf = 2e10;
struct range {
    ll loc, l, r;
    char val;
    bool operator<(const range& o) const {
        return loc < o.loc;
    }
};

set<range> A, B;

inline void splitAt(set<range>& S, ll index) {
    assert(!S.empty());
    auto a = --S.upper_bound({index});
    if (a->loc == index) {
        return;
    }
    auto erased = *a;
    S.erase(a);
    S.insert({erased.loc, erased.l, erased.l + index - erased.loc, erased.val});
    S.insert({index, erased.l + index - erased.loc, erased.r, erased.val});
}

void task(set<range>& S) {
    string op;
    while (cin >> op && op != "E") {
        ll index;
        cin >> index;

        if (op == "I") {
            splitAt(S, index);
            char c;
            cin >> c;
            auto a = S.lower_bound({index});
            assert(a->loc == index);
            vector<range> added;
            while (a != S.end()) {
                auto r = *a;
                r.loc++;
                added.push_back(r);
                a = S.erase(a);
            }
            for (auto& r : added) S.insert(r);
            S.insert({index, -1, -1, c});
        } else {
            splitAt(S, index);
            splitAt(S, index + 1);
            auto a = S.lower_bound({index});
            assert(a->loc == index);
            assert(next(a)->loc == index + 1);
            a = S.erase(a);
            vector<range> added;
            while (a != S.end()) {
                auto r = *a;
                r.loc--;
                added.push_back(r);
                a = S.erase(a);
            }
            for (auto& r : added) S.insert(r);
        }
    }

    // clean
    vector<range> vA;
    for (auto& r : S) {
        if (vA.empty()) {
            vA.push_back(r);
            continue;
        }
        auto& b = vA.back();
        if (r.val != b.val || r.val != '$') {
            vA.push_back(r);
            continue;
        }
        if (r.l == b.r)
            b.r = r.r;
        else {
            vA.push_back(r);
            continue;
        }
    }
    S.clear();
    S.insert(all(vA));
}

bool ok() {
    if (A.size() != B.size()) return false;
    auto a = A.begin(), b = B.begin();
    while (a != A.end()) {
        if (a->loc != b->loc) return false;
        if (a->l != b->l) return false;
        if (a->r != b->r) return false;
        if (a->val != b->val) return false;
        a++;
        b++;
    }
    return true;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    srand(time(0));
    A.insert({1, 1, inf, '$'});
    B.insert({1, 1, inf, '$'});
    task(A);
    task(B);

    cout << !ok() << endl;
    return 0;
}