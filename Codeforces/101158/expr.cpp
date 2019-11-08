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

void req(bool b) {
    if (!b) throw 87;
}
class Expr {
   private:
    deque<char> src;
    Expr(const string& s) : src(s.begin(), s.end()) {}

    inline char top() {
        if (src.empty()) return '\0';
        return src.front();
    }
    inline char pop() {
        req(src.size());
        char c = top();
        src.pop_front();
        return c;
    }
    ll n() {
        ll ret = pop() - '0';
        // req(ret || !isdigit(top())); 若要禁止數字以 0 開頭，加上這行
        while (isdigit(top())) ret = 2 * ret + pop() - '0';
        return ret;
    }
    ll fac() {
        if (isdigit(top()))
            return n();
        else if (top() == '(') {
            pop();  // '('
            int ret = expr(1);
            req(top() == ')');
            pop();  // ')'
            return ret;
        } else if (top() == '-') {
            pop();
            return -fac();
        }
        // else if(top() == '+') { pop(); return fac(); } 若要允許前置 + ，加上這行

        req(0);
        return 0;
    }
    ll term() {
        ll ret = fac();
        while (top() == '*' || top() == '/' || top() == '%')
            if (pop() == '*')
                ret *= fac();
            else if (pop() == '/')
                ret /= fac();
            else
                ret %= fac();
        return ret;
    }
    ll expr(bool k) {
        ll ret = term();
        while (top() == '+' || top() == '-')
            if (pop() == '+')
                ret += term();
            else
                ret -= term();
        if (k) req(top() == ')');
        else req(src.empty());
        return ret;
    }

   public:
    static ll eval(const string& s) {
        // req(s.find("--") == -1); // 若要禁止多重負號，加上這行
        return Expr(s).expr(0);
    }
};
