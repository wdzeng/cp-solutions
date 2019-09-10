#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

// AC

struct building {
    int x0, x1, h;
    bool operator<(const building& o) const { x0 < o.x0; }
};

struct skyline {
    int x, h;
};

list<skyline> merge(list<skyline>& a, list<skyline>& b) {
    int ha = 0, hb = 0;
    auto ita = a.begin(), itb = b.begin();
    list<skyline> ret;
    while (ita != a.end() && itb != b.end()) {
        if (ita->x == itb->x) {
            ha = ita->h;
            hb = itb->h;
            int maxh = max(ha, hb);
            if (ret.empty() || ret.back().h != maxh)
                ret.push_back({.x = ita->x, .h = maxh});
            ita++;
            itb++;
        } else if (ita->x < itb->x) {
            ha = ita->h;
            int maxh = max(ha, hb);
            if (ret.empty() || ret.back().h != maxh)
                ret.push_back({.x = ita->x, .h = maxh});
            ita++;
        } else {
            hb = itb->h;
            int maxh = max(ha, hb);
            if (ret.empty() || ret.back().h != maxh)
                ret.push_back({.x = itb->x, .h = maxh});
            itb++;
        }
    }

    // tails
    ret.splice(ret.end(), a, ita, a.end());
    ret.splice(ret.end(), b, itb, b.end());

    return ret;
}

list<skyline> b2s(const building& b) {
    list<skyline> ls;
    ls.push_back({.x = b.x0, .h = b.h});
    ls.push_back({.x = b.x1, .h = 0});
    return ls;
}

list<skyline> merge(vector<building>& group) {
    int size = group.size();
    if (size == 1) return b2s(group[0]);
    if (size == 2) {
        list<skyline> a = b2s(group[0]), b = b2s(group[1]);
        return merge(a, b);
    }
    auto midit = group.begin() + (size >> 1);
    vector<building> left = vector<building>(group.begin(), midit),
                     right = vector<building>(midit, group.end());
    auto la = merge(left), lb = merge(right);
    return merge(la, lb);
}

int main() {
    int n;
    cin >> n;
    vector<building> v(n);

    int x, h, w;
    while (n--) {
        cin >> x >> h >> w;
        v[n].x0 = x;
        v[n].x1 = x + w;
        v[n].h = h;
    }
    sort(v.begin(), v.end());
    auto res = merge(v);

    long p = 0;
    long area = 0;
    long px = res.front().x, ph = 0;
    for (skyline& l : res) {
        long _x = l.x - px;
        long _h = abs(l.h - ph);
        area += _x * ph;
        p += _h;
        //cout << "### " << _h << endl;
        if (ph) {
            p += l.x - px;
            //cout << "::: " << l.x - px << endl;
        }
        px = l.x;
        ph = l.h;
    }
    cout << p << " " << area << endl;
    return 0;
}