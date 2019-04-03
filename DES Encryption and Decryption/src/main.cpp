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