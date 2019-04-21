#include <openssl/bn.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

void str2hex(const char *input, char *output) {
    int loop;
    int i;

    i = 0;
    loop = 0;

    while (input[loop] != '\0') {
        sprintf((char *)(output + i), "%02X", input[loop]);
        loop += 1;
        i += 2;
    }
    // insert NULL at the end of the output string
    output[i++] = '\0';
}

int main() {
    char str_e[128];
    char str_n[2048];
    char msg[2048];

    printf("Input plain message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strlen(msg) - 1] = 0;
    printf("Input e in hex: ");
    scanf("%s", str_e);
    printf("Input n in hex: ");
    scanf("%s", str_n);
    
    char hexMsg[strlen(msg) * 2 + 1];
    str2hex(msg, hexMsg);

    BIGNUM *e = NULL;
    BIGNUM *n = NULL;
    BIGNUM *m = NULL;
    BIGNUM *c = NULL;
    BN_CTX *ctx = BN_CTX_new();

    BN_hex2bn(&e, str_e);
    BN_hex2bn(&n, str_n);
    BN_hex2bn(&m, hexMsg);
    BN_hex2bn(&c, "0"); // Alloc mem
    BN_mod_exp(c, m, e, n, ctx);

    FILE *out = fopen("./out.txt", "a");
    fprintf(out, "%s\n", BN_bn2hex(c));
    fclose(out);
    return 0;
}