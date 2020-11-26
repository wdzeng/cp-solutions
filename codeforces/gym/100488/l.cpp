#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    string s;
    cin >> s;
    char l, r;
    list<char> left, center, right;
    for (int i = 0; i < n; i++) {
        if (i < a)
            left.push_back(s[i]);
        else if (i == a)
            l = s[i];
        else if (i < b)
            center.push_back(s[i]);
        else if (i == b)
            r = s[i];
        else
            right.push_back(s[i]);
    }

    int q;
    cin >> q;
    bool rev = false;
    while (q--) {
        char o;
        cin >> o;
        if (o == 'R')
            rev = !rev, swap(l, r);
        else if (o == 'Q') {
            char who;
            cin >> who;
            cout << (who == 'L' ? l : r);
        }  //
        else {
            char who, where;
            cin >> who >> where;
            if (who == 'L' && where == 'L') {
                if (!rev)
                    center.push_front(l);
                else
                    center.push_back(l);
                l = left.back();
                left.pop_back();
            } else if (who == 'L' && where == 'R') {
                left.push_back(l);
                if (!rev) {
                    l = center.front();
                    center.pop_front();
                } else {
                    l = center.back();
                    center.pop_back();
                }
            } else if (who == 'R' && where == 'R') {
                if (!rev) {
                    center.push_back(r);
                } else {
                    center.push_front(r);
                }
                r = right.front();
                right.pop_front();
            } else {
                right.push_front(r);
                if (!rev) {
                    r = center.back();
                    center.pop_back();
                } else {
                    r = center.front();
                    center.pop_front();
                }
            }
        }
    }
    cout << "\n";
    return 0;
}