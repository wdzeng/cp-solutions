#include "./dblock.h"
#include "./keygen.h"
#include "./util.h"

// Encodes a message by DES.
lung encode(lung plain, lung key) {
    lung subkeys[16];
    createSubkeys(key, subkeys);
    return encode(plain, subkeys);
}

// Decodes a message by DES.
lung decode(lung cipher, lung key) {
    lung subkeys[16];
    createSubkeys(key, subkeys);
    return decode(cipher, subkeys);
}

// Encodes a message by 3DES.
lung encode3(lung plain, lung k1, lung k2, lung k3) {
    return encode(decode(encode(plain, k1), k2), k3);
}

// Decodes a message by 3DES.
lung decode3(lung cipher, lung k1, lung k2, lung k3) {
    return decode(encode(decode(cipher, k3), k2), k1);
}