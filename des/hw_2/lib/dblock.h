#include <iostream>
#include "./sbox.h"
#include "./util.h"

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

lung encode(lung msg, lung key48s[]) {
    lung res = nmdblock::genIp(msg);
    res = nmdblock::encrypt(res, key48s, false);
    return nmdblock::genFp(res);
}

lung decode(lung msg, lung key48s[]) {
    lung res = nmdblock::genIp(msg);
    res = nmdblock::encrypt(res, key48s, true);
    return nmdblock::genFp(res);
}