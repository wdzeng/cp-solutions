#ifndef desutil
#define desutil

#include <stdint.h>

namespace bit {

// Gets the bit at a specific position. Returns either 0 or 1. If right is set
// to true, the index is count from right to left. That is, the 63th bit matches
// index=0. If zero is set to first, the first index is 0 or otherwise 1.
int get(uint64_t val, int index, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 63 - index;
    }
    return (val >> index) & 1;
}

// Gets the bit at a specific position. Returns either 0 or 1. If right is set
// to true, the index is count from right to left. That is, the 31th bit matches
// index=0. If zero is set to first, the first index is 0 or otherwise 1.
int get(uint32_t val, int index, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 31 - index;
    }
    return (val >> index) & 1;
}

// Sets the bit at a specific position then returns the new value. If right is
// set to true, the index is count from right to left. That is, the 63th bit
// matches index=0. If zero is set to first, the first index is 0 or
// otherwise 1.
uint64_t set(uint64_t src, int index, int val, bool right, bool zero) {
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

// Sets the bit at a specific position then returns the new value. If right is
// set to true, the index is count from right to left. That is, the 31th bit
// matches index=0. If zero is set to first, the first index is 0 or
// otherwise 1.
uint32_t set(uint32_t src, int index, int val, bool right, bool zero) {
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

}  // namespace bit

namespace shuf {

// Permutation by a table.
uint64_t shuffle(uint64_t src, int srclen, int table[], int tblen,
                 bool right = true, bool zero = true) {
    int tbshift = right ? 0 : (64 - tblen);
    int srcshift = right ? 0 : (64 - srclen);
    int index, b;
    uint64_t res = 0;
    for (int i = 0; i < tblen; i++) {
        index = table[i];
        b = bit::get(src, index + srcshift, right, zero);
        res = bit::set(res, i + tbshift, b, right, true);
    }
    return res;
}

}  // namespace shuf

#endif

#ifndef deskey
#define deskey
#include <stdint.h>

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
    uint32_t dkey = key56 & 0x0FFFFFFFul;
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

#ifndef descip
#define descip

namespace sbox {

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
    return S_BOXES[((index - 1) << 6) | (row << 4) | col];
}

// Gets the value in s boxes by a given 6-bit key.
int s(int index, uint32_t key6) {
    int row = (key6 & 0b100000) >> 4 | (key6 & 1);
    int col = (key6 & 0b011110) >> 1;
    return s(index, row, col);
}

}  // namespace sbox

namespace cipblk {

using namespace sbox;

// Performs a single permutation of data.
void encrypt(uint32_t* left, uint32_t* right, uint64_t key);

// Performs 16 permutation processes to data and a reverse. Then applys the
// final permutation. Returns the permutated 64-bit value.
uint64_t encrypt(uint64_t ip, uint64_t keys[], bool reverse = false);

// Query the value in s boxes.
uint32_t squery(uint64_t e);

// A permutation about DES.
uint32_t f(uint32_t key32, uint64_t key48);

// Performs the inital permutation.
uint64_t genIp(uint64_t msg);

// Performs the final permutation.
uint64_t genFp(uint64_t msg);

// Concantates two 32-bit keys to a 64-bit key.
uint64_t concat3264(uint32_t left, uint32_t right);

// Split a 64-bit key into two 32-bit keys.
void split6432(uint64_t seq, uint32_t* left, uint32_t* right);

uint64_t concat3264(uint32_t left, uint32_t right) {
    return (uint64_t)left << 32 | right;
}

void split6432(uint64_t seq, uint32_t* left, uint32_t* right) {
    *left = seq >> 32;
    *right = seq & 0xFFFFFFFFul;
}

uint64_t genIp(uint64_t msg) {
    static int TABLE_INITIAL_PERMUTATION[] = {
        58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
    return shuf::shuffle(msg, 64, TABLE_INITIAL_PERMUTATION, 64, false, false);
}

uint64_t genFp(uint64_t msg) {
    static int TABLE_FINAL_PERMUTATION[] = {
        40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9,  49, 17, 57, 25};
    return shuf::shuffle(msg, 64, TABLE_FINAL_PERMUTATION, 64, false, false);
}

uint64_t encrypt(uint64_t ip, uint64_t keys[], bool reverse) {
    uint32_t left, right;
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

void encrypt(uint32_t* left, uint32_t* right, uint64_t key) {
    uint32_t right0 = *right;
    *right = *left ^ f(*right, key);
    *left = right0;
}

uint32_t squery(uint64_t e) {
    uint32_t key6;
    uint32_t sb[8];
    for (int i = 7; i >= 0; i--) {
        key6 = e & 0b111111u;
        sb[i] = s(i + 1, key6);  // index 0 matches the box 1
        e >>= 6;
    }
    uint32_t res = 0;
    for (int i = 0; i < 8; i++) {
        res |= sb[i];
        if (i < 7) res <<= 4;
    }
    return res;
}

uint32_t f(uint32_t key32, uint64_t key48) {
    static int TABLE_E_BIT_SELECTION[] = {
        32, 1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,  8,  9,  10, 11,
        12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21,
        22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
    static int TABLE_P[] = {16, 7, 20, 21, 29, 12, 28, 17, 1,  15, 23,
                            26, 5, 18, 31, 10, 2,  8,  24, 14, 32, 27,
                            3,  9, 19, 13, 30, 6,  22, 11, 4,  25};

    uint64_t e =
        shuf::shuffle(key32, 32, TABLE_E_BIT_SELECTION, 48, false, false);
    uint32_t spmt = squery(e ^ key48);
    return shuf::shuffle(spmt, 32, TABLE_P, 32, false, false);
}

}  // namespace cipblk

#endif

#ifndef des0716023
#define des0716023

#include <stdint.h>

namespace des {

namespace tool {

// Generates 16 subkeys by given 64-biy key. Each subkey is 48-bit prefixed
// with 8 zeros. The 64-bit key is first permutated to another 56-bit key, then
// multuple tasks are processed to generate such subkeys.
void createSubkeys(uint64_t seed, uint64_t keys[]) {
    seed = key::genKey56(seed);
    key::genKey48s(seed, keys);
}

// Encodes a 64-bit message with 16 48-bit subkeys.
uint64_t encode(uint64_t msg, uint64_t key48s[]) {
    uint64_t res = cipblk::genIp(msg);
    res = cipblk::encrypt(res, key48s, false);
    return cipblk::genFp(res);
}

// Decodes a 64-bit message with 16 48-bit subkeys.
uint64_t decode(uint64_t msg, uint64_t key48s[]) {
    uint64_t res = cipblk::genIp(msg);
    res = cipblk::encrypt(res, key48s, true);
    return cipblk::genFp(res);
}

}  // namespace tool

// Encodes a 64-bit message
uint64_t encode(uint64_t msg, uint64_t key64) {
    uint64_t subkeys[16];
    tool::createSubkeys(key64, subkeys);
    return tool::encode(msg, subkeys);
}

// Decodes a 64-bit message
uint64_t decode(uint64_t msg, uint64_t key64) {
    uint64_t subkeys[16];
    tool::createSubkeys(key64, subkeys);
    return tool::decode(msg, subkeys);
}

// Encodes a message by 3DES.
uint64_t encode3(uint64_t plain, uint64_t k1, uint64_t k2, uint64_t k3) {
    return encode(decode(encode(plain, k1), k2), k3);
}

// Decodes a message by 3DES.
uint64_t decode3(uint64_t cipher, uint64_t k1, uint64_t k2, uint64_t k3) {
    return decode(encode(decode(cipher, k3), k2), k1);
}

}  // namespace des

#endif

// Author: 0716023 Wen-Ting Zeng
#include <time.h>
#include <iostream>
using namespace std;

int main() {
    FILE* out = fopen("./out.txt", "w");
    if (out == NULL) {
        printf("Fail to access file.\n");
        return -1;
    }

    uint64_t plaintexts[] = {
        0xda3014b0715059e6, 0xbe480047cce655db, 0x453b067193a45dd6,
        0xc991fcb1c2ca8d56, 0x6d5b8932b745264e, 0xe5e2adf3e3accebd,
        0x89ef992ca9f3dbbf, 0x557e28cf53b12a71, 0x7f466ddd525c32c7,
        0xbf36fa881cd554d8, 0x95b330236137670d, 0xfc8bcee076acd78a,
        0x6ea9f9e827f8a414, 0x2f41770c4841039c, 0x3310a8cac239c4e8,
        0x18c09faaefd5fb85, 0x0f4bdbf17d4975f5, 0xaadd02913d90abd5,
        0xe1a02d8b76738dee, 0xdad35f07c350f584};
    uint64_t ciphertexts[] = {
        0xc71b0946f8308fa5, 0x37ca5f03bbdb5668, 0x1e8951c1253c2837,
        0x1ad9299839efc771, 0x9b18bbfc748fa55e, 0x79e6db8d6c4f725f,
        0xf4ef880bbbd5fa36, 0xe45d6ef5999a2329, 0xa647883ddb55a783,
        0xd0d1226520263b9f, 0x71045a9a2381da5d, 0x0cfb7d18bf8f4cf3,
        0x07f437adf583e839, 0xcbbffe5f7bdc33cf, 0xffa08459aabce49d,
        0xadbef68debd8b7a6, 0x0ff2ef31b23c32ff, 0xb918355be8203c81,
        0x7a08ea6100b83807, 0x769b1ab38193c72c};

    uint64_t res;
    double timesum = 0;

    // Encrpytion
    for (int i = 0; i < 20; i += 2) {
        clock_t start = clock();
        res = des::encode(plaintexts[i + 1], plaintexts[i]);
        clock_t end = clock();
        timesum += (double)(end - start);
        fprintf(out, "%016lX\n", res);
    }
    fprintf(out, "\n");

    // Decryption
    for (int i = 0; i < 20; i += 2) {
        clock_t start = clock();
        res = des::decode(ciphertexts[i + 1], ciphertexts[i]);
        clock_t end = clock();
        timesum += (double)(end - start);
        fprintf(out, "%016lX\n", res);
    }
    fprintf(out, "\n");

    // Measure time
    double time = timesum / 20 / CLOCKS_PER_SEC * 1000;
    fprintf(out, "%.3f ms\n", time);
    fclose(out);
    printf("Task completed. Please inspect the output.\n");
    return 0;
}