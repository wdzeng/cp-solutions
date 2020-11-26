#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

const int N = 3e5 + 10;
ll ranksum[N];
int scoreToNum[N];
int score[N];
ll debt[N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, w;
    cin >> n >> w;

    scoreToNum[0] = n;
    for (int i = 0; i < n; i++) ranksum[i] = w;
    int ww = w;

    while (w) {
        int t;
        cin >> t;
        while (t--) {
            int a;
            cin >> a;
            a--;

            int s = score[a];
            ranksum[a] += debt[s];
            debt[s] += w;

            score[a]++;
            scoreToNum[s]--;
            s++;

            ranksum[a] -= ll(scoreToNum[s]) * w;
            ranksum[a] -= debt[s];

            scoreToNum[s]++;
        }
        w--;
    }

    for (int i = 0; i < n; i++) {
        ranksum[i] += debt[score[i]];
        printf("%.12lf\n", 1.0 * ranksum[i] / ww);
    }
    return 0;
}