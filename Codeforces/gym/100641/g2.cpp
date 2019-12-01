#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
double l[maxn];
int v[maxn];
double loc, t;
int vel, n, dst;

double rd(double d) { return ceil(d * 4) / 4; }

void solve() {
    for (int i = 0; i < n; i++) cin >> l[i] >> v[i];

    t = 0;
    while (loc <= dst) {
        // cout << loc << endl;
        int vsum = vel, ncand = 1;
        bool diff = false;
        for (int i = 0; i < n; i++) {
            double curl = l[i] + v[i] * t;
            if (curl >= loc - 1 && curl <= loc) {
                ncand++;
                vsum += v[i];
                diff |= (v[i] != vel);
            }
        }
            
        vel = vsum / ncand;
        if (loc + vel * 0.25 > dst) {
            t+= (dst-loc) / vel;
            return;
        }

        double nxtt = 0.25;
        if (!diff) {
            nxtt = (dst - loc) / vel;
            for (int i = 0; i < n; i++)
                if (v[i] != vel) {
                    double curl = l[i] + v[i] * t;
                    if (curl < loc -1 && v[i] > vel) {
                        nxtt = min(nxtt, rd((loc - 1 - curl) / (v[i] - vel)));
                    }  //
                    else if(curl > loc && v[i] < vel) {
                        nxtt = min(nxtt, rd((curl - loc) / (vel - v[i])));
                    }
                }
        }  //
        t += nxtt;
        loc += nxtt * vel;
        // cout << loc << ", " << t << ", " << vel << endl;
    }
}

int main() {
    int cs = 0;
    while (cin >> loc >> vel >> dst >> n && (loc || vel || dst || n)) {
        solve();
        printf("Case %d: Anna reaches her destination at time %.4f at a speed of %d\n", ++cs, t, vel);
    }
    return 0;
}