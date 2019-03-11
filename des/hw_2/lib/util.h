#ifndef hpblcryutil
#define hpblcryutil

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

#endif