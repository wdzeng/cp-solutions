#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

struct davidtree {
    vector<bool> stamp;
    vector<pii> arr;
    int counter = 0;
    int N;

    davidtree(int n) : N(n) {
        arr.resize(4 * N);
        stamp.assign(4 * N, false);
        stamp[0] = true;
        arr[0] = {INT_MAX, -1};
    }

    // set all values in [l, r] to len.
    void range_set(int l, int r, int len) {
        counter++;
        range_set(0, 0, N - 1, l, r, len);
    }

    // at index i, this node represents range [curl, curr]; a user wants to set [tarl, tarr] to value len.
    void range_set(int i, int curl, int curr, int tarl, int tarr, int len) {
        // no intersection
        if (curl > tarr || curr < tarl) {
            return;
        }
        // combined
        if (tarl <= curl && curr <= tarr) {
            if (stamp[i]) {
                arr[i] = min(arr[i], {len, counter});
                return;
            }
        }

        // kick down
        if (stamp[i]) {
            stamp[i * 2 + 1] = stamp[i * 2 + 2] = true;
            arr[i * 2 + 1] = arr[i * 2 + 2] = arr[i];
            cout << flush;
        }

        // go down
        stamp[i] = false;
        int m = (curl + curr) / 2;
        range_set(i * 2 + 1, curl, m, tarl, tarr, len);
        range_set(i * 2 + 2, m + 1, curr, tarl, tarr, len);

        // if this node has no stamp, check if it can have a stamp.
        if (!stamp[i] && stamp[i * 2 + 1] && stamp[i * 2 + 2] && arr[i * 2 + 1] == arr[i * 2 + 2]) {
            cout << flush;
            stamp[i] = true;
            arr[i] = arr[i * 2 + 1];
        }
    }

    int query(int i) { query(0, 0, N - 1, i); }

    // at tree index i, this node represents range [curl, curr]; a user wants to query array index tar;
    // the function returns the value that locates at array index tar.
    int query(int i, int curl, int curr, int tar) {
        if (stamp[i]) return arr[i].second;

        int m = (curl + curr) / 2;
        return tar <= m ? query(i * 2 + 1, curl, m, tar) : query(i * 2 + 2, m + 1, curr, tar);
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<pii> segments;
    vector<int> queries;
    set<int> all_nums;
    unordered_map<int, int> order;

    int nseg;
    cin >> nseg;
    for (int i = 0; i < nseg; i++) {
        pii s;
        cin >> s.first >> s.second;
        segments.push_back(s);
        all_nums.insert(s.first);
        all_nums.insert(s.second);
    }

    int nq;
    cin >> nq;
    while (nq--) {
        int x;
        cin >> x;
        queries.push_back(x);
        all_nums.insert(x);
    }

    int counter = 0;
    for (int num : all_nums) order[num] = counter++;

    davidtree dt(order.size());
    for (auto& sg : segments) {
        dt.range_set(order[sg.first], order[sg.second], sg.second - sg.first);
    }

    for (int q : queries) {
        cout << dt.query(order[q]) << endl;
    }

    return 0;
}