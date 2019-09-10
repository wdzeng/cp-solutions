// AC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define poop unsigned long long
#define DIGIT 18
#define REGEX "%llu"
#define ZEGEX "%018llu"
#define COMP 999999999999999999ull
#define CUMP 1000000000000000000ull
#define atop convert
#define LINE_SIZE 100000000
#define ONE_SIZE 1000001
#define great(a, b) ((a) % (b)) ? ((a) / (b) + 1) : ((a) / (b));

struct number {
    int len;
    poop* val;
};

char line[LINE_SIZE];
struct number sum = {.val = NULL};
struct number added = {.val = NULL};

// Convert a line to a poop, then set the fisrt index of line to null
poop convert(char* line) {
    poop v = 0;
    for (int i = 0; line[i]; i++) {
        v = v * 10 + line[i] - '0';
    }
    line[0] = 0;  // Set tis digit to '\0'
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

// c = a + b where a > b
void add(struct number* numa, struct number* numb, struct number* numc) {
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

// Prints a number.
void printNumber(struct number* num) {
    // print first num
    int cur = num->len - 1;
    printf(REGEX, num->val[cur]);
    // print remaining
    while (cur--) printf(ZEGEX, num->val[cur]);
}

// a = a + b
void operate(struct number* a, struct number* b) {
    int cp = compare(a, b);
    if (cp <= 0)
        add(a, b, a);
    else
        add(b, a, a);
}

int task() {
    char* p = fgets(line, LINE_SIZE, stdin);
    if (!p) return 0;

    char* readed = strtok(line, " \r\n");
    createNumber(readed, &sum);
    readed = strtok(NULL, " \r\n");
    while (readed != NULL) {
        createNumber(readed, &added);
        operate(&sum, &added);
        readed = strtok(NULL, " \r\n");
    }

    printNumber(&sum);
    printf("\n");
    return 1;
}

int main() {
    while (task()) {
    }
    return 0;
}