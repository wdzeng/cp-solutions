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

/**
 * 支援處理四則運算的工具。給四則運算的字串，檢查格式並計算其值。如果
 * 格式不合法，會丟出錯誤。複雜度 O(字串長度) 。支援的符號有四則運算
 * 和求餘數，先乘除後加減。可以使用括號、或前置正負號。數字開頭可以為
 * 零或禁止為零。可以兼容或禁止多重前置號 (例如 --1 視為 1 、+-+-1
 * 視為 -1) 。空字串視為不合法。運算範圍限於 long long 。如果試圖除
 * 以零或對零求餘也會丟出錯誤。
 */
void req(bool b) { if (!b) throw 87; }
const int B = 2; // 可以調整成 B 進位
class Expr {
   private:
    deque<char> src;
    Expr(const string& s) : src(s.begin(), s.end()) {}

    inline char top() {
        return src.empty() ? '\0' : src.front();
    }
    inline char pop() {
        char c = top(); src.pop_front(); return c;
    }
    ll n() {
        ll ret = pop() - '0';
        // 若要禁止數字以 0 開頭，加上這行
        req(ret || !isdigit(top()));
        while (isdigit(top())) ret = B * ret + pop() - '0';
        return ret;
    }
    ll fac() {
        if (isdigit(top())) return n();
        if (top() == '-') return pop(), -fac();
        if (top() == '(') {
            pop();
            int ret = expr(1);
            return req(pop() == ')'), ret;
        }
        // 若要允許前置正號，加上這行
        // else if(top() == '+') { pop(); return fac(); }
        return req(0), 0;
    }
    ll term() {
        ll ret = fac(); char c;
        while ((c = top()) && (c == '*' || c == '/' || c == '%')) {
            pop();
            if (c == '*') { ret *= fac(); continue; }
            ll t = fac(); req(t);
            if (c == '/') ret /= t; else ret %= t;
        }
        return ret;
    }
    ll expr(bool k) {
        ll ret = term();
        while (top() == '+' || top() == '-')
            if (pop() == '+') ret += term();
            else ret -= term();
        return req(top() == (k ? ')' : '\0')), ret;
    }

   public:
    // 給定數學運算的字串，求其值。若格式不合法，丟出錯誤。
    static ll eval(const string& s) {
        // 若要禁止多重前置號，加上這四行
        // req(s.find("--") == -1); // 禁止多重負號
        // req(s.find("-+") == -1);
        // req(s.find("+-") == -1);
        // req(s.find("++") == -1);
        return Expr(s).expr(0);
    }
};

bool judge(const string& s) {
    int eq = s.find_first_of('=');
    if (eq == -1 or s.find_first_of('=', eq + 1) != -1) return 0;
    try { return Expr::eval(s.substr(0, eq)) == Expr::eval(s.substr(eq + 1));
    } catch (...) { }
    return 0;
}

string update(string src, const vector<char>& p) {
    for (char& c : src) { if (isalpha(c)) c = p[c - 'a']; }
    return src;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<char> p = {'0', '1', '=', '(', ')', '+', '-', '*'}; sort(iter(p));
    string s; cin >> s;
    unordered_map<char, char> args;
    for (char c : s) if (!args.count(c) and isalpha(c)) args[c] = args.size() + 'a';
    if (args.size() > p.size()) { cout << 0 << endl; return 0; }
    for (char& c : s) if (isalpha(c)) c = args[c];
    unordered_set<string> vis; int ans = 0;
    do {
        string u = update(s, p);
        if (vis.count(u)) continue;
        vis.insert(u);
        if (judge(u)) ans++;
    } while (next_permutation(iter(p)));
    cout << ans << endl;
    return 0;
}
