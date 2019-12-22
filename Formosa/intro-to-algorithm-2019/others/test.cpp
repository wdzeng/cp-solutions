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

/**
 * Queries if there exists an arithmetic subsequence of s
 * whose length is not less than n/2 and common diffrerence
 * is d. The correct rate is 100% and the time complexity
 * is O(n).
 */
bool judge(vector<int>& s, int d) {
    int n = s.size();
    // Generates a hashset containing all the elements in s
    unordered_set<int> ss(iter(s));
    for (int i = 0; i < n; i++) {
        if (ss.count(s[i] - d) /* O(1) */) continue;
        int e = s[i];
        int counter = 0;
        while (2 * counter < n and ss.count(e)) {
            e += d;
            counter++;
        }
        if (2 * counter >= n) return true;
    }
    return false;
}

/**
 * Queries if there exists an arithmetic subsequence of
 * s whose length is not less than n/2. If such subsequence
 * exists, this function returns true with probability at
 * least 99%; if not exists, this function always returns
 * false. The time complexity is O(n).
 */
bool judge(vector<int>& s) {
    int n = s.size();
    const int K = 23, M = 23;
    // Assumed that n is very big, so the index is
    // always in the bound.
    for (int i = 0; i < K; i++) {      // O(1)
        for (int j = 0; j < M; j++) {  // O(1)
            int d = s[i + j] - s[i];
            if (judge(s, d)) {  // O(n)
                return true;
            }
        }
    }

    return false;
}

int main() {
    srand(time(0));
    // cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a, another;
    int d = rand() % 100 + 1;
    int a0 = rand() % 50000;
    for (int i = 0; 2 * i < n; i++) {
        a.push_back(a0 + i * d);
    }
    while (a.size() + another.size() < n) {
        another.push_back(rand() % 50000);
    }

    vector<int> s;
    for (int i = 0; i < n; i++) {
        s.push_back(i < a.size() ? 1 : 0);
    }
    random_shuffle(iter(s));

    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (s.back() == 1)
            v.push_back(a.back()), a.pop_back();
        else
            v.push_back(another.back()), another.pop_back();
        s.pop_back();
    }
    reverse(iter(v));
    cout << judge(v) << endl;
    return 0;
}
