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
#define mss(a) memset(a, 1, sizeof(a))
#define mp(e, f) make_pair(e, f)

void reset(vector<pii>& varloc) {
    for (int i = 0; i < 26; i++) varloc[i] = {-1, -1};
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    const int M = 50000;
    int n;
    cin >> n;

    vector<string> warning;
    vector<vector<int>> q;
    vector<int> varloc(26, -1);
    string s;
    getline(cin, s); // throw away
    for (int l = 0; l < n; l++) {
        getline(cin, s);
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == '{') {
                q.push_back(varloc);
                varloc.assign(26, -1);
                continue;
            }
            if (s[i] == '}') {
                varloc.swap(q.back());
                q.pop_back();
                continue;
            }
            if (s[i] < 'a' || s[i] > 'z') {
                continue;
            }
            int index = s[i] - 'a';
            varloc[index] = l * M + i;

            int shadowed_loc = -1;
            for (int i = q.size() - 1; i >= 0 && shadowed_loc == -1; i--) {
                shadowed_loc = q[i][index];
            }
            if (shadowed_loc != -1) {
                printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n", l + 1, i + 1, s[i],
                       shadowed_loc / M + 1, shadowed_loc % M + 1);
            }
        }
    }

    return 0;
}