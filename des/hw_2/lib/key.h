#ifndef deskey
#define deskey
#include <stdint.h>
#include "./util.h"

namespace key {

// Generates a 56-bit key by given 64-bit key usgin Qc-1 table. The 56-bit key
// is prefixed with 8 zero.
uint64_t genKey56(uint64_t key64) {
    static int TABLE_PERMUTED_CHOICE_1[] = {
        57, 49, 41, 33, 25, 17, 9,  1,  58, 50, 42, 34, 26, 18,
        10, 2,  59, 51, 43, 35, 27, 19, 11, 3,  60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15, 7,  62, 54, 46, 38, 30, 22,
        14, 6,  61, 53, 45, 37, 29, 21, 13, 5,  28, 20, 12, 4};
    return shuf::shuffle(key64, 64, TABLE_PERMUTED_CHOICE_1, 56, false, false);
}

// Permutate a key by shift one or two position to left. The leftest bit is
// cycled to right.
uint32_t pmtKey28(uint32_t key28, bool one = true) {
    if (one) {
        uint32_t b = key28 >> 27;
        key28 = (key28 << 1) | b;
    }
    // Shift by two
    else {
        uint32_t b2 = key28 >> 26;
        key28 = (key28 << 2) | b2;
    }
    return key28 & 0x0FFFFFFF;
}

// Permuate a 28-but key to another 16 keys.
void pmtKey28(uint32_t key28, uint32_t dest[]) {
    static bool SHIFT_SCHD[] = {true,  true,  false, false, false, false,
                                false, false, true,  false, false, false,
                                false, false, false, true};

    uint32_t src;
    bool one;
    for (int i = 0; i < 16; i++) {
        src = i ? dest[i - 1] : key28;
        one = SHIFT_SCHD[i];
        dest[i] = pmtKey28(src, one);
    }
}

// Permutate a 56-bit key to 16 C-Keys and 16 D-Keys. Each of C/D-Key is
// 28-bit so the first 4 bits is filled with '0'.
void pmtKey56(uint64_t key56, uint32_t c[], uint32_t d[]) {
    uint32_t dkey = key56 & 0x0FFFFFFFull;
    uint32_t ckey = key56 >> 28;
    pmtKey28(ckey, c);
    pmtKey28(dkey, d);
}

// Permutate a 56-bit key to another 16 48-bit keys. Each of 48-bit keys is
// prefixed with 16 zero.
void genKey48s(uint64_t key56, uint64_t key48[]) {
    static int TABLE_PERMUTED_CHOICE_2[] = {
        14, 17, 11, 24, 1,  5,  3,  28, 15, 6,  21, 10, 23, 19, 12, 4,
        26, 8,  16, 7,  27, 20, 13, 2,  41, 52, 31, 37, 47, 55, 30, 40,
        51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

    uint32_t c[16], d[16];
    pmtKey56(key56, c, d);
    uint64_t cd;
    for (int n = 0; n < 16; n++) {
        cd = c[n];
        cd = (cd << 28) | d[n];
        key48[n] =
            shuf::shuffle(cd, 56, TABLE_PERMUTED_CHOICE_2, 48, false, false);
    }
}

}  // namespace key

#endif