#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define iter(x) x.begin(), x.end()
#define ms(x) memset(x, 0, sizeof(x))
#define mss(x) memset(x, -1, sizeof(x))
#define money first
#define ad second

vector<pii> alone, share;
int adone, adtwo;
int money;
vector<pii> fd;
vector<pair<int, pii>> hs;

pair<pii, int> la() {
    int maxad = -1;
    int elect = -1;
    int nperson = -1;
    for (int i = 0; i < hs.size(); i++) {
        if (hs[i].second.money > money) continue;
        int myad = hs[i].first == 1 ? adone : adtwo;
        int ad = hs[i].second.ad + myad;
        if (ad > maxad) {
            maxad = ad;
            elect = i + 1;
            nperson = hs[i].first;
        }
    }
    return {{elect, nperson}, maxad};
}

pair<pii, int> ls() {
    int maxad = -1, ef = -1, eh = -1;
    for (int h = 0; h < hs.size(); h++) {
        if (hs[h].first == 1) continue;
        int cost = (hs[h].second.money + 1) / 2;
        if (cost > money) continue;
        for (int f = 0; f < fd.size(); f++) {
            if (cost > fd[f].money) continue;
            int ad = fd[f].ad + hs[h].second.ad;
            if (ad > maxad) {
                maxad = ad;
                ef = f + 1;
                eh = h + 1;
            }
        }
    }

    return {{ef, eh}, maxad};
}

int main() {
    cin.tie(NULL), ios::sync_with_stdio(false);
    int nfriend;
    cin >> money >> adone >> adtwo >> nfriend;
    for (int i = 0; i < nfriend; i++) {
        pii p;
        cin >> p.money >> p.ad;
        fd.push_back(p);
    }
    int nhouse;
    cin >> nhouse;
    for (int i = 0; i < nhouse; i++) {
        pair<int, pii> p;
        cin >> p.first;
        cin >> p.second.money >> p.second.ad;
        hs.push_back(p);
    }

    pair<pii, int> l1 = la(), l2 = ls();
    auto& best = l1.ad > l2.ad ? l1 : l2;
    if (best.ad == -1) {
        cout << "Forget about apartments. Live in the dormitory.";
    }
    else if (l1.ad > l2.ad) {
        int i = l1.first.first;
        printf("You should rent the apartment #%d alone.", i);
    } else {
        int ih = l2.first.second, ifd = l2.first.first;
        printf("You should rent the apartment #%d with the friend #%d.", ih, ifd);
    }
    return 0;
}