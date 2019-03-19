// AC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define poop unsigned long long
#define DIGIT 9
#define REGEX "%llu"
#define ZEGEX "%09llu"
#define COMP 999999999ull
#define CUMP 1000000000ull
#define atop convert
#define LINE_SIZE 100000000
#define ONE_SIZE 1000001
#define great(a, b) ((a) % (b)) ? ((a) / (b) + 1) : ((a) / (b));

struct number {
    int len;
    poop* val;
};

// Convert a line to a poop, then set the fisrt index of line to null
poop convert(char* line) {
    poop v = 0;
    for (int i = 0; line[i]; i++) {
        v = v * 10 + line[i] - '0';
    }
    line[0] = 0;  // Set tis DIGIT10 to '\0'
    return v;
}

// Compare a and b. Returns -1 if a > b; 0 a == b; 1 a < b
int compare(struct number* a, struct number* b) {
    if (a->len == b->len) {
        int len = a->len;
        while (len--) {
            if (a->val[len] == b->val[len]) continue;
            return a->val[len] > b->val[len] ? -1 : 1;
        }
        return 0;
    }
    return a->len > b->len ? -1 : 1;
}

// Delete leading zeros
void clear(struct number* num) {
    int i;
    for (i = num->len - 1; i >= 0; i--) {
        if (num->val[i]) break;
    }
    // Now i is the first index of nonzero number

    if (i == -1) {
        // num = 0;
        if (num->len != 1) {
            num->val = (poop*)realloc(num->val, sizeof(poop));
            num->len = 1;
        }
        return;
    }
    int shortlen = i + 1;
    if (num->len != shortlen) {
        num->len = shortlen;
        num->val = (poop*)realloc(num->val, shortlen * sizeof(poop));
    }
}

// Converts string to positive number
void createNumber(char* string, struct number* dest) {
    int cursor = strlen(string);
    const int alen = great(cursor, DIGIT);
    poop* array = (poop*)malloc(alen * sizeof(poop));
    int index = 0;
    while ((cursor -= DIGIT) > 0) {
        array[index++] = atop(string + cursor);
    }
    array[index] = atop(string);
    free(dest->val);
    dest->val = array;
    dest->len = alen;
    clear(dest);
}

// Prints a number.
void printNumber(struct number* num) {
    // print first num
    int cur = num->len - 1;
    printf(REGEX, num->val[cur]);
    // print remaining
    while (cur--) printf(ZEGEX, num->val[cur]);
}

// Checks if a number is zero or one
int isZeroOrOne(struct number* num) {
    if (num->len == 1) {
        if (num->val[0] == 0) return 0;
        if (num->val[0] == 1) return 1;
    }
    return -1;
}

// Sets a number to zero
void reset(struct number* num) {
    if (num->len != 1) {
        num->val = (poop*)realloc(num->val, sizeof(poop));
        num->len = 1;
    }
    num->val[0] = 0;
}

void copyNumber(struct number* dest, struct number* src) {
    if (src == dest) return;
    size_t nbyte = src->len * sizeof(poop);
    dest->val = realloc(dest->val, nbyte);
    memcpy(dest->val, src->val, nbyte);
    dest->len = src->len;
}

// c = a + b where a >= b
void add(struct number* numa, struct number* numb, struct number* numc) {
    /*printf("Add ");
    printNumber(numa);
    printf(" and ");
    printNumber(numb);
    printf("\n");*/

    int judge = isZeroOrOne(numb);
    if (judge == 0) {
        copyNumber(numc, numa);
        return;
    }

    const int la = numa->len;
    const int lb = numb->len;
    poop* a = numa->val;
    poop* b = numb->val;
    poop* sum = (poop*)malloc((la + 1) * sizeof(poop));
    int carry = 0, index = 0;

    // From index 0 to lb
    for (; index < lb; index++) {
        sum[index] = a[index] + b[index] + carry;
        carry = sum[index] > COMP /*|| sum[index] < a[index]*/;
        if (carry) sum[index] -= CUMP;
    }

    // For the remainging
    for (; index < la; index++) {
        sum[index] = a[index] + carry;
        carry = sum[index] > COMP;
        if (carry) sum[index] -= CUMP;
    }

    // Last carry
    if (carry) {
        sum[la] = 1;
        numc->len = la + 1;
    }
    // 0
    else {
        // Release that leading zero
        sum = (poop*)realloc(sum, la * sizeof(poop));
        numc->len = la;
    }

    free(numc->val);
    numc->val = sum;
}

// a * b = c where a >= b
void multiply(struct number* numa, struct number* numb, struct number* numc) {
    /*printf("Mut ");
    printNumber(numa);
    printf(" and ");
    printNumber(numb);
    printf("\n");*/

    int judge = isZeroOrOne(numb);
    if (judge == 0) {
        reset(numc);
        return;
    }
    if (judge == 1) {
        copyNumber(numc, numa);
        return;
    }

    const int la = numa->len;
    const int lb = numb->len;
    const int ll = la + lb;
    poop* a = numa->val;
    poop* b = numb->val;
    poop* pd = calloc(ll, sizeof(poop));

    int i, j;
    for (j = 0; j < lb; j++) {
        for (i = 0; i < la; i++) {
            pd[i + j] += a[i] * b[j];
        }
    }

    int carry = 0;
    for (i = 0; i < ll; i++) {
        pd[i] += carry;
        carry = pd[i] / CUMP;
        // printf("At index %d get carry: %d\n", i, carry);
        pd[i] %= CUMP;
    }

    free(numc->val);
    numc->val = pd;
    numc->len = ll;
    clear(numc);
}

void operate(struct number* numa, struct number* numb, int isPlus) {
    int cp = compare(numa, numb);
    // a > b
    if (cp == -1) {
        if (isPlus)
            add(numa, numb, numa);
        else
            multiply(numa, numb, numa);
    }
    // a <= b
    else {
        if (isPlus)
            add(numb, numa, numa);
        else
            multiply(numb, numa, numa);
    }
}

int task() {
    static char line[10000001];
    static struct number sum = {.val = NULL};
    static struct number next = {.val = NULL};
    if (scanf("%s", line) == EOF) return 0;

    int prevplus, nextplus, hasnext;
    char* p = line;

    int nread = strspn(p, "1234567890");
    hasnext = 1;
    nextplus = p[nread] == '+';
    p[nread] = 0;
    //printf("Read: %s\n", p);
    createNumber(p, &sum);
    while (hasnext) {
        prevplus = nextplus;
        p += (nread + 1);
        nread = strspn(p, "1234567890");
        hasnext = p[nread];
        nextplus = p[nread] == '+';
        p[nread] = '\0';
        //printf("Read: %s\n", p);
        createNumber(p, &next);
        operate(&sum, &next, prevplus);
    }
    printNumber(&sum);
    return 1;
}

int main() {
    while (task()) {
        printf("\n");
    }
    return 0;
}