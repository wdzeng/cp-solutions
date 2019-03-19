#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "./des.h"

int main() {
    uint64_t plain = 0x5365637572697479;
    uint64_t cipher = 0x9ba99ba3540353bb;

    clock_t start = clock();
    for (uint64_t key = 0xFFFF; key >= 0x0; key--) {
        if (des::encode(plain, key) == cipher) {
            printf("%016lX\n", key);
            break;
        }
    }
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("%.3f ms\n", time);
}