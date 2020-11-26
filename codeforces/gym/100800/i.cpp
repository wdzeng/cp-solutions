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

char hards[] = {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};

int remove_dash(string& s) {
    int fd = INT_MAX;
    string updated;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != '-') {
            updated += c;
        } else {
            fd = min(fd, i);
        }
    }
    s.swap(updated);
    return fd;
}

void opt(string& s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++) s[i] = tolower(s[i]);
}

char find_prefix(char c) {
    c = tolower(c);
    char ret;
    int minn = 100;
    for (char cand : hards) {
        int dist = abs(c - cand);
        if (dist < minn) {
            ret = cand;
            minn = dist;
        }
    }
    return ret;
}

char find_suffix(char c) {
    // c = tolower(c);
    int a = abs(c - 'a');
    int o = abs(c - 'o');
    int u = abs(c - 'u');
    if (a <= o && a <= u) return 'a';
    if (o <= a && o <= u) return 'o';
    return 'u';
}

bool is_hard(char c) { return binary_search(hards, hards + 8, c); }

char last_hard(const string& s) {
    for (int i = s.size() - 1; i > -1; i--) {
        if (is_hard(s[i])) return s[i];
    }
    assert(false);
}

void fix(string& s, int fd) {
    char h = find_prefix(s[0]);
    s[0] = h;
    for (int i = 1; i < s.size(); i++) {
        if (i >= fd && is_hard(s[i])) s[i] = h;
    }

    if (is_hard(s.back())) {
        char lh = last_hard(s);
        char suf = find_suffix(lh);
        s += suf;
        s += 'h';
    }
}

void task(string& s) {
    bool up = 'A' <= s[0] && s[0] <= 'Z';
    int f = remove_dash(s);
    fix(s, f);
    if (up) s[0] = toupper(s[0]);
}

int main() {
    // cin.tie(0), ios::sync_with_stdio(0);
    string w;
    while (cin >> w) {
        task(w);
        cout << ' ' << w;
    }
    return 0;
}