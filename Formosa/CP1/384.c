// AC

#include <stdio.h>
#define  max(a, b) (a)>(b)?(a):(b)

int main() {
    int n;
    scanf("%d", &n);
    // We have to ensure the length of {b} is at lease one.
    // If all {a} are negatives, pick the biggest one.
    int hasrecord = 0;
    int maxsum = -99999;  // Set to a very small number to guarentee if all {a}
                          // are negative the max num is correctly record.
    int currsum = 0;
    int next;
    while(n--) { // Cleaner code!!
        scanf("%d", &next);
        if (next >= 0) {
            hasrecord = 1;
            currsum += next;
            continue;
        }
        // If no any positive numbers appears, check if this number is greatest
        // negative number.
        if (!hasrecord) {
            maxsum = max(next, maxsum);
            continue;
        }
        // Record this sum if needed
        maxsum = max(currsum, maxsum);
        // This negative number is too negative
        if (-next >= currsum) {
            currsum = 0;
            continue;
        }
        // This negative number is tolerable
        else {
            currsum += next;
        }
    }
    if (hasrecord) {
        maxsum = max(currsum, maxsum);
    }
    printf("%d\n", maxsum);
}