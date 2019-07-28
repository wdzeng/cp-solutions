#include <stdio.h>
#include <stdlib.h>

// AC
char next[10000001];

struct node {
    struct node *one, *zero;
    int count;
};

struct node* createNode(struct node* parent, int theone) {
    struct node* n = malloc(sizeof(struct node));
    n->one = NULL;
    n->zero = NULL;
    n->count = 0;
    if (theone)
        parent->one = n;
    else
        parent->zero = n;
    return n;
}

void inc(char* addr, struct node* root) {
    for (int i = 0; addr[i]; i++) {
        root->count++;
        if (addr[i] == '1') {
            root = root->one ? root->one : createNode(root, 1);
        }  //
        else {
            root = root->zero ? root->zero : createNode(root, 0);
        }
    }
    root->count++;
}

int get(char* addr, struct node* root) {
    for (int i = 0; addr[i] && root; i++) {
        root = addr[i] == '1' ? root->one : root->zero;
    }
    return root ? root->count : 0;
}

void solve(int n, struct node* root) {
    while (n--) {
        // printf("[%d]: ", n);
        scanf("%s", next);
        printf("%d\n", get(next, root));
    }
}

struct node* prepare(int n) {
    struct node* root = malloc(sizeof(struct node));
    root->one = NULL;
    root->zero = NULL;
    root->count = 0;

    while (n--) {
        // printf("[%d]: ", n);
        scanf("%s", next);
        inc(next, root);
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    struct node* root = prepare(n);
    scanf("%d", &n);
    solve(n, root);
    return 0;
}