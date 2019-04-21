#include <openssl/bn.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

unsigned char hexval(unsigned char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    else if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    else if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    else {
        printf("Invalid character: %c", c);
        exit(716023);
    }
}

void hex2str(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i]; i += 2, j++) {
        output[j] = 16 * hexval(input[i]) + hexval(input[i + 1]);
    }
    output[j] = 0;
}

int main() {
    char str_e[128];
    char str_n[2048];
    char cipmsg[2048];

    printf("Input cipher text in hex: ");
    scanf("%s", cipmsg);
    printf("Input d in hex: ");
    scanf("%s", str_e);
    printf("Input n in hex: ");
    scanf("%s", str_n);

    BIGNUM *d = NULL;
    BIGNUM *n = NULL;
    BIGNUM *m = NULL;
    BIGNUM *plain = NULL;
    BN_CTX *ctx = BN_CTX_new();

    BN_hex2bn(&d, str_e);
    BN_hex2bn(&n, str_n);
    BN_hex2bn(&m, cipmsg);
    BN_hex2bn(&plain, "0");  // Alloc mem
    BN_mod_exp(plain, m, d, n, ctx);

    char str_plain[2048];
    hex2str(BN_bn2hex(plain), str_plain);

    FILE *out = fopen("./out.txt", "a");
    fprintf(out, "%s\n", str_plain);
    fclose(out);
    return 0;
}