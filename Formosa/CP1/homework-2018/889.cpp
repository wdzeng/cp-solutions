#include <algorithm>
#include <iostream>

// AC but slow

using namespace std;

int *tree = NULL;
int tsize;
int offset;
int n;

void view() {
    for (int i = 1; i <= offset + n; i++) cout << tree[i] << " ";
}

int qgcd(int h, int l) {
    while (l) {
        int r = h % l;
        h = l;
        l = r;
    }
    return h;
}

int gcd(int a, int b) {
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;
    return qgcd(max(a, b), min(a, b));
}

int ciellog2(int n) {
    n--;
    int ret = 1;
    while (n >>= 1) ret++;
    return ret;
}

int pow2(int e) {
    int ret = 1;
    while (e--) ret <<= 1;
    return ret;
}

int validate(const int index) {
    if (index <= offset)
        tree[index] = gcd(validate(index * 2), validate(index * 2 + 1));
    return tree[index];
}

void task1(int i, int v) {
    int index = offset + i;
    tree[index] = v;
    while (index >>= 1) {
        tree[index] = gcd(tree[index * 2], tree[index * 2 + 1]);
    }
}

int query(int left, int right, int index = 1, int leftc = 1,
          int rightc = tsize - offset - 1) {
    if (leftc >= left && rightc <= right) return tree[index];
    if (leftc > right || rightc < left) return 0;
    int mid = (leftc + rightc) / 2;
    return gcd(query(left, right, index * 2, leftc, mid),
               query(left, right, index * 2 + 1, mid + 1, rightc));
}

void task2(const int from, const int lim) {
    int left = from;
    int right = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        int guess = query(from, mid);
        if (guess <= lim)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (left > n)
        cout << "DOYA!\n";
    else
        cout << left << "\n";
}

void solve() {
    int q;
    cin >> n >> q;
    tsize = pow2(ciellog2(n) + 1);
    offset = tsize / 2 - 1;
    if (tree != NULL) delete[] tree;
    tree = new int[tsize];
    for (int i = 1; i <= n; i++) tree[offset + i] = 1;
    validate(1);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            task1(b, c);
        else
            task2(b, c);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}