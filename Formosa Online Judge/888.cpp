#include <iostream>
#include <cstring>
using namespace std;
#define foul "endro~!\n"

// AC, but somehow slow

int log2(int n) {
    n -= 1;
    int ret = 1;
    while (n >>= 1) ret++;
    // cout << "ret: " << ret << "\n";
    return ret;
}

int pow2(int e) {
    int ret = 1;
    while (e--) ret <<= 1;
    return ret;
}

int* tree = NULL;
int offset = 0;
int tree_size = 0;

void view() {
    cout << ">> ";
    for (int i = 1; i < tree_size; i++) printf("%2d ", tree[i]);
    cout << endl;
}

void inc(int k, int val = 1) {
    if (val == 0) return;
    int index = k + offset;
    while (index) {
        tree[index] += val;
        index >>= 1;
    }
}

void reset(int k) {
    int dec = 1 - tree[k + offset];
    inc(k, dec);
}

void query_and_dec(int k) {
    if (k > tree[1]) {
        cout << foul;
        return;
    }
    int index = 1;
    while (index <= offset) {
        tree[index]--;
        int left = tree[index << 1];
        if (k > left) {
            k -= left;
            index = (index << 1) | 1;
        } else {
            index <<= 1;
        }
    }
    /*if (tree[index] == 1) {
        cout << foul;
        return;
    }*/
    tree[index]--;
    // inc(index - offset, -1);
    cout << index - offset << "\n";
}

void buildTree(int n) {
    tree_size = pow2(log2(n) + 1);
    tree = new int[tree_size];
    memset(tree, 0, sizeof(int) * tree_size);
    offset = (tree_size >> 1) - 1;
    for (int i = 1; i <= n; i++) inc(i);
}

void solve() {
    int n, q;
    cin >> n >> q;
    buildTree(n);
    // view();

    int o1, o2;
    while (q--) {
        cin >> o1 >> o2;
        if (o1 == 1)
            inc(o2);
        else if (o1 == 2)
            reset(o2);
        else
            query_and_dec(o2);
    //    view();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (tree != NULL) delete[] tree;
        solve();
    }
}