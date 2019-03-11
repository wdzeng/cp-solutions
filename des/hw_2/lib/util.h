#ifndef hpblcryutil
#define hpblcryutil

typedef unsigned long lung;

namespace nmcryutil {

// Converts a hexadecimal string to a lung integer. Length of string should be
// less than 16.
lung toLong(char* hexStr);

// Converts a hexadecimal string to an integer. Length of string should be less
// than 8.
int toInt(char* hexStr);

// Converts 0-h to integer.
int toInt(char c);

// Gets the bit at a specific position. Returns either 0 or 1. If right is set
// to true, the index is count from right to left. That is, the 63th bit matches
// index=0. If zero is set to first, the first index is 0 or otherwise 1.
int bitAt(lung val, int index, bool right = 1, bool zero = 1);

// Gets the bit at a specific position. Returns either 0 or 1. If right is set
// to true, the index is count from right to left. That is, the 31th bit matches
// index=0. If zero is set to first, the first index is 0 or otherwise 1.
int bitAt(int val, int index, bool right = 1, bool zero = 1);

// Sets and returns the bit at a specific position. If right is set to true, the
// index is count from right to left. That is, the 63th bit matches index=0. If
// zero is set to first, the first index is 0 or otherwise 1.
lung bit(lung src, int index, int val, bool right = 1, bool zero = 1);

// Sets and returns the bit at a specific position. If right is set to true, the
// index is count from right to left. That is, the 31th bit matches index=0. If
// zero is set to first, the first index is 0 or otherwise 1.
int bit(int src, int index, int val, bool right = 1, bool zero = 1);

// Converts an integer range from 0 to 15 to a hexadecimal character. If
// uppercase is set to true, returns the uppercase character or otherwise
// lowercase one.
char toHex(int i, int uppercase = 1);

// Converts a lung integer to a 16-bit hexadecimal string.
void toHex(lung val, char* res);

// Converts an integer to an 8-bit hexadecimal string.
void toHex(int val, char* res);

// Converts a lung integer to a 64-bit binary string.
void toBin(lung val, char* res);

// Converts a lung integer to a 32-bit binary string.
void toBin(int val, char* res);

// Permutation by a table.
lung shuffle(lung src, int table[], int len);

/**************************************************************************************/

lung toLong(char* hexStr) {
    lung res = toInt(hexStr[0]);
    int v;
    for (int i = 1; hexStr[i]; i++) {
        res <<= 4;
        res |= toInt(hexStr[i]);
    }
    return res;
}

int toInt(char* hexStr) {
    int res = toInt(hexStr[0]);
    int v;
    for (int i = 1; hexStr[i]; i++) {
        res <<= 4;
        res |= toInt(hexStr[i]);
    }
    return res;
}

int toInt(char c) {
    if (c >= 'a') return 10 + c - 'a';
    if (c >= 'A') return 10 + c - 'A';
    return c - '0';
}

int bitAt(lung val, int index, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 63 - index;
    }
    return (val >> index) & 1;
}

int bitAt(int val, int index, bool right, bool zero) {
    if (!zero) {
        index--;
    }
    if (!right) {
        index = 31 - index;
    }
    return (val >> index) & 1;
}

char toHex(int i, int uppercase) {
    if (i > 9) {
        return (uppercase ? 'A' : 'a') + (i - 10);
    }
    return i + '0';
}

void toHex(lung val, char* res) {
    res[16] = '\0';
    for (int i = 15; i >= 0; i--) {
        res[i] = toHex(val & 0x0F);
        val >>= 4;
    }
}

void toHex(int val, char* res) {
    res[8] = '\0';
    for (int i = 7; i >= 0; i--) {
        res[i] = toHex(val & 0x0F);
        val >>= 4;
    }
}

void toBin(lung val, char* res) {
    res[64] = '\0';
    int v;
    for (int i = 0; i < 64; i++) {
        v = bitAt(val, i, 0);
        res[i] = v ? '1' : '0';
    }
}

void toBin(int val, char* res) {
    res[32] = '\0';
    int v;
    for (int i = 0; i < 32; i++) {
        v = bitAt(val, i, 0);
        res[i] = v ? '1' : '0';
    }
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

int bit(int src, int index, int val, bool right, bool zero) {
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