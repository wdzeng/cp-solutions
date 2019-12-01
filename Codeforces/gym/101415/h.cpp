#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

inline bool assure(bool b) {
    if (!b) throw "";
}

struct pH {
    unordered_map<string, int> varlen;
    unordered_map<string, unordered_map<int, int>> assigned;
    void declare(string varname, int len) {
        varlen[varname] = len;
    }
    void assign(string varname, int index, int value) {
        assure(varlen.count(varname) && index < varlen[varname]);
        assigned[varname][index] = value;
    }
    int query(string varname, int index) {
        assure(varlen.count(varname) && index < varlen[varname] && assigned[varname].count(index));
        return assigned[varname][index];
    }
    int query(string statement) {
        int lb = statement.find_first_of('[');
        if (lb == -1) return stoi(statement);
        int rb = statement.find_last_of(']');
        string varname = statement.substr(0, lb);
        string q = statement.substr(lb + 1, rb - lb - 1);
        int index = query(q);
        return query(varname, index);
    }
};

int solve(const vector<string>& codes) {
    pH cc;
    int c = 1;
    try {
        for (const string& statement : codes) {
            int eq = statement.find('=');
            if (eq != -1) {
                // assign
                string left = statement.substr(0, eq);
                int lb = left.find_first_of('[');
                int rb = left.find_last_of(']');
                string varname = left.substr(0, lb);
                string q = left.substr(lb + 1, rb - lb - 1);
                int index = cc.query(q);

                string right = statement.substr(eq + 1);
                int value = cc.query(right);
                cc.assign(varname, index, value);
            }  //
            else {
                // declare
                int lb = statement.find_first_of('[');
                int rb = statement.find_last_of(']');
                string varname = statement.substr(0, lb);
                string q = statement.substr(lb + 1, rb - lb - 1);
                int len = cc.query(q);
                cc.declare(varname, len);
            }
            c++;
        }
    } catch (...) {
        return c;
    }
    return 0;
}

int main() {
    freopen("H.in", "r", stdin);
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    vector<string> codes;
    while (1) {
        cin >> s;
        if (s != ".") {
            codes.push_back(s);
            continue;
        }
        if (codes.empty())
            break;
        else
            cout << solve(codes) << endl;
        codes.clear();
    }
    return 0;
}