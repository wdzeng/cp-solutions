#include <bits/stdc++.h>
using namespace std;
const int INFTY = 10000000;

vector<vector<int>> input_cost(int n) {
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < cost.size(); i++) {
        cost[i][i] = INFTY;
        for (int j = i + 1; j < cost.size(); j++) {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }
    return cost;
}

vector<vector<int>> reduce(vector<vector<int>> cost) {
    for (int r = 0; r < cost.size(); r++) {
        int red = INFTY;
        for (int c = 0; c < cost.size(); c++) red = min(red, cost[r][c]);
        for (int c = 0; c < cost.size(); c++) cost[r][c] -= red;
    }
    for (int c = 0; c < cost.size(); c++) {
        int red = INFTY;
        for (int r = 0; r < cost.size(); r++) red = min(red, cost[r][c]);
        for (int r = 0; r < cost.size(); r++) cost[r][c] -= red;
    }
    return cost;
}

bool try_match(const vector<vector<int>>& cost, int src, vector<int>& r2c, vector<int>& c2r, vector<bool>& forbidden) {
    if (r2c[src] != -1) return true;
    // find empty
    for (int j = 0; j < cost.size(); j++) {
        if (cost[src][j] == 0 && c2r[j] == -1 && !forbidden[j]) {
            r2c[src] = j;
            c2r[j] = src;
            return true;
        }
    }
    // try all
    for (int j = 0; j < cost.size(); j++) {
        if (cost[src][j] == 0 && !forbidden[j]) {
            auto newforbidden = forbidden;
            newforbidden[j] = true;
            int orgsrc = c2r[j];
            r2c[orgsrc] = -1;
            r2c[src] = j;
            c2r[j] = src;
            if (try_match(cost, orgsrc, r2c, c2r, newforbidden)) return true;

            r2c[orgsrc] = j;
            r2c[src] = -1;
            c2r[j] = orgsrc;
        }
    }
    return false;
}

pair<vector<int>, vector<int>> max_match(const vector<vector<int>>& cost) {
    vector<int> r2c(cost.size(), -1), c2r(cost.size(), -1);
    vector<bool> fb(cost.size(), false);
    for (int src = 0; src < cost.size(); src++) try_match(cost, src, r2c, c2r, fb);
    return {r2c, c2r};
}

bool is_valid_match(const vector<int>& r2c) {
    for (int j : r2c)
        if (j == -1) return false;
    return true;
}

int is_covered(int r, int c, const vector<bool>& ticked_row, const vector<bool>& ticked_col) {
    int ret = 0;
    if (ticked_col[c]) ret++;
    if (!ticked_row[r]) ret++;
    return ret;
}

bool is_all_zero_covered(const vector<vector<int>>& cost, const vector<bool>& ticked_row, const vector<bool>& ticked_col) {
    for (int r = 0; r < cost.size(); r++)
        for (int c = 0; c < cost.size(); c++)
            if (cost[r][c] == 0)
                if (is_covered(r, c, ticked_row, ticked_col) == 0) return false;
    return true;
}

vector<int> haungarian(vector<vector<int>>& cost) {
    while (true) {
        auto matches = max_match(cost);
        auto& r2c = matches.first;
        auto& c2r = matches.second;
        if (is_valid_match(r2c)) return r2c;

        vector<bool> ticked_row(cost.size(), false), ticked_col(cost.size(), false);
        for (int r = 0; r < cost.size(); r++)
            if (r2c[r] == -1) ticked_row[r] = true;

        while (true) {
            for (int r = 0; r < cost.size(); r++)
                if (ticked_row[r])
                    for (int c = 0; c < cost.size(); c++)
                        if (cost[r][c] == 0) {
                            ticked_col[c] = true;
                        }

            for (int c = 0; c < cost.size(); c++) {
                if (ticked_col[c]) {
                    int r = c2r[c];
                    if (r != -1) {
                        ticked_row[r] = true;
                    }
                }
            }
            if (is_all_zero_covered(cost, ticked_row, ticked_col)) break;
        }

        int min_val_uncovered = INFTY;
        for (int r = 0; r < cost.size(); r++) {
            for (int c = 0; c < cost.size(); c++) {
                if (is_covered(r, c, ticked_row, ticked_col) == 0) {
                    min_val_uncovered = min(min_val_uncovered, cost[r][c]);
                }
            }
        }

        for (int r = 0; r < cost.size(); r++) {
            for (int c = 0; c < cost.size(); c++)
                if (is_covered(r, c, ticked_row, ticked_col) == 2)
                    cost[r][c] += min_val_uncovered;
                else if (is_covered(r, c, ticked_row, ticked_col) == 0)
                    cost[r][c] -= min_val_uncovered;
        }
    }
}

int solve() {
    int n;
    cin >> n;
    auto cost = input_cost(n);
    auto reduced_cost = reduce(cost);
    auto res = haungarian(reduced_cost);
    int sum = 0;

    for (int i = 0; i < n; i++) sum += cost[i][res[i]];
    return sum;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) printf("Case %d: %d\n", i, solve());
    return 0;
}