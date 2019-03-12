typedef unsigned long lung;
typedef unsigned int uui;

namespace nmcryutil {

// Gets the bit at a specific position. Returns either 0 or 1. If right is set
// to true, the index is count from right to left. That is, the 63th bit matches
// index=0. If zero is set to first, the first index is 0 or otherwise 1.
int bitAt(lung val, int index, bool right = true, bool zero = true);

// Gets the bit at a specific position. Returns either 0 or 1. If right is set
// to true, the index is count from right to left. That is, the 31th bit matches
// index=0. If zero is set to first, the first index is 0 or otherwise 1.
int bitAt(uui val, int index, bool right = true, bool zero = true);

// Sets and returns the bit at a specific position. If right is set to true, the
// index is count from right to left. That is, the 63th bit matches index=0. If
// zero is set to first, the first index is 0 or otherwise 1.
lung bit(lung src, int index, int val, bool right = true, bool zero = true);

// Sets and returns the bit at a specific position. If right is set to true, the
// index is count from right to left. That is, the 31th bit matches index=0. If
// zero is set to first, the first index is 0 or otherwise 1.
int bit(uui src, int index, int val, bool right = true, bool zero = true);

// Permutation by a table.
lung shuffle(lung src, int table[], int len);

int bitAt(lung val, int index, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 63 - index;
    }
    return (val >> index) & 1l;
}

int bitAt(uui val, int index, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 31 - index;
    }
    return (val >> index) & 1;
}

lung bit(lung src, int index, int val, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 63 - index;
    }
    // set to 1
    if (val) {
        return src | (1l << index);
    }
    // set to 0
    else {
        return src & ~(1l << index);
    }
}

int bit(uui src, int index, int val, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 31 - index;
    }
    // set to 1
    if (val) {
        return src | (1 << index);
    }
    // set to 0
    else {
        return src & ~(1 << index);
    }
}

lung shuffle(lung src, int srclen, int table[], int tblen, bool right = true,
             bool zero = true) {
    int tbshift = right ? 0 : (64 - tblen);
    int srcshift = right ? 0 : (64 - srclen);
    int index, b;
    lung res = 0;
    for (int i = 0; i < tblen; i++) {
        index = table[i];
        b = bitAt(src, index + srcshift, right, zero);
        res = bit(res, i + tbshift, b, right, true);
    }
    return res;
}

}  // namespace nmcryutil

namespace nmsboxes {

// Gets the value in s boxes by box index, row and column. Note that the
// first s bos has index 1.
int s(int index, int row, int col) {
    // S_BOXES[index][row * 16 + col]
    static int S_BOXES[512] = {
        14, 4,  13, 1,  2,  15, 11, 8,  3,  10, 6,  12, 5,  9,  0,  7,  0,  15,
        7,  4,  14, 2,  13, 1,  10, 6,  12, 11, 9,  5,  3,  8,  4,  1,  14, 8,
        13, 6,  2,  11, 15, 12, 9,  7,  3,  10, 5,  0,  15, 12, 8,  2,  4,  9,
        1,  7,  5,  11, 3,  14, 10, 0,  6,  13, 15, 1,  8,  14, 6,  11, 3,  4,
        9,  7,  2,  13, 12, 0,  5,  10, 3,  13, 4,  7,  15, 2,  8,  14, 12, 0,
        1,  10, 6,  9,  11, 5,  0,  14, 7,  11, 10, 4,  13, 1,  5,  8,  12, 6,
        9,  3,  2,  15, 13, 8,  10, 1,  3,  15, 4,  2,  11, 6,  7,  12, 0,  5,
        14, 9,  10, 0,  9,  14, 6,  3,  15, 5,  1,  13, 12, 7,  11, 4,  2,  8,
        13, 7,  0,  9,  3,  4,  6,  10, 2,  8,  5,  14, 12, 11, 15, 1,  13, 6,
        4,  9,  8,  15, 3,  0,  11, 1,  2,  12, 5,  10, 14, 7,  1,  10, 13, 0,
        6,  9,  8,  7,  4,  15, 14, 3,  11, 5,  2,  12, 7,  13, 14, 3,  0,  6,
        9,  10, 1,  2,  8,  5,  11, 12, 4,  15, 13, 8,  11, 5,  6,  15, 0,  3,
        4,  7,  2,  12, 1,  10, 14, 9,  10, 6,  9,  0,  12, 11, 7,  13, 15, 1,
        3,  14, 5,  2,  8,  4,  3,  15, 0,  6,  10, 1,  13, 8,  9,  4,  5,  11,
        12, 7,  2,  14, 2,  12, 4,  1,  7,  10, 11, 6,  8,  5,  3,  15, 13, 0,
        14, 9,  14, 11, 2,  12, 4,  7,  13, 1,  5,  0,  15, 10, 3,  9,  8,  6,
        4,  2,  1,  11, 10, 13, 7,  8,  15, 9,  12, 5,  6,  3,  0,  14, 11, 8,
        12, 7,  1,  14, 2,  13, 6,  15, 0,  9,  10, 4,  5,  3,  12, 1,  10, 15,
        9,  2,  6,  8,  0,  13, 3,  4,  14, 7,  5,  11, 10, 15, 4,  2,  7,  12,
        9,  5,  6,  1,  13, 14, 0,  11, 3,  8,  9,  14, 15, 5,  2,  8,  12, 3,
        7,  0,  4,  10, 1,  13, 11, 6,  4,  3,  2,  12, 9,  5,  15, 10, 11, 14,
        1,  7,  6,  0,  8,  13, 4,  11, 2,  14, 15, 0,  8,  13, 3,  12, 9,  7,
        5,  10, 6,  1,  13, 0,  11, 7,  4,  9,  1,  10, 14, 3,  5,  12, 2,  15,
        8,  6,  1,  4,  11, 13, 12, 3,  7,  14, 10, 15, 6,  8,  0,  5,  9,  2,
        6,  11, 13, 8,  1,  4,  10, 7,  9,  5,  0,  15, 14, 2,  3,  12, 13, 2,
        8,  4,  6,  15, 11, 1,  10, 9,  3,  14, 5,  0,  12, 7,  1,  15, 13, 8,
        10, 3,  7,  4,  12, 5,  6,  11, 0,  14, 9,  2,  7,  11, 4,  1,  9,  12,
        14, 2,  0,  6,  10, 13, 15, 3,  5,  8,  2,  1,  14, 7,  4,  10, 8,  13,
        15, 12, 9,  0,  3,  5,  6,  11};
    return S_BOXES[(--index << 6) | (row << 4) | col];
}

// Gets the value in s boxes by a given 6-bit key.
int s(int index, uui key6) {
    int row = (key6 & 0b100000) >> 4 | (key6 & 1);
    int col = (key6 & 0b011110) >> 1;
    return s(index, row, col);
}
}  // namespace nmsboxes

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
    return shuffle(key64, 64, TABLE_PERMUTED_CHOICE_1, 56, false, false);
}

// Permutate a key by shift one or two position to left. The leftest bit is
// cycled to right.
uui pmtKey28(uui key28, bool one = true) {
    if (one) {
        uui b = key28 >> 27;
        key28 = (key28 << 1) | b;
    }
    // Shift by two
    else {
        uui b2 = key28 >> 26;
        key28 = (key28 << 2) | b2;
    }
    return key28 & 0x0FFFFFFF;
}

// Permuate a 28-but key to another 16 keys.
void pmtKey28(uui key28, uui dest[]) {
    static bool SHIFT_SCHD[] = {true,  true,  false, false, false, false,
                               false, false, true,  false, false, false,
                               false, false, false, true};

    uui src;
    bool one;
    for (int i = 0; i < 16; i++) {
        src = i ? dest[i - 1] : key28;
        one = SHIFT_SCHD[i];
        dest[i] = pmtKey28(src, one);
    }
}

// Permutate a 56-bit key to 16 C-Keys and 16 D-Keys. Each of C/D-Key is
// 28-bit so the first 4 bits is filled with '0'.
void pmtKey56(lung key56, uui c[], uui d[]) {
    uui dkey = key56 & 0x0FFFFFFFul;
    uui ckey = key56 >> 28;
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

    uui c[16], d[16];
    pmtKey56(key56, c, d);
    lung cd;
    for (int n = 0; n < 16; n++) {
        cd = c[n];
        cd = (cd << 28) | d[n];
        key48[n] = shuffle(cd, 56, TABLE_PERMUTED_CHOICE_2, 48, false, false);
    }
}

}  // namespace nmkeygen

namespace nmdblock {

using namespace nmcryutil;
using namespace nmsboxes;

// Performs a single permutation of data.
void encrypt(uui* left, uui* right, lung key);

// Performs 16 permutation processes to data and a reverse. Then applys the
// final permutation. Returns the permutated 64-bit value.
lung encrypt(lung ip, lung keys[], bool reverse = false);

// Query the value in s boxes.
uui squery(lung e);

// A permutation about DES.
uui f(uui key32, lung key48);

// Concantates two 32-bit keys to a 64-bit key.
lung concat3264(uui left, uui right) { return (lung)left << 32 | right; }

// Split a 64-bit key into two 32-bit keys.
void split6432(lung seq, uui* left, uui* right) {
    *left = seq >> 32;
    *right = seq & 0xFFFFFFFFul;
}

// Performs the inital permutation.
lung genIp(lung msg) {
    static int TABLE_INITIAL_PERMUTATION[] = {
        58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
    return shuffle(msg, 64, TABLE_INITIAL_PERMUTATION, 64, false, false);
}

// Performs the final permutation.
lung genFp(lung msg) {
    static int TABLE_FINAL_PERMUTATION[] = {
        40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9,  49, 17, 57, 25};
    return shuffle(msg, 64, TABLE_FINAL_PERMUTATION, 64, false, false);
}

// Switches the ip-converted msg for 16 times.
lung encrypt(lung ip, lung keys[], bool reverse) {
    uui left, right;
    split6432(ip, &left, &right);
    // Encoding
    if (!reverse) {
        for (int i = 0; i < 16; i++) encrypt(&left, &right, keys[i]);
    }
    // Decoding
    else {
        for (int i = 15; i >= 0; i--) encrypt(&left, &right, keys[i]);
    }
    // Swap
    return concat3264(right, left);
}

void encrypt(uui* left, uui* right, lung key) {
    uui right0 = *right;
    *right = *left ^ f(*right, key);
    *left = right0;
}

uui squery(lung e) {
    uui key6;
    uui sb[8];
    for (int i = 7; i >= 0; i--) {
        key6 = e & 0b111111u;
        sb[i] = s(i + 1, key6);  // index 0 matches the box 1
        e >>= 6;
    }
    uui res = 0;
    for (int i = 0; i < 8; i++) {
        res |= sb[i];
        if (i < 7) res <<= 4;
    }
    return res;
}

uui f(uui key32, lung key48) {
    static int TABLE_E_BIT_SELECTION[] = {
        32, 1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,  8,  9,  10, 11,
        12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21,
        22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
    static int TABLE_P[] = {16, 7, 20, 21, 29, 12, 28, 17, 1,  15, 23,
                            26, 5, 18, 31, 10, 2,  8,  24, 14, 32, 27,
                            3,  9, 19, 13, 30, 6,  22, 11, 4,  25};

    lung e = shuffle(key32, 32, TABLE_E_BIT_SELECTION, 48, false, false);
    uui spmt = squery(e ^ key48);
    return shuffle(spmt, 32, TABLE_P, 32, false, false);
}

}  // namespace nmdblock

// Generates 16 subkeys by given 64-biy key. Each subkey is 48-bit prefixed
// with 8 zeros. The 64-bit key is first permutated to another 56-bit key, then
// multuple tasks are processed to generate such subkeys.
void createSubkeys(lung seed, lung keys[]) {
    seed = nmkeygen::genKey56(seed);
    nmkeygen::genKey48s(seed, keys);
}

// Encodes a 64-bit message with 16 48-but subkeys.
lung encode(lung msg, lung key48s[]) {
    lung res = nmdblock::genIp(msg);
    res = nmdblock::encrypt(res, key48s, false);
    return nmdblock::genFp(res);
}

// Decodes a 64-bit message with 16 48-but subkeys.
lung decode(lung msg, lung key48s[]) {
    lung res = nmdblock::genIp(msg);
    res = nmdblock::encrypt(res, key48s, true);
    return nmdblock::genFp(res);
}

// Encodes a 64-bit message
lung encode(lung msg, lung key64) {
    lung subkeys[16];
    createSubkeys(key64, subkeys);
    return encode(msg, subkeys);
}

lung decode(lung msg, lung key64) {
    lung subkeys[16];
    createSubkeys(key64, subkeys);
    return decode(msg, subkeys);
}

// Author: 0716023 Wen-Ting Zeng
#include <time.h>
#include <iostream>
using namespace std;
using namespace nmcryutil;

int main() {
    lung ekeys[] = {0xda3014b0715059e6ul, 0x453b067193a45dd6ul,
                    0x6d5b8932b745264eul, 0x89ef992ca9f3dbbful,
                    0x7f466ddd525c32c7ul, 0x95b330236137670dul,
                    0x6ea9f9e827f8a414ul, 0x3310a8cac239c4e8ul,
                    0x0f4bdbf17d4975f5ul, 0xe1a02d8b76738deeul};
    lung plaintexts[] = {0xbe480047cce655dbul, 0xc991fcb1c2ca8d56ul,
                         0xe5e2adf3e3accebdul, 0x557e28cf53b12a71ul,
                         0xbf36fa881cd554d8ul, 0xfc8bcee076acd78aul,
                         0x2f41770c4841039cul, 0x18c09faaefd5fb85ul,
                         0xaadd02913d90abd5ul, 0xdad35f07c350f584ul};
    lung dkeys[] = {0xc71b0946f8308fa5ul, 0x1e8951c1253c2837ul,
                    0x9b18bbfc748fa55eul, 0xf4ef880bbbd5fa36ul,
                    0xa647883ddb55a783ul, 0x71045a9a2381da5dul,
                    0x07f437adf583e839ul, 0xffa08459aabce49dul,
                    0x0ff2ef31b23c32fful, 0x7a08ea6100b83807ul};
    lung ciphertexts[] = {0x37ca5f03bbdb5668ul, 0x1ad9299839efc771ul,
                          0x79e6db8d6c4f725ful, 0xe45d6ef5999a2329ul,
                          0xd0d1226520263b9ful, 0x0cfb7d18bf8f4cf3ul,
                          0xcbbffe5f7bdc33cful, 0xadbef68debd8b7a6ul,
                          0xb918355be8203c81ul, 0x769b1ab38193c72cul};

    lung res;
    // Encrpytion
    for (int i = 0; i < 10; i++) {
        res = encode(plaintexts[i], ekeys[i]);
        printf("%016lX\n", res);
    }

    // Decryption
    for (int i = 0; i < 10; i++) {
        res = decode(ciphertexts[i], dkeys[i]);
        printf("%016lX\n", res);
    }

    // Measure time
    clock_t start = clock();
    lung cmsg = encode(plaintexts[0], ekeys[0]);
    clock_t end = clock();
    printf("%.3f", ((double)(end - start)) / CLOCKS_PER_SEC * 1000);
}