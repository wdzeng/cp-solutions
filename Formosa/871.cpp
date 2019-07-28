#include <iostream>
#include <list>
#include <vector>
using namespace std;

// AC

struct pass {
    int come, plane, walk;
};

struct server {
    int a, b;
    bool work(int t) {
        int r = t % (a + b);
        return r <= a && r != 0;
    }
};

list<pass> await;
list<pass> normal, vip;
vector<server> servers;

int fail = 0;

void pass_come(int t) {
    if (await.empty()) return;
    pass p = await.front();
    if (p.come > t) return;
    await.pop_front();
    normal.push_back(p);
}

void promote(int t) {
    auto it = normal.begin();
    while (it != normal.end()) {
        if (t + 30 >= it->plane) {
            pass p = *it;
            it = normal.erase(it);
            vip.push_back(p);
            // cout << "P" << p.come << " promoted at t" << t << endl;
        } else {
            it++;
        }
    }
}

void serve(int t) {
    auto* passes = &vip;
    for (server s : servers) {
        if (passes->empty()) {
            if (passes == &vip && !normal.empty())
                passes = &normal;
            else
                return;
        }
        if (s.work(t)) {
            pass p = passes->front();
            passes->pop_front();
            // cout << "P" << p.come << " served at T" << t <<endl;
            if (t + 1 + p.walk > p.plane) {
                fail++;
            }
        }
    }
}

int main() {
    int np, ns;
    cin >> np >> ns;

    while (ns--) {
        server s;
        cin >> s.a >> s.b;
        servers.push_back(s);
    }

    while (np--) {
        pass p;
        cin >> p.come >> p.plane >> p.walk;
        await.push_back(p);
    }

    for (int t = 1; t <= 50001; t++) {
        pass_come(t);
        promote(t);
        serve(t);
    }

    cout << fail << endl;
    return 0;
}