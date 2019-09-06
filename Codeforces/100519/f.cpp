#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const double PI = acos(-1);
#define x first
#define y second
#define iter(c) c.begin(), c.end()
#define ms(a) memset(a, 0, sizeof(a))
#define mss(a) memset(a, -1, sizeof(a))
#define mp(e, f) make_pair(e, f)

double len(pii& a, pii& b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

bool online(pii& p, pii& a, pii& b) { return (p.y - a.y) * (p.x - b.x) - (p.x - a.x) * (p.y - b.y) == 0; }

int dur(const string& dep, const string& arr) {
    int minutes = (stoi(arr.substr(0, 2)) - stoi(dep.substr(0, 2))) * 60 + (stoi(arr.substr(3)) - stoi(dep.substr(3)));
    if (minutes < 0) minutes += 1440;
    return minutes;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    pii a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    int d, valex;
    cin >> d >> valex;
    double talex = (len(a, c) + len(b, c)) * 60 / valex + d;

    string dep, dura;
    cin >> dep >> dura;
    double tdmitry = dur("00:00", dura) + dur("09:00", dep);

    int vpetr;
    cin >> vpetr;
    double tpetr = len(a, b) * 60 / vpetr + (online(c, a, b) ? d : 0);

    if (talex < tpetr && talex < tdmitry)
        cout << "Alex" << endl;
    else if (tpetr < talex && tpetr < tdmitry)
        cout << "Petr" << endl;
    else
        cout << "Dmitry" << endl;
    return 0;
}