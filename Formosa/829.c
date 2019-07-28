#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZ 100000

// AC

struct letter {
    struct letter* next[26];
    struct record* loc;
};

struct record {
    char* word;
    int count;
    struct record* next;
};

struct letter* createLetter() {
    struct letter* n = (struct letter*)calloc(1, sizeof(struct letter));
    return n;
}

struct record* createRecord() {
    struct record* r = (struct record*)calloc(1, sizeof(struct record));
    return r;
}

int valid(char c) { return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z'; }

char low(char c) {
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 'a';
    else
        return c;
}

/*
void doline(const char* line, struct letter* root, struct record** rec) {
    int started = 0;
    // printf("Get line: %s\n", line);
    struct letter *node = root, *nxt;
    for (int i = 0; ; i++) {
        if (!valid(line[i])) {
            if (i == started) {
                if (line[i] == 0) return;
                started++;
                continue;
            }
            struct record* loc = node->loc;
            if (loc == NULL) {
                loc = createRecord();
                (*rec)->next = loc;
                *rec = loc;
                node->loc = loc;
                int len = i - started;
                loc->word = malloc(len + 1);
                for (int i = 0; i < len; i++)
                    loc->word[i] = low(line[started + i]);
                loc->word[len] = 0;
            }
            loc->count++;
            // printf("# Update %s\n", loc->word);
            started = i + 1;
            node = root;

            if (line[i] == 0) return;
            continue;
        }
        int idx = low(line[i]) - 'a';
        nxt = node->next[idx];
        if (nxt == NULL) {
            nxt = createLetter();
            node->next[idx] = nxt;
        }
        node = nxt;
    }
}*/

void doline(char* string, struct letter* root, struct record** last) {
    static char buffer[BUF_SIZ];
    struct letter *n = root, *nxt;
    int cur = 0;

    for (int i = 0; string[i]; i++) {
        if (!valid(string[i])) continue;
        char l = low(string[i]);
        int idx = l - 'a';
        nxt = n->next[idx];
        if (nxt == NULL) {
            nxt = createLetter();
            n->next[idx] = nxt;
        }
        n = nxt;
        buffer[cur++] = l;
    }

    if (cur == 0) return;

    buffer[cur] = 0;
    struct record* rec = n->loc;
    if (rec == NULL) {
        rec = createRecord();
        rec->word = (char*)malloc(cur + 1);
        strcpy(rec->word, buffer);
        (*last)->next = rec;
        *last = rec;
        n->loc = rec;
    }
    rec->count++;
}

int main() {
    static char readed[BUF_SIZ];
    struct letter* root = createLetter();
    struct record* rec = createRecord();
    struct record* last = rec;
    while (scanf("%s", readed) != EOF) {
        doline(readed, root, &last);
    }
    rec = rec->next;
    while (rec) {
        printf("%s %d\n", rec->word, rec->count);
        rec = rec->next;
    }
    return 0;
}