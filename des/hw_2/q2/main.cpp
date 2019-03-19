#include <stdint.h>
#include <stdio.h>
#include "./des.h"

int main() {
    uint64_t plain = 0x5365637572697479;
    uint64_t   key = 0xa30000f500ce0098;
    printf("%016lX\n", des::encode(plain, key));

    uint64_t cipher = 0x0;
               key = 0x0F0F0F0F0F0F0F0F;
    printf("%016lX\n", des::decode(cipher, key));
}