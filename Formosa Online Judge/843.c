#include <stdio.h>
#include <stdlib.h>
#define mmm(a, b) (long)(a) * (b)
#define node struct node

// AC

node {
    node *prev, *next;
    int x, y;
};

node *first = NULL, *last = NULL;

void see() {
    node *n = first;
    while (n) {
        printf("(%d, %d) ", n->x, n->y);
        n = n->next;
    }
    printf("\n");
}

void printNode(const node *n, int nl) {
    if (n == NULL)
        printf("NULL");
    else
        printf("(%d, %d)", n->x, n->y);

    if (nl) printf("\n");
}

node *buildNode(int x, int y, node *theprev, node *thenext) {
    node *n = malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->prev = theprev;
    n->next = thenext;
    if (theprev)
        theprev->next = n;
    else
        first = n;
    if (thenext)
        thenext->prev = n;
    else
        last = n;
    return n;
}

void removeNode(node *n) {
    node *n1 = n->next;
    node *n0 = n->prev;
    if (n1)
        n1->prev = n0;
    else
        last = n0;
    if (n0)
        n0->next = n1;
    else
        first = n1;
    free(n);
}

long firstBite(const int x, const int y) {
    buildNode(x, y, NULL, NULL);
    return mmm(x, y);
}

long loop(const int x, const int y) {
    long eaten = 0;
    int px = 0;
    node *n = first;
    while (n) {
        // nx < x
        if (n->x < x) {
            if (n->y <= y) {
                long e =  mmm(n->x - px, y - n->y);
                eaten += e;
                // printf("+++ %ld\n", e);
                px = n->x;

                node *removed = n;
                n = n->next;
                removeNode(removed);
            } else {
                px = n->x;
                n = n->next;
            }
            continue;
        }
        // nx >= x
        else {
            if (n->y >= y) return 0;
            eaten += mmm(x - px, y - n->y);
            if (n->x > x)
                buildNode(x, y, n->prev, n);
            else  // nx == x
                n->y = y;
            return eaten;
        }
    }

    // at here maybe the list is empty
    if (last == NULL) {
        // printf("haha\n");
        eaten += mmm(x - px, y);
        buildNode(x, y, NULL, NULL);
    } 
    else {
        eaten += mmm(x - px, y);
        if (last->y <= y) {
            last->x = x;
            last->y = y;
        }
        else {
            buildNode(x, y, last, NULL);
        }
    }

    return eaten;
}

long biteAt(int x, int y) {
    if (first == NULL) return firstBite(x, y);
    int mid = (last->x + first->x) / 2;
    // if (x > mid) {
    //    printf("Back loop: ");
    //    node *inserted = backloop(x, y);
    //    return inserted ? traceToFront(inserted) : 0;
    //} else {
    //    printf("Front loop: ");
    return loop(x, y);
    //}
}

int main() {
    int width, height, t;
    long area;
    scanf("%d %d %d", &width, &height, &t);
    area = mmm(width, height);

    int x, y;
    while (t--) {
        scanf("%d %d", &x, &y);
        long bitten = biteAt(x, y);
        if (bitten)
            printf("%ld\n", bitten);
        else
            printf("QAQ\n");
        area -= bitten;
        // see();
    }
    printf("%ld\n", area);
}