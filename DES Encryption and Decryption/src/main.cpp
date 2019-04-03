// Author: 0716023 Wen-Ting Zeng
#include <time.h>
#include <iostream>
#include "../lib/des.h"
using namespace std;

uint64_t strtoint(const unsigned char[16]) {}

int main() {
    FILE *in, *out = fopen("./out.txt", "w");
    if (out == NULL) {
        printf("Fail to access file.\n");
        return -1;
    }

    uint64_t plaintextsAndKeys[] = {
        0xda3014b0715059e6, 0xbe480047cce655db, 0x453b067193a45dd6,
        0xc991fcb1c2ca8d56, 0x6d5b8932b745264e, 0xe5e2adf3e3accebd,
        0x89ef992ca9f3dbbf, 0x557e28cf53b12a71, 0x7f466ddd525c32c7,
        0xbf36fa881cd554d8, 0x95b330236137670d, 0xfc8bcee076acd78a,
        0x6ea9f9e827f8a414, 0x2f41770c4841039c, 0x3310a8cac239c4e8,
        0x18c09faaefd5fb85, 0x0f4bdbf17d4975f5, 0xaadd02913d90abd5,
        0xe1a02d8b76738dee, 0xdad35f07c350f584};
    uint64_t ciphertextsAndKeys[] = {
        0xc71b0946f8308fa5, 0x37ca5f03bbdb5668, 0x1e8951c1253c2837,
        0x1ad9299839efc771, 0x9b18bbfc748fa55e, 0x79e6db8d6c4f725f,
        0xf4ef880bbbd5fa36, 0xe45d6ef5999a2329, 0xa647883ddb55a783,
        0xd0d1226520263b9f, 0x71045a9a2381da5d, 0x0cfb7d18bf8f4cf3,
        0x07f437adf583e839, 0xcbbffe5f7bdc33cf, 0xffa08459aabce49d,
        0xadbef68debd8b7a6, 0x0ff2ef31b23c32ff, 0xb918355be8203c81,
        0x7a08ea6100b83807, 0x769b1ab38193c72c};

    uint64_t res, text, key;
    double timesum = 0;

    // Encrpytion
    in = fopen("../res/DES-Key-Plaintext.txt", "r");
    if (in == NULL) {
        printf("Fail to write to the file.\n");
        exit(-1);
    }
    for (int i = 0; i < 10; i++) {
        fscanf(in, "%016lx %016lx", &key, &text);
        clock_t start = clock();
        res = des::encode(text, key);
        clock_t end = clock();
        timesum += (double)(end - start);
        fprintf(out, "%016lX\n", res);
    }
    fprintf(out, "\n");
    fclose(in);

    // Decryption
    in = fopen("../res/DES-Key-Ciphertext.txt", "r"); 
    for (int i = 0; i < 20; i += 2) {
        fscanf(in, "%016lx %016lx", &key, &text);
        clock_t start = clock();
        res = des::decode(text, key);
        clock_t end = clock();
        timesum += (double)(end - start);
        fprintf(out, "%016lX\n", res);
    }
    fprintf(out, "\n");
    fclose(in);

    // Measure time
    double time = timesum / 20 / CLOCKS_PER_SEC * 1000;
    fprintf(out, "%.3f ms\n", time);
    fclose(out);
    printf("Task completed. Please inspect the output.\n");
    return 0;
}