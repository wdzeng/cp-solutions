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

int minswap(const string& a, const string& b) {
    if (a == b) return 0;
    unordered_map<string, int> vis;
    queue<string> q;
    q.push(a);
    vis[a] = 0;
    while (!q.empty()) {
        string u = q.front();
        int step = vis[u];
        q.pop();
        for (int i = 0; i < 3; i++) {
            string v = u;
            swap(v[i], v[i + 1]);
            if (vis.count(v)) continue;
            if (v == b) return step + 1;
            vis[v] = step + 1;
            q.push(v);
        }
    }
    assert(0);
    return 0;
}

const int inf = 1e9;
inline void req(bool b) {
    if (!b) throw "";
}

inline bool tisdigit(unsigned char c) {
    return c >= 0x30;
}

const int B = 10;  // 可以調整成 B 進位
class Expr {
   private:
    deque<char> src;
    Expr(const string& s) : src(s.begin(), s.end()) {}
    inline unsigned char top() {
        return src.empty() ? 0 : src.front();
    }
    inline unsigned char pop() {
        char c = src.front();
        src.pop_front();
        return c;
    }
    ll n() {
        ll ret = pop() - 0x30;
        // 若要禁止數字以 0 開頭，加上這行
        // req(ret || !isdigit(top()));
        while (tisdigit(top())) ret = B * ret + pop() - 0x30;
        return ret;
    }
    ll fac() {
        if (tisdigit(top())) return n();
        if (top() == '-') {
            pop();
            return -fac();
        }
        if (top() == '(') {
            pop();
            ll ret = expr(1);
            req(pop() == ')');
            return ret;
        }
        // 若要允許前置正號，加上這行
        // if(top() == '+') { pop(); return fac(); }
        throw "";
    }
    ll term() {
        ll ret = fac();
        char c = top();
        while (c == '*' || c == '/' || c == '%') {
            pop();
            if (c == '*')
                ret *= fac();
            else {
                ll t = fac();
                req(t);
                if (ret % t) req(0);
                ret /= t;
            }
            c = top();
        }
        return ret;
    }
    ll expr(bool k) {
        ll ret = term();
        while (top() == '+' || top() == '-')
            if (pop() == '+')
                ret += term();
            else
                ret -= term();
        req(top() == (k ? ')' : '\0'));
        return ret;
    }

   public:
    // 給定數學運算的字串，求其值。若格式不合法，丟出錯誤。
    static ll eval(const string& s) {
        // 若要禁止多重前置號，加上這四行
        // req(s.find("--") == -1); // 禁止多重負號
        // req(s.find("-+") == -1);
        // req(s.find("+-") == -1);
        // req(s.find("++") == -1);
        try {
            return Expr(s).expr(0);
        } catch (...) {
            return inf;
        }
    }
};

int test(const vector<char>& v, int o) {
    string s;
    for (char c : v) s.push_back(c);
    int ret = Expr::eval(s);
    return ret == 24 ? o : inf;
}

int solve(const vector<int>& v) {
    int ret = inf;
    for (int i = 0; i < 64; i++) {
        string s = "       ";
        s[0] = v[0] + '0';
        s[2] = v[1] + '0';
        s[4] = v[2] + '0';
        s[6] = v[3] + '0';
        for (int j = 0; j < 3; j++) {
            int index = 2 * j + 1;
            int m = ((i >> (j * 2)) & 3);
            if (m == 0)
                s[index] = '+';
            else if (m == 1)
                s[index] = '-';
            else if (m == 2)
                s[index] = '*';
            else if (m == 3)
                s[index] = '/';
        }
        vector<char> v, u;
        for (char c : s) v.push_back(c);
        ret = min(ret, test(v, 0));  // a+b+c+d
        u = v;
        u.insert(u.begin() + 0, '(');
        u.insert(u.begin() + 4, ')');
        ret = min(ret, test(u, 1));  // (a+b)+c+d
        u = v;
        u.insert(u.begin() + 2, '(');
        u.insert(u.begin() + 6, ')');
        ret = min(ret, test(u, 1));  // a+(b+c)+d
        u = v;
        u.insert(u.begin() + 4, '(');
        u.insert(u.begin() + 8, ')');
        ret = min(ret, test(u, 1));  // a+b+(c+d)
        u = v;
        u.insert(u.begin() + 0, '(');
        u.insert(u.begin() + 6, ')');
        ret = min(ret, test(u, 1));  // (a+b+c)+d
        u = v;
        u.insert(u.begin() + 2, '(');
        u.insert(u.begin() + 8, ')');
        ret = min(ret, test(u, 1));  // a+(b+c+d)
        u = v;
        u.insert(u.begin() + 0, '(');
        u.insert(u.begin() + 1, '(');
        u.insert(u.begin() + 5, ')');
        u.insert(u.begin() + 8, ')');
        ret = min(ret, test(u, 1));  // ((a+b)+c)+d
        u = v;
        u.insert(u.begin() + 0, '(');
        u.insert(u.begin() + 3, '(');
        u.insert(u.begin() + 7, ')');
        u.insert(u.begin() + 8, ')');
        ret = min(ret, test(u, 1));  // (a+(b+c))+d
        u = v;
        u.insert(u.begin() + 2, '(');
        u.insert(u.begin() + 3, '(');
        u.insert(u.begin() + 7, ')');
        u.insert(u.begin() + 10, ')');
        ret = min(ret, test(u, 1));  // a+((b+c)+d)
        u = v;
        u.insert(u.begin() + 2, '(');
        u.insert(u.begin() + 5, '(');
        u.insert(u.begin() + 9, ')');
        u.insert(u.begin() + 10, ')');
        ret = min(ret, test(u, 1));  // a+(b+(c+d))
        u = v;
        u.insert(u.begin() + 0, '(');
        u.insert(u.begin() + 4, ')');
        u.insert(u.begin() + 6, '(');
        u.insert(u.begin() + 10, ')');
        ret = min(ret, test(u, 2));  // (a+b)+(c+d)
    }
    return ret;
}

int main1() {
    string s;
    s.push_back(100 + '0');
    s.push_back('/');
    s.push_back(100 + '0');
    cout << Expr::eval(s) << endl;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<pii> v(4);
    string strsrc;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        v[i] = {i, a};
        strsrc.push_back(a + '0');
    }
    int ans = inf;
    string strdst;
    do {
        vector<int> vi;
        strdst.clear();
        for (auto& p : v) vi.push_back(p.y), strdst.push_back(p.y + '0');
        int d = minswap(strsrc, strdst);
        ans = min(ans, solve(vi) + d * 2);
    } while (next_permutation(all(v)));
    if (ans == inf)
        cout << "impossible\n";
    else
        cout << ans << endl;
    return 0;
}