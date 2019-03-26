// AC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define POO 1000001

struct node {
    struct node *prev, *next;
    int val, len;
};

/*
void  viewlist(struct node* tail) {
    return;
    struct node* n = tail;
    while (n) {
        printf("[%d]%d ", n->len, n->val);
        n = n->prev;
    }
    printf("\n");
}*/

void freeList(struct node* tail) {
    struct node* tmp;
    while (tail) {
        tmp = tail;
        tail = tail->prev;
        free(tmp);
    }
}

void update(struct node** head, struct node* const tail, const int j) {
    struct node* n = tail;
    while (n) {
        if (j < n->val) {
            n = n->prev;
            continue;
        }
        struct node* nx = n->next;
        // Should remove this node
        if (nx && nx->len == n->len + 1) {
            if (j < nx->val) nx->val = j;
            nx->prev = NULL;
            *head = nx;
            freeList(n);
        }
        // Should update this node
        else {
            n->val = j;
            n->len++;
            *head = n;
            freeList(n->prev);
            n->prev = NULL;
        }
        // viewlist(tail);
        return;
    }

    struct node* h = *head;
    if (h->len == 1) {
        // if (j > h->val) return;
        h->val = j;
        // viewlist(tail);
        return;
    }

    n = malloc(sizeof(struct node));
    n->len = 1;
    n->val = j;
    n->next = h;
    n->prev = NULL;
    h->prev = n;
    *head = n;
    // viewlist(tail);
}

int solve() {
    int n;
    scanf("%d", &n);
    if (n < 0) return -1;
    if (n == 0) return 0;

    int first;
    scanf("%d", &first);
    struct node *tail = malloc(sizeof(struct node)), *head = tail;
    tail->next = NULL;
    tail->prev = NULL;
    tail->val = first;
    tail->len = 1;

    int next;
    while (--n) {
        scanf("%d", &next);
        update(&head, tail, next);
        /*continue;
        printf("-> %d ", next);
        for (int i = 0; i < len; i++)
            printf(":%d", lenarr[i] == POO ? 0 : lenarr[i]);
        printf(": {%d} \n", len);*/
    }

    int tmp = tail->len;
    freeList(tail);
    return tmp;
}

int main() {
    int n;
    // FILE* f = fopen("./data.txt", "r");
    scanf("%d", &n);
    while (n--) {
        printf("%d\n", solve(stdin));
    }
}