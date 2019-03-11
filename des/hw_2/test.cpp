#include <iostream>
#include "./lib/dblock.h"
#include "./lib/keygen.h"
using namespace std;

int main() {
    lung key = 0x5B5A57676A56676Eul;
    lung pmsg = 0x675A69675E5A6B5Aul;
    lung subkeys[16];
    createSubKeys(key, subkeys);
    printf("%016lX", encode(pmsg, subkeys));
}