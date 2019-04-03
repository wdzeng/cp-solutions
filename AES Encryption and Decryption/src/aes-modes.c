#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZ 1024
#define bool int
#define true 1
#define false 0

unsigned hextoval(char c) {
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return c - '0';
}

int hextostr(unsigned char* str) {
    unsigned n;
    unsigned char* cur = str;
    for (int i = 0; str[i]; i += 2, cur++) {
        n = hextoval(str[i]) * 16 + hextoval(str[i + 1]);
        *cur = n;
    }
    *cur = 0;
    return cur - str;
}

void clearPkcs7(unsigned char* str) {
    int slen = strlen(str);
    int rem = str[slen - 1];
    if (rem > 16) rem = 0;
    str[slen - rem] = 0;
}

void printHexaString(const unsigned char* s, int len, FILE* output) {
    for (int i = 0; i < len; i += 2) {
        fprintf(output, "%02x%02x ", s[i], s[i + 1]);
    }
    fprintf(output, "\n");
}

void pkcs7(unsigned char* input) {
    int len = strlen((char*)input);
    int rem = 16 - len % 16;
    for (int i = 0; i < rem; i++) input[len + i] = rem;
    input[len + rem] = 0;
}

void pad0(unsigned char* input) {
    int len = strlen((char*)input);
    int rem = 16 - len % 16;
    for (int i = 0; i < rem; i++) input[len + i] = 0;
    input[len + rem] = 0;
}

void cbcDecrypt(const unsigned char* input, int slen, unsigned char* output,
                const unsigned char* key, const unsigned char* ivec,
                bool usepkcs7, int nbit) {
    unsigned char vector[16];
    memcpy(vector, ivec, 16);
    unsigned char buff[BUF_SIZ] = {0};
    memcpy((char*)buff, (const char*)input, slen);

    AES_KEY akey;
    AES_set_decrypt_key(key, nbit, &akey);
    AES_cbc_encrypt(buff, output, slen, &akey, vector, AES_DECRYPT);
    clearPkcs7(output);
}

int cbcEncrypt(const unsigned char* input, unsigned char* output,
               const unsigned char* key, const unsigned char* ivec,
               bool usepkcs7, int nbit) {
    const int nbyte = nbit / 8;

    unsigned char vector[16];
    memcpy(vector, ivec, 16);
    unsigned char buff[BUF_SIZ];
    strcpy((char*)buff, (const char*)input);
    if (usepkcs7) {
        pkcs7(buff);
    } else {
        pad0(buff);
    }

    int len0 = strlen((char*)input);
    const int len = len0 + 16 - len0 % 16;
    const int n = len / 16;

    AES_KEY akey;
    AES_set_encrypt_key(key, nbit, &akey);
    AES_cbc_encrypt(buff, output, len, &akey, vector, AES_ENCRYPT);
    return len;
}

void ecbDecrypt(const unsigned char* input, int len, unsigned char* output,
                const unsigned char* key, bool usepkcs7, int nbit) {
    int n = len / 16;
    unsigned char buff[len];
    memcpy(buff, input, len);
    AES_KEY akey;
    AES_set_decrypt_key(key, nbit, &akey);

    unsigned char *icur = buff, *ocur = output;
    while (n--) {
        AES_ecb_encrypt(icur, ocur, &akey, AES_DECRYPT);
        icur += 16;
        ocur += 16;
    }
    clearPkcs7(output);
}

int ecbEncrypt(const unsigned char* input, unsigned char* output,
               const unsigned char* key, bool usepkcs7, int nbit) {
    const int nbyte = nbit / 8;

    unsigned char buff[BUF_SIZ];
    strcpy((char*)buff, (const char*)input);
    if (usepkcs7) {
        pkcs7(buff);
    } else {
        pad0(buff);
    }

    int len0 = strlen((char*)input);
    const int len = len0 + 16 - len0 % 16;
    const int n = len / 16;

    AES_KEY akey;
    AES_set_encrypt_key(key, nbit, &akey);

    unsigned char* icur = buff;
    unsigned char* ocur = output;
    for (int i = 0; i < n; i++) {
        AES_ecb_encrypt(icur, ocur, &akey, AES_ENCRYPT);
        icur += 16;
        ocur += 16;
    }

    return len;
}

int main() {
    const unsigned char strkey[] = "1234567890123456";
    const unsigned char vector[] = "0000000000000000";
    const int nbit = strlen((char*)strkey) * 8;
    unsigned char plntxt[] = "AES is efficient in both software and hardware.";
    unsigned char output[BUF_SIZ];
    int outlen;

    FILE* out = fopen("./Out.txt", "w");
    if (out == NULL) {
        printf("Fail to write to the file.\n");
        exit(-1);
    }

    memset(output, 0, BUF_SIZ);
    outlen = ecbEncrypt(plntxt, output, strkey, false, nbit);
    printHexaString(output, outlen, out);

    memset(output, 0, BUF_SIZ);
    outlen = ecbEncrypt(plntxt, output, strkey, true, nbit);
    printHexaString(output, outlen, out);

    memset(output, 0, BUF_SIZ);
    outlen = cbcEncrypt(plntxt, output, strkey, vector, false, nbit);
    printHexaString(output, outlen, out);

    memset(output, 0, BUF_SIZ);
    outlen = cbcEncrypt(plntxt, output, strkey, vector, true, nbit);
    printHexaString(output, outlen, out);

    fclose(out);
    printf("Done.\n");
    return 0;
}