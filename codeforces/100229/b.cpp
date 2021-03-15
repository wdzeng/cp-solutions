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
#define ass(a) assert(a)
#else
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#define ass(a)
#endif

int main() {
    fastio();
    int t;
    cin >> t;
    string line;
    getline(cin, line);
    while (t--) {
        getline(cin, line);
        debug(line);
        stringstream ss(line);
        vector<string> app;
        string readed;
        while (ss >> readed) app.push_back(readed);
        set<string> no;
        int ok = 1;
        while (ok) {
            getline(cin, line);
            debug(line);
            stringstream ss(line);
            if (line.size() == 0) break;
            vector<string> am;
            while (ss >> readed) am.push_back(readed);
            if (am.size() == 3) {
                no.insert(am[2]);
            } else {
                for (auto& a : app)
                    if (!no.count(a)) cout << a << ' ';
                cout << endl;
                ok = 0;
                break;
            }
        }
    }
    return 0;
}
