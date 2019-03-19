#ifndef des0716023
#define des0716023

#include <stdint.h>
#include "./cipblk.h"
#include "./key.h"
#include "./util.h"

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