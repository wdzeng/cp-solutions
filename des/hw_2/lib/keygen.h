#include "./util.h"

namespace nmkeygen {

using namespace nmcryutil;

// Generates a 56-bit key by given 64-bit key usgin Qc-1 table. The 56-bit key
// is prefixed with 8 zero.
lung genKey56(lung key64) {
    static int TABLE_PERMUTED_CHOICE_1[] = {
        57, 49, 41, 33, 25, 17, 9,  1,  58, 50, 42, 34, 26, 18,
        10, 2,  59, 51, 43, 35, 27, 19, 11, 3,  60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15, 7,  62, 54, 46, 38, 30, 22,
        14, 6,  61, 53, 45, 37, 29, 21, 13, 5,  28, 20, 12, 4};

    lung key56 = 0;
    for (int i = 0; i < 56; i++) {
        key56 = (key56 | bitAt(key64, TABLE_PERMUTED_CHOICE_1[i], false, false))
                << 1;
    }
    return key56 >> 1;  // Move back
}

// Permutate a key by shift one or two position to left. The leftest bit is
// cycled to right.
int pmtKey28(int key28, int n) {
    for (int i = 0; i < n; i++) {
        key28 <<= 1;
        key28 |= bitAt(key28, 28);
        key28 &= 0x0FFFFFFF;
    }
    return key28;
}

// Permuate a 28-but key to another 16 keys.
void pmtKey28(int key28, int dest[]) {
    static int SHIFT_SCHD[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    int src, shift, k;
    for (int i = 0; i < 16; i++) {
        src = i ? dest[i - 1] : key28;
        shift = SHIFT_SCHD[i];
        dest[i] = pmtKey28(src, shift);
    }
}

// Permutate a 56-bit key to 16 C-Keys and 16 D-Keys. Each of C/D-Key is
// 28-bit so the first 4 bits is filled with '0'.
void pmtKey56(lung key56, int c[], int d[]) {
    int dkey = key56 & 0x0FFFFFFF;
    int ckey = key56 >> 28;
    pmtKey28(ckey, c);
    pmtKey28(dkey, d);
}

// Permutate a 56-bit key to another 16 48-bit keys. Each of 48-bit keys is
// prefixed with 16 zero.
void genKey48s(lung key56, lung key48[]) {
    static int TABLE_PERMUTED_CHOICE_2[] = {
        14, 17, 11, 24, 1,  5,  3,  28, 15, 6,  21, 10, 23, 19, 12, 4,
        26, 8,  16, 7,  27, 20, 13, 2,  41, 52, 31, 37, 47, 55, 30, 40,
        51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

    int c[16], d[16];
    pmtKey56(key56, c, d);
    lung cd;
    for (int n = 0; n < 16; n++) {
        cd = ((lung)c[n] << 28) | d[n];
        key48[n] = shuffle(cd, 56, TABLE_PERMUTED_CHOICE_2, 48, false, false);
    }
}

}  // namespace nmkeygen

// Generates 16 subkeys by given 64-biy key. Each subkey is 48-bit prefixed
// with 8 zeros. The 64-bit key is first permutated to another 56-bit key, then
// multuple tasks are processed to generate such subkeys.
void createSubKeys(lung seed, lung keys[]) {
    seed = nmkeygen::genKey56(seed);
    nmkeygen::genKey48s(seed, keys);
}