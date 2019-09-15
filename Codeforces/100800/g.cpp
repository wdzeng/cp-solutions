#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

typedef pair<pair<string, int>, int> wine;
#define name first.first
#define take first.second
#define cost second

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    double m;
    cin >> m;
    int money = round(m * 100);

    double a;
    cin >> a;
    int alcohol = round(a * 10) * 6;

    int d;
    cin >> d;
    vector<wine> ws;
    while (d--) {
        wine w;
        cin >> w.name;

        int p;
        cin >> p;
        string szz;
        cin >> szz;
        int z = stoi(szz.substr(2));
        z = 6 / z;
        p *= z;
        w.take = p * 10;

        double cc;
        cin >> cc;
        w.cost = round(cc * 100);

        ws.push_back(w);
    }

    vector<vector<vector<int>>> dp(money + 1, vector<vector<int>>(alcohol + 1));
    for (int w = 0; w < ws.size(); w++) {
        vector<vector<vector<int>>> u(money + 1, vector<vector<int>>(alcohol + 1));
        for (int m = 0; m <= money; m++) {
            for (int a = 0; a <= alcohol; a++) {
                auto& v = dp[m][a];
                if (v.empty() && (m != 0 || a != 0)) continue;
                int cst = m;
                int c2h5oh = a;
                while (cst <= money && c2h5oh <= alcohol) {
                    u[cst][c2h5oh] = v;
                    cst += ws[w].cost;
                    c2h5oh += ws[w].take;
                    v.push_back(w);
                }
            }
        }
        dp.swap(u);
    }

    auto& v = dp[money][alcohol];
    if (v.empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    sort(iter(v));
    map<int, int> mmap;
    for (int i : v) mmap[i]++;

    for (auto& p : mmap) {
        int i = p.first;
        cout << ws[i].name << ' ' << p.second << '\n';
    }
    return 0;
}