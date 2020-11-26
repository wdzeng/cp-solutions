#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))
#define zz(v) int(v.size())

double prop[15];

unordered_map<string, double> Q;
double solveMax(const string s) {
    if (s.empty()) return 0;
    if (Q.count(s)) return Q[s];

    vector<string> cands[13];
    int n = s.size();
    int N = stoi(s);
    int SUM = 0;
    for (char c : s) SUM += c - '0';

    for (int m = 0; m < (1 << n); m++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (m >> i & 1) sum += s[i] - '0';
        }
        sum = SUM - sum;
        if (sum >= 2 && sum <= 12) {
            string added = "";
            for (int i = 0; i < n; i++) {
                if (m >> i & 1) added.push_back(s[i]);
            }
            cands[sum].push_back(added);
        }
    }

    double ret = 0;
    for (int sum = 2; sum <= 12; sum++) {
        if (cands[sum].empty()) {
            ret += prop[sum] * N;
        }  //
        else {
            double maxexp = -1;
            for (auto nxt : cands[sum]) maxexp = max(maxexp, solveMax(nxt));
            ret += prop[sum] * maxexp;
        }
    }

    return Q[s] = ret;
}

unordered_map<string, double> P;
double solveMin(const string s) {
    if (s.empty()) return 0;
    if (P.count(s)) return P[s];

    vector<string> cands[13];
    int n = s.size();
    int N = stoi(s);
    int SUM = 0;
    for (char c : s) SUM += c - '0';

    for (int m = 0; m < (1 << n); m++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (m >> i & 1) sum += s[i] - '0';
        }
        sum = SUM - sum;
        if (sum >= 2 && sum <= 12) {
            string added = "";
            for (int i = 0; i < n; i++) {
                if (m >> i & 1) added.push_back(s[i]);
            }
            cands[sum].push_back(added);
        }
    }

    double ret = 0;
    for (int sum = 2; sum <= 12; sum++) {
        if (cands[sum].empty()) {
            ret += prop[sum] * N;
        }  //
        else {
            double minexp = 1e18;
            for (auto nxt : cands[sum]) minexp = min(minexp, solveMin(nxt));
            ret += prop[sum] * minexp;
        }
    }

    return P[s] = ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++) prop[i + j]++;
    for (int i = 2; i <= 12; i++) prop[i] /= 36;

    string s;
    cin >> s;
    int SUM = 0;
    for (char c : s) SUM += c - '0';

    int a, b;
    cin >> a >> b;
    a += b;

    vector<string> M;
    int n = s.size();
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        string added = "";
        for (int j = 0; j < n; j++) {
            int d = s[j] - '0';
            if (i >> j & 1) {
                sum += d;
                added.push_back(s[j]);
            }
        }
        if (SUM - sum == a) {
            M.push_back(added);
        }
    }

    if (M.empty()) {
        printf("-1 %.5f\n", stof(s));
        printf("-1 %.5f\n", stof(s));
        return 0;
    }

    string minstr;
    double ans1 = 1e18;
    for (auto m : M) {
        double res = solveMin(m);
        if (res < ans1) {
            minstr = "";
            ans1 = res;
            set<char> every(all(s));
            for (char c : m) every.erase(c);
            for (char c : every) minstr.push_back(c);
        }
    }
    printf("%s %.5f\n", minstr.c_str(), ans1);

    string maxstr;
    double ans2 = -1;
    for (auto m : M) {
        double res = solveMax(m);
        if (res > ans2) {
            maxstr = "";
            ans2 = res;
            set<char> every(all(s));
            for (char c : m) every.erase(c);
            for (char c : every) maxstr.push_back(c);
        }
    }
    printf("%s %.5f\n", maxstr.c_str(), ans2);

    return 0;
}