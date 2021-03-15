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
#define ass(x) assert(x)
#define fastio()
#define debug(a) cerr << #a << ": " << a << endl
#else
#define ass(x)
#define endl '\n'
#define fastio() cin.tie(0), ios::sync_with_stdio(0)
#define debug(a)
#endif

const int L = 3e5 + 10, R = 3e5 + 10, B = 3e5 + 10;
const int H = 1e9 + 10;

typedef pair<int, int> Monkey;

vector<Monkey> mks;
map<int, int> lads[L];

struct Rope {
    int xl, xr, len, id, h;
    int sl, sr;
    ll srwlen, slwlen;
};

vector<Rope> ropes;

struct Banana {
    int show, hide, x, h;
};

vector<Banana> bananas;

int main() {
    fastio();
    int n, h, r, b;
    cin >> n >> h >> r >> b;
    ropes.resize(r + 1);

    for (int i = 1; i <= r; i++) {
        Rope& rope = ropes[i];

        int len, xl, xr, h;
        cin >> len >> xl >> xr >> h;
        xl--, xr--;
        if (xl > xr) swap(xl, xr);

        rope.len = len, rope.xl = xl, rope.xr = xr, rope.h = h;
    }
    for (int i = 0; i < n; i++) {
        int vy, vx;
        cin >> vy >> vx;
        mks.emplace_back(vx, vy);
    }
    for (int i = 0; i < b; i++) {
        int x, s, h, y;
        cin >> x >> y >> s >> h;
        x--;
        bananas.push_back({s, h, x, y});
    }
    sort(all(ropes), [](Rope& a, Rope& b) { return a.h < b.h; });
    for (int i = 1; i <= r; i++) {
        Rope& rope = ropes[i];
        rope.id = i;
        lads[rope.xl][-rope.h] = -i;
        lads[rope.xr][-rope.h] = i;
    }

    for (int i = 1; i <= r; i++) {
        Rope& rope = ropes[i];
        ass(rope.h > 0);
        int xl = rope.xl, xr = rope.xr, h = rope.h;

        ass(xl >= 0 && xl < n);
        ass(xr >= 0 && xr < n);

        auto ul = lads[xl].upper_bound(-h);
        auto ur = lads[xr].upper_bound(-h);

        if (ul == lads[xl].end()) {
            rope.sr = xl;
            rope.srwlen = rope.len;
        }  //
        else {
            int urpid = ul->y;
            ass(urpid && abs(urpid) <= r);

            if (urpid < 0)
                rope.sr = ropes[-urpid].sl, rope.srwlen = ropes[-urpid].slwlen + rope.len;
            else
                rope.sr = ropes[urpid].sr, rope.srwlen = ropes[urpid].srwlen + rope.len;
        }

        if (ur == lads[xr].end()) {
            rope.sl = xr;
            rope.slwlen = rope.len;
        }  //
        else {
            int urpid = ur->y;
            ass(urpid && abs(urpid) <= r);

            if (urpid < 0)
                rope.sl = ropes[-urpid].sl, rope.slwlen = ropes[-urpid].slwlen + rope.len;
            else
                rope.sl = ropes[urpid].sr, rope.slwlen = ropes[urpid].srwlen + rope.len;
        }

        debug(rope.sl);
        debug(rope.sr);
        debug(rope.slwlen);
        debug(rope.srwlen);
    }

    int ans = 0;
    for (auto& banana : bananas) {
        int x = banana.x;
        int h = banana.h;
        debug(x);
        debug(h);
        auto ur = lads[x].upper_bound(-h);
        int s = -1;

        ll wlen;
        if (ur == lads[x].end())
            s = x, wlen = 0;
        else {
            int id = ur->y;
            ass(id && abs(id) <= r);
            if (id < 0) {
                s = ropes[-id].sl, wlen = ropes[-id].slwlen;
            } else {
                s = ropes[id].sr, wlen = ropes[id].srwlen;
            }
        }
        debug(s);
        debug(wlen);
        ass(s >= 0);

        ll t = 1ll * h * mks[s].y + 1ll * wlen * mks[s].x;
        debug(t);
        t += banana.show + banana.hide;
        t--;
        ass(t >= 0);
        ll trem = t % (banana.show + banana.hide);
        if (trem < banana.show) {
            // cout << "banana" << i << " : " << s << endl;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}