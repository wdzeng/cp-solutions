#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
typedef long long ll;
using namespace std;
// AC
double dist(ll x1, ll y1, ll x2, ll y2) {
    ll dx = x1 - x2;
    ll dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

double area(double a, double b, double c) {
    double s = (double)(a + b + c) / 2;
    // cout << s << " " << a<< " " << b << " "<< c << endl;
    double ret = sqrt(s * (s - a) * (s - b) * (s - c));
    // cout << ret << endl;
    return ret;
}

double solve() {
    ll x[4], y[4];
    ll price;
    for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
    cin >> price;
    double e01 = dist(x[0], y[0], x[1], y[1]);
    double e02 = dist(x[0], y[0], x[2], y[2]);
    double e03 = dist(x[0], y[0], x[3], y[3]);
    double e12 = dist(x[1], y[1], x[2], y[2]);
    double e13 = dist(x[1], y[1], x[3], y[3]);
    double e23 = dist(x[2], y[2], x[3], y[3]);

    double a012_230 = area(e01, e12, e02) + area(e23, e03, e02);
    double a123_301 = area(e12, e23, e13) + area(e03, e01, e13);
    double a230_012 = area(e23, e03, e02) + area(e01, e12, e02);
    double a301_123 = area(e03, e01, e13) + area(e12, e23, e13);
    double ret = min(a012_230, min(a123_301, min(a230_012, a301_123)));
    return price / ret;
}

int main() {
    int t;
    cin >> t;
    if (t == 0) return 0;
    cout << setprecision(2) << fixed;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}