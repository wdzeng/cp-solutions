#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int inf = INT_MAX;

struct Car {
    int vel, initloc;
    double loc(double t) { return initloc + vel * t; }
} car[maxn];

int vel, dst, n;
double loc;

double round_time(double a /* a!=0 */, double b) {
    if (a == 0) throw "";
    double d = ceil(a * 4) / 4;
    return d <= b ? d : inf;
}

bool is_next(double lm, double lh) { return lh >= lm - 1 && lh <= lm; }

double hit(double lm, int vm, double lh, int vh) {
    // la <= lb
    if (is_next(lm, lh)) {
        double newlm = lm + vm * 0.25, newlh = lh + vh * 0.25;
        return is_next(newlm, newlh) ? 0.25 : inf;
    }  //
    else if (lh < lm) {
        if (vh <= vm) return inf;
        double hitback = (lm - 1 - lh) / (vh - vm);
        double hitfront = (lm - lh) / (vh - vm);
        return round_time(hitback, hitfront);
    }  //
    else {
        if (vm <= vh) return inf;
        double hitfront = (lh - lm) / (vm - vh);
        double hitback = (lh - lm + 1) / (vm - vh);
        return round_time(hitfront, hitback);
    }
}

bool is_stable(const vector<int>& cand, double t) {
    bool iscand[n];
    memset(iscand, false, sizeof(iscand));
    for (int i : cand) iscand[i] = true;
    for (int i = 0; i < n; i++)
        if (!iscand[i])
            if (hit(loc, vel, car[i].loc(t), car[i].vel) != inf) return false;
    for (int i : cand)
        if (car[i].vel != vel) return false;
    return true;
}

void task(double& t) {
    double mint = inf;
    vector<int> cand;
    bool stable = true;
    bool samevel = true;
    for (int i = 0; i < n; i++) {
        double nxtt = hit(loc, vel, car[i].loc(t), car[i].vel);
        // cout << nxtt << endl;
        if (nxtt == inf) continue;
        if (nxtt < mint) {
            mint = nxtt;
            if(!cand.empty()) stable = false;
            cand.clear();
            samevel = true;
        }
        if (nxtt == mint) {
            if (car[i].vel != vel) samevel = false;
            cand.push_back(i);
        } //
        else {
            stable = false;
        }
    }
    if (mint == inf || loc + vel * mint > dst || (stable && samevel)) {
        t += (dst - loc) / vel;
        loc = dst;
        return;
    }

    loc += vel * mint;
    t += mint;
    int velsum = vel;
    for (int i : cand) velsum += car[i].vel;
    vel = floor((double)velsum / (cand.size() + 1));
    // printf("(time, loc, vel) = (%.4f, %.4f, %d)\n", t, loc, vel);
}

pair<double, int> solve() {
    int velsum = vel, ncand = 1;
    for (int i = 0; i < n; i++) {
        cin >> car[i].initloc >> car[i].vel;
        if (is_next(loc, car[i].initloc)) {
            velsum += car[i].vel;
            ncand++;
        }
    }
    vel = floor((double)velsum / ncand);

    double t = 0;
    while (loc < dst) task(t);
    return {t, vel};
}

int main() {
    int cs = 0;
    while (cin >> loc >> vel >> dst >> n && (loc || vel || dst || n)) {
        auto ans = solve();
        printf("Case %d: Anna reaches her destination at time %.4f at a speed of %d\n", ++cs, ans.first, ans.second);
    }
    return 0;
}