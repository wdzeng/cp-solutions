#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define hit 1
#define attack 2
#define defend 3
#define heal 4

struct ma {
    int id;
    int hp = 10, att = 0, def = 0;
    vector<int> h = vector<int>(6);
    vector<int> a = vector<int>(6);
    vector<int> d = vector<int>(6);
    vector<bool> ht = vector<bool>(6);
    void settle(const vector<pair<int, int>>& vec) {
        for (int i = 0; i < 6; i++) {
            int maxx = 0;
            for (int x = 0; x < i + 5; x++) {
                if (vec[x].first == heal) maxx = max(maxx, vec[x].second);
            }
            h[i] = maxx;
        }
        for (int i = 0; i < 6; i++) {
            int maxx = 0;
            for (int x = 0; x < i + 5; x++) {
                if (vec[x].first == attack) maxx = max(maxx, vec[x].second);
            }
            a[i] = maxx;
        }
        for (int i = 0; i < 6; i++) {
            int maxx = 0;
            for (int x = 0; x < i + 5; x++) {
                if (vec[x].first == defend) maxx = max(maxx, vec[x].second);
            }
            d[i] = maxx;
        }
        for (int i = 0; i < 6; i++) {
            bool hitable = false;
            for (int x = 0; x < i + 5; x++) {
                if (vec[x].first == hit) {
                    hitable = true;
                    break;
                }
            }
            ht[i] = hitable;
        }
    }
    int canhitat(int r) {
        r++;
        return ht[r / 2 - 1];
    }
    int attackat(int r) {
        r++;
        return a[r / 2 - 1];
    }
    int defendat(int r) {
        r++;
        return d[r / 2 - 1];
    }
    int healat(int r) {
        r++;
        return h[r / 2 - 1];
    }
};

ma init() {
    vector<pair<int, int>> vec(10);
    for (int i = 0; i < 10; i++) {
        string o1;
        cin >> o1;
        if (o1 == "HIT!") {
            vec[i] = {hit, 0};
        } else if (o1 == "Def") {
            int x;
            cin >> x;
            vec[i] = {defend, x};
        } else if (o1 == "Atk") {
            int x;
            cin >> x;
            vec[i] = {attack, x};
        } else if (o1 == "Heal") {
            int x;
            cin >> x;
            vec[i] = {heal, x};
        } else {
            throw "";
        }
    }
    ma m;
    m.settle(vec);
    return m;
}

pair<int, int> better(int id, pair<int, int> a, pair<int, int> b) {
    if (a.first == -1) return b;
    if (b.first == -1) return a;
    if (a.first == id && b.first == id) return a.second < b.second ? a : b;
    if (a.first != id && b.first != id) return a.second > b.second ? a : b;
    if (a.first == id) return a;
    return b;
}

pair<int, int> play(int round, ma& m1, ma& m2) {
    if (round > 12) {
        return {m1.id, round};
    }

    pair<int, int> lim = {-1, 0};
    bool dosomething = false;

    if (m1.canhitat(round) && m1.att > m2.def) {
        int loss = (m1.att - m2.def);
        m2.hp -= loss;
        if (m2.hp <= 0) {
            m2.hp += loss;
            return {m1.id, round};
        }
        lim = better(m1.id, lim, play(round + 1, m2, m1));
        m2.hp += loss;
        dosomething = true;
    }

    int h = m1.healat(round);
    int after_heal = min(10, m1.hp + h);
    if (after_heal > m1.hp) {
        int added = after_heal - m1.hp;
        m1.hp += added;
        lim = better(m1.id, lim, play(round + 1, m2, m1));
        m1.hp -= added;
        dosomething = true;
    }

    int a = m1.attackat(round);
    if (a > m1.att) {
        int added = a - m1.att;
        m1.att += added;
        lim = better(m1.id, lim, play(round + 1, m2, m1));
        m1.att -= added;
        dosomething = true;
    }

    int d = m1.defendat(round);
    if (d > m1.def) {
        int added = d - m1.def;
        m1.def += added;
        lim = better(m1.id, lim, play(round + 1, m2, m1));
        m1.def -= added;
        dosomething = true;
    }

    if (!dosomething) return better(m1.id, lim, play(round + 1, m2, m1));
    return lim;
}

pair<int, int> solve() {
    ma m1 = init();
    ma m2 = init();
    m1.id = 1;
    m2.id = 2;

    return play(1, m1, m2);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        auto a = solve();
        if (a.first != 1 && a.first != 2) throw "";
        printf("Case #%d: %s %d\n", i, a.first == 1 ? "win" : "lose", a.second);
    }
    return 0;
}