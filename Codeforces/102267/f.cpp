#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846264338327950288419716939937510L
using namespace std;
struct f {
    int x, y;
    long double maxangle, minangle;
    f(int x, int y, int a, int r) : x(x), y(y) {
        maxangle = a + r;
        if (maxangle >= 360) maxangle -= 360;
        minangle = a - r;
        if (minangle < 0) minangle += 360;
        maxangle *= (M_PI / 180.0);
        minangle *= (M_PI / 180.0);
    };
    bool cansee(f& o) {
        long double deg = atan2((long double)o.y - y, (long double)o.x - x);
        if (deg < 0) deg += M_PI * 2.0;
        if (maxangle < minangle) return deg >= minangle || deg <= maxangle;
        return minangle <= deg && deg <= maxangle;
    }
};
int main() {
    int n;
    cin >> n;
    vector<f> vec;
    for (int i = 0; i < n; i++) {
        int x, y, a, r;
        cin >> x >> y >> a >> r;
        vec.push_back(f(x, y, a, r));
    }

    vector<vector<int>> watched(n);
    vector<vector<int>> watching(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vec[i].cansee(vec[j])) {
                watched[j].push_back(i);
                watching[i].push_back(j);
            }
            if (vec[j].cansee(vec[i])) {
                watched[i].push_back(j);
                watching[j].push_back(i);
            }
        }
    }

    vector<int> ans;
    vector<bool> dead(n, false);
    list<int> q;
    for (int i = 0; i < n; i++)
        if (watched[i].empty()) q.push_back(i);

    while (!q.empty()) {
        int i = q.front();
        q.pop_front();
        if (dead[i]) continue;
        if (ans.size() < watched[i].size()) continue;

        bool isshot = true;
        for (int w : watched[i]) {
            if (!dead[w]) {
                isshot = false;
                break;
            }
        }
        if (isshot) {
            for (int w : watching[i]) q.push_back(w);
            ans.push_back(i);
            dead[i] = true;
        }
    }

    if (ans.size() != n)
        cout << "-1\n";
    else {
        for (int a : ans) cout << (a + 1) << " ";
        cout << endl;
    }

    return 0;
}