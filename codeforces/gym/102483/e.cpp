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

void task(const string& s, int& pos, vector<pii>& ans, int opt) {
    if (s[pos] == '[') {
        pos++;
        while (s[pos] != ']') {
            int num = 0;
            while (s[pos] != ',' and s[pos] != ']') {
                num = num * 10 + s[pos] - '0';
                pos++;
            }
            ans.push_back({num, -1});
            if (s[pos] == ',') pos++;  // ,
        }
        assert(s[pos] == ']');
        pos++;  // ]
    } else if (s[pos] == 'c') {
        pos += 7;
        task(s, pos, ans, opt);
        pos++;  // ,
        task(s, pos, ans, opt);
        pos++;  // )
    } else if (s[pos + 1] == 'h') {
        int l = ans.size();
        pos += 8;
        task(s, pos, ans, 0);
        pos++;  // )
        int r = ans.size();
        if (opt) {
            sort(ans.begin() + l, ans.begin() + r);
            if (ans[l].x == ans[r - 1].x)
                for (int i = l; i < r; i++) ans[i].y = -1;
            else
                for (int i = l; i < r; i++) ans[i].y = r;
        }
    } else if (s[pos + 1] == 'o') {
        pos += 7;
        int l = ans.size();
        task(s, pos, ans, 0);
        pos++;  // )
        int r = ans.size();
        if (opt) {
            sort(ans.begin() + l, ans.begin() + r);
            for (int i = l; i < r; i++) ans[i].y = -1;
        }
    } else {
        assert(0);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    int posa = 0, posb = 0;
    vector<pii> ansa, ansb;
    task(a, posa, ansa, 1);
    task(b, posb, ansb, 1);
    //for(auto& p: ansa) cout << "[" << p.x << ',' << p.y << "] "; cout << endl;
    //for(auto& p: ansb) cout << "[" << p.x << ',' << p.y << "] "; cout << endl;
    cout << (ansa == ansb ? "equal" : "not equal") << endl;
    return 0;
}