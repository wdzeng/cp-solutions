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

const double PI = acos(-1);
typedef complex<double> C;
namespace FFT {

void bit_reverse(vector<C>& v) {
    int n = v.size();
    for (int i = 1, j = n / 2; i < n - 1; i++) {
        if (i < j) swap(v[i], v[j]);
        int k = n / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
}

// Given a function whose co-efficient is v, calculates its FFT and stores
// resulting co-efficients in local. Length of v MUST be 2^N.
void fft(vector<C>& v, bool is_inverse = false) {
    int n = v.size(), len = __lg(n), f = is_inverse ? -1 : 1;
    assert(n == (1 << len));
    bit_reverse(v);
    for (int k = 2; k <= n; k <<= 1) {
        int m = k >> 1;
        for (int i = 0; i < m; i++) {
            C c = {0, i * f * PI / m};
            auto w = exp(c);
            for (int j = i; j < n; j += k) {
                int k = j + m;
                C s = v[j], t = w * v[k];
                v[j] = s + t, v[k] = s - t;
            }
        }
    }
    if (is_inverse)
        for (int i = 0; i < n; ++i) v[i] /= n;
}

};  // namespace FFT

int getr(C &c) { return round(real(c)); }

const int len = 262144;
int main() {
    int dump;
    cin >> dump >> dump;
    string _s, _t;
    cin >> _s >> _t;
    reverse(all(_t));

    // check rock
    vector<C> sr(len), tr(len), ss(len), ts(len), sp(len), tp(len);
    for (int i = 0; i < zz(_s); i++)
        if (_s[i] == 'R')
            sr[i].real(1);
        else if (_s[i] == 'S')
            ss[i].real(1);
        else
            sp[i].real(1);
    for (int i = 0; i < zz(_t); i++)
        if (_t[i] == 'R')
            tr[i].real(1);
        else if (_t[i] == 'S')
            ts[i].real(1);
        else
            tp[i].real(1);
    FFT::fft(sr);
    FFT::fft(ss);
    FFT::fft(sp);
    FFT::fft(tr);
    FFT::fft(ts);
    FFT::fft(tp);
    for (int i = 0; i < len; i++) sr[i] = sr[i] * tp[i];
    for (int i = 0; i < len; i++) ss[i] = ss[i] * tr[i];
    for (int i = 0; i < len; i++) sp[i] = sp[i] * ts[i];
    FFT::fft(sr, 1);
    FFT::fft(ss, 1);
    FFT::fft(sp, 1);
    int ans = 0;
    for (int i = zz(_t) - 1; i < zz(_t) - 1 + zz(_s); i++) {
        ans = max(ans, getr(sr[i]) + getr(ss[i]) + getr(sp[i]));
    }
    cout << ans << endl;
}