#include <string.h>
#include <cstdlib>
#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

// AC

int* gids;
bool* hasGroup;

std::unordered_set<int> iset;
std::vector<std::list<int>*>* qs;
std::list<std::list<int>*> tasks;

int e2() {
    if (tasks.empty()) return -1;

    std::list<int>* queue = tasks.front();
    const int id = queue->front();
    iset.erase(id);
    queue->pop_front();
    if (queue->empty()) {
        hasGroup[gids[id]] = false;
        tasks.pop_front();
    }
    return id;
}

bool e1(int id) {
    if (iset.count(id)) return false;

    iset.insert(id);
    int gid = gids[id];
    std::list<int>* queue = (*qs)[gid];
    queue->push_front(id);
    if (hasGroup[gid]) return true;

    hasGroup[gid] = true;
    tasks.push_back(queue);
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    gids = (int*)malloc(n * sizeof(int));
    hasGroup = (bool*)calloc(n, sizeof(bool));
    qs = new std::vector<std::list<int>*>(n);

    for (int i = 0; i < n; i++) {
        (*qs)[i] = new std::list<int>();
    }

    int e, x;
    scanf("%d", &e);

    int min = 10000001;
    for (int i = 0; i < n; i++) {
        int gid;
        scanf("%d", &gid);
        min = gid < min ? gid : min;
        gids[i] = gid;
    }
    min *= -1;
    for (int i = 0; i < n; i++) gids[i] += min;

    while (e--) {
        scanf("%d", &x);
        if (x == 1) {
            int id;
            scanf("%d", &id);
            if (e1(id - 1))
                printf("Successful\n");
            else
                printf("Ignore\n");
        } else {
            printf("%d\n", e2() + 1);
        }
    }
}