#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define len(v) int(v.size())
#ifdef hy
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

int main() {
    fastio();
    string line;
    vector<string> lines;
    while (getline(cin, line)) lines.push_back(line);
    reverse(all(lines));
    while (1) {
        if (lines.empty()) break;
        vector<string> data;
        while (1) {
            if (lines.empty()) break;
            string l = lines.back();
            lines.pop_back();
            if (l.empty()) break;
            data.push_back(l);
        }
        int R = data.size();
        int C = data[0].size();
        vector<int> vp;
        for (int c = 0; c < C; c++) {
            int ans = -1;
            for (int r = 0; r < R; r++)
                if (data[r][c] == '*') {
                    ans = r;
                    break;
                }
            assert(~ans);
            vp.push_back(ans);
        }
        sort(all(vp));
        reverse(all(vp));
        vector<string> gans(R);
        for (auto& s : gans)
            for (int i = 0; i <C; i++) s += ".";
        for (int i = 0; i < vp.size(); i++) {
            int r = vp[i];
            gans[r][i] = '*';
        }
        for (auto& s : gans) cout << s << endl;
        cout << endl;
    }
    return 0;
}