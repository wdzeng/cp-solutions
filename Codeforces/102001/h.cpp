#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
#define INF 2147483647

using namespace std;

const int maxn = 1e5 + 10;

int n, ones[maxn << 2], st[maxn << 2];

void build(int t, int l, int r) {
    if (r - l == 1) return st[t] = -l, void();
    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build(t << 1 | 1, mid, r);
    st[t] = min(st[t << 1], st[t << 1 | 1]);
}

void modify(int t, int l, int r, int x, int v) {
    if (r - l == 1) {
        if (v == 1)
            ones[t] = 1, st[t] = 1e9;
        else if (v == -1)
            ones[t] = 0, st[t] = 1e9;
        return;
    }
    int mid = (l + r) >> 1;
    if (x < mid)
        modify(t << 1, l, mid, x, v);
    else
        modify(t << 1 | 1, mid, r, x, v);
    st[t] = min(st[t << 1], st[t << 1 | 1]);
}

int query_ones(int t, int l, int r, int ql, int qr) {
    if (r <= ql || qr <= l) return 0;
    if (ql <= l && r <= qr) return ones[t];
    int mid = (l + r) >> 1;
    return query_ones(t << 1, l, mid, ql, qr) + query_ones(t << 1 | 1, mid, r, ql, qr);
}

int query_last_zero(int t, int l, int r, int ql, int qr) {
    if (r <= ql || qr <= l) return 1e9;
    if (ql <= l && r <= qr) return st[t];
    int mid = (l + r) >> 1;
    return min(query_last_zero(t << 1, l, mid, ql, qr), query_last_zero(t << 1 | 1, mid, r, ql, qr));
}

// 1-base, [)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, lm;
    cin >> n >> lm;
    build(1, 1, n + 1);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        if (v == 1) modify(1, 1, n + 1, i, 1);
        if (v == -1) modify(1, 1, n + 1, i, -1);
    }

    for (int i = 1; i <= n; i++) {
        cout << (query_ones(1, 1, n + 1, i, i + 1) ? 1 : -1) << ' ';
    }
    cout << endl;

    while (lm--) {
        int l, r, c;
        cin >> l >> r >> c;
        int n1 = query_ones(1, 1, n + 1, l, r + 1);
        cout << n1 << "?\n";
        c = max((l + c + 1) / 2, 0);
        c -= n1;
        while (c > 0) {
            int loc = query_last_zero(1, 1, n + 1, l, r + 1);
            //cout << loc << "!\n";
            if (loc > 0) {
                cout << "Impossible" << endl;
                return 0;
            }
            modify(1, 1, n + 1, -loc, 1);
            c--;
            
        }
        for (int i = 1; i <= n; i++) {
                cout << (query_ones(1, 1, n + 1, i, i + 1) ? 1 : -1) << ' ';
            }
            cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        cout << (query_ones(1, 1, n + 1, i, i + 1) ? 1 : -1) << " \n"[i == n];
    }
    return 0;
}
