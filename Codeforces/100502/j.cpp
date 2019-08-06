#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define arrive first
#define madtime second
int t, n;
const int MAXN = 251;
vector<pii> wvec, evec;
int mtw[MAXN][MAXN][MAXN];
int mte[MAXN][MAXN][MAXN];

void judge(int w, int e, bool west, int mad) {
    if (west) {
        auto& car = wvec[w];
        int gotime = min(mtw[w][e][mad] + 3, mte[w][e][mad] + t);
        gotime = max(gotime, car.arrive);
        if (gotime > car.arrive + car.madtime) mad++;
        mtw[w + 1][e][mad] = min(gotime, mtw[w + 1][e][mad]);
    }  //
    else {
        auto& car = evec[e];
        int gotime = min(mtw[w][e][mad] + t, mte[w][e][mad] + 3);
        gotime = max(gotime, car.arrive);
        if (gotime > car.arrive + car.madtime) mad++;
        mte[w][e + 1][mad] = min(gotime, mte[w][e + 1][mad]);
    }
}

int solve() {
    cin >> t >> n;
    int ne = 0, nw = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        pii car;
        cin >> car.arrive >> car.madtime;
        auto& vec = c == 'E' ? evec : wvec;
        vec.push_back(car);
    }
    const int ww = wvec.size(), ee = evec.size();

    memset(mtw, 1, sizeof(mtw));
    memset(mte, 1, sizeof(mte));
    if (ww) mtw[1][0][0] = wvec[0].arrive;
    if (ee) mte[0][1][0] = evec[0].arrive;

    for (int sum = 1; sum <= n; sum++) {
        for (int w = 0, e = sum; w <= sum; w++, e--) {
            if (w > ww || e > ee) continue;
            for (int mad = 0; mad <= sum; mad++) {
                if (w < ww) judge(w, e, true, mad);
                if (e < ee) judge(w, e, false, mad);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (mtw[ww][ee][i] < 1e6 || mte[ww][ee][i] < 1e6) return i;
    }
    return n;
}

int main() {
    cout << solve() << endl;
    return 0;
}