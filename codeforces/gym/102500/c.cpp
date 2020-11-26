#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define ms(v) memset(v, 0, sizeof(v))
#define mss(v) memset(v, -1, sizeof(v))

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> ll(n);
    vector<int> rr(n);
    vector<vector<int>> pag(n);

    for (int i = 0; i < n; i++) {
        cin >> ll[i] >> rr[i];
    }

    sort(all(ll));
    sort(all(rr));
    unordered_set<int> haspag;
    int p;
    cin >> p;

    while (p--) {
        int x;
        cin >> x;
        haspag.insert(x);
        auto a = upper_bound(all(ll), x);
        int index = a - ll.begin() - 1;
        if (index >= 0) {
            if (x < rr[index]) {
                pag[index].push_back(x);
            }
        }
        auto b = lower_bound(all(rr), x);
        if (b == rr.end()) continue;
        index = b - rr.begin();
        if (rr[index] == x) {
            pag[index].push_back(x);
        }
    }

    vector<int> ans;
    for (auto& pp : pag) {
        if (pp.size() > 2) {
            cout << "impossible\n";
            return 0;
        }
        sort(all(pp));
    }

    /*for (auto& pp : pag) {
        for (auto p : pp) cout << p << ' ';
        cout << endl;
    }*/

    for (int i = 0; i < n; i++) {
        auto& p = pag[i];
        // cout << '*' << p.size() << ' ';
        if (p.size() == 1) {
            if (i == n - 1) {
                for (int j = ll[i] + 1; j < rr[i]; j++) {
                    if (!haspag.count(j)) {
                        ans.push_back(j);
                        pag[i].push_back(j);
                        haspag.insert(j);
                        break;
                    }
                }
            } else {
                if (ll[i + 1] == rr[i]) {
                    if (pag[i + 1].size() == 2) {
                        for (int j = ll[i] + 1; j < rr[i]; j++) {
                            if (!haspag.count(j)) {
                                ans.push_back(j);
                                pag[i].push_back(j);
                                haspag.insert(j);
                                break;
                            }
                        }
                    } else {
                        if (haspag.count(rr[i])) {
                            for (int j = ll[i] + 1; j < rr[i]; j++) {
                                if (!haspag.count(j)) {
                                    ans.push_back(j);
                                    pag[i].push_back(j);
                                    haspag.insert(j);
                                    break;
                                }
                            }
                        } else {
                            ans.push_back(rr[i]);
                            pag[i + 1].push_back(rr[i]);
                            pag[i].push_back(rr[i]);
                            haspag.insert(rr[i]);
                        }
                    }
                } else {
                    for (int j = ll[i] + 1; j < rr[i]; j++) {
                        if (!haspag.count(j)) {
                            ans.push_back(j);
                            pag[i].push_back(j);
                            haspag.insert(j);
                            break;
                        }
                    }
                }
            }

        } else if (p.size() == 0) {
            for (int j = ll[i] + 1; j < rr[i]; j++) {
                if (!haspag.count(j)) {
                    ans.push_back(j);
                    pag[i].push_back(j);
                    haspag.insert(j);
                    break;
                }
            }
            // r
            if (i == n - 1) {
                for (int j = ll[i] + 1; j < rr[i]; j++) {
                    if (!haspag.count(j)) {
                        ans.push_back(j);
                        pag[i].push_back(j);
                        haspag.insert(j);
                        break;
                    }
                }
            } else {
                if (ll[i + 1] == rr[i]) {
                    if (pag[i + 1].size() == 2) {
                        for (int j = ll[i] + 1; j < rr[i]; j++) {
                            if (!haspag.count(j)) {
                                ans.push_back(j);
                                pag[i].push_back(j);
                                haspag.insert(j);
                                break;
                            }
                        }
                    } else {
                        if (haspag.count(rr[i])) {
                            for (int j = ll[i] + 1; j < rr[i]; j++) {
                                if (!haspag.count(j)) {
                                    ans.push_back(j);
                                    pag[i].push_back(j);
                                    haspag.insert(j);
                                    break;
                                }
                            }
                        } else {
                            ans.push_back(rr[i]);
                            pag[i + 1].push_back(rr[i]);
                            pag[i].push_back(rr[i]);
                            haspag.insert(rr[i]);
                        }
                    }
                } else {
                    for (int j = ll[i] + 1; j < rr[i]; j++) {
                        if (!haspag.count(j)) {
                            ans.push_back(j);
                            pag[i].push_back(j);
                            haspag.insert(j);
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;
    sort(all(ans));
    for (auto& val : ans) cout << val << ' ';
    cout << endl;

    return 0;
}