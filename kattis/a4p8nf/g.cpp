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
    unordered_map<string, int> vals;
    string line;
    while (getline(cin, line)) {
        if (line == "0") break;
        stringstream ss(line);
        vector<string> toks;
        string tok;
        while (ss >> tok) {
            if (isalpha(tok[0])) {
                //if (!od.count(tok)) od[tok] = od.size() + 1;
            }
            toks.push_back(tok);
        }
        if (toks.size() == 3 && toks[1] == "=") {
            vals[toks[0]] = stoi(toks[2]);
        } else {
            int val = 0;
            vector<string> vars;
            for (int i = 0; i < toks.size(); i += 2) {
                string v = toks[i];
                if (isdigit(v[0])) {
                    val += stoi(v);
                } else if (vals.count(v))
                    val += vals[v];
                else
                    vars.push_back(v);
            }
            // sort(all(vars), [&](string a, string b) { return od[a] < od[b]; });
            if (val) {
                if (vars.size()) {
                    cout << val;
                    for (int i = 0; i < vars.size(); i++) {
                        cout << " + ";
                        cout << vars[i];
                    }
                    cout << endl;
                } else {
                    cout << val << endl;
                }
            } else {
                if (vars.size()) {
                    for (int i = 0; i < vars.size(); i++) {
                        if (i) cout << " + ";
                        cout << vars[i];
                    }
                    cout << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}