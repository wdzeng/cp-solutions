#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#define MAX_LEN 1000
using namespace std;

int history[MAX_LEN][MAX_LEN];
int ins, del, mod;

int ed(const char* strA, const char* strB, int lenA, int lenB) {
    if (lenA == 0) return ins * lenB;
    if (lenB == 0) return del * lenA;
    if (history[lenA - 1][lenB - 1] != -1) return history[lenA - 1][lenB - 1];

    // If last characters are same, ignore them.
    if (strA[lenA - 1] == strB[lenB - 1]) {
        int cost = ed(strA, strB, lenA - 1, lenB - 1);
        history[lenA - 1][lenB - 1] = cost;
        return cost;
    }

    int ins_cost = ins + ed(strA, strB, lenA, lenB - 1);
    int del_cost = del + ed(strA, strB, lenA - 1, lenB);
    int min_cost = min(ins_cost, del_cost);
    if (mod < ins + del) {
        int rep_cost = mod + ed(strA, strB, lenA - 1, lenB - 1);
        min_cost = min(min_cost, rep_cost);
    }
    history[lenA - 1][lenB - 1] = min_cost;
    return min_cost;
}

int solve() {
    int lenA, lenB;
    cin >> lenB >> lenA >> ins >> del >> mod;
    char strA[lenA + 1], strB[lenB + 1];
    cin >> strB >> strA;
    memset(history, -1, sizeof(history));
    return ed(strA, strB, lenA, lenB);
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}