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
    return (val >> index) & 1l;
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