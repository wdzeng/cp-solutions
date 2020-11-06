#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

const ll inf = 1e9;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int nred, nblue;
    cin >> nred >> nblue;

    vector<pair<pii, char>> vec;
    pii red, blue;
    red.x = -inf;
    cin >> red.y;
    for (int i = 0; i < nred; i++) {
        ll x, y;
        cin >> x >> y;
        vec.push_back({{x, y}, 'R'});
    }
    blue.x = -inf;
    cin >> blue.y;
    for (int i = 0; i < nblue; i++) {
        ll x, y;
        cin >> x >> y;
        vec.push_back({{x, y}, 'B'});
    }

    sort(all(vec));

    int bound = 0;
    ll areasum = 0;
    ll area = 0;
    int clip = 0;
    for (auto& g : vec) {
        auto& p = g.x;
        if (g.y == 'R') {
            if (bound) {
                assert(blue.y > red.y);
                // cout << "+" << endl;
                ll prevx = max(red.x, blue.x);
                area += (p.x - prevx) * (blue.y - red.y);
            }
            if (p.y > blue.y && blue.y > red.y) {
                if (bound) {
                    clip++;
                    areasum += area;
                    area = 0;
                    bound = 0;
                }
            }
            if (p.y < blue.y && blue.y < red.y) {
                bound = 1;
            }
            red = p;
        }  //
        else {
            if (bound) {
                assert(blue.y > red.y);
                // cout << "+" << endl;
                ll prevx = max(red.x, blue.x);
                area += (p.x - prevx) * (blue.y - red.y);
            }
            if (p.y > red.y && red.y > blue.y) {
                bound = 1;
            }
            if (p.y < red.y && red.y < blue.y) {
                if (bound) {
                    clip++;
                    areasum += area;
                    area = 0;
                    bound = 0;
                }
            }
            blue = p;
        }
    }
    cout << clip << ' ' << areasum << endl;
    return 0;
}