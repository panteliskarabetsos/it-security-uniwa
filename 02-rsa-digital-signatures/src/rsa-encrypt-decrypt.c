#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM * a)
{
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
} 

int main() {
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *m = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *encrypted = BN_new();
    BIGNUM *decrypted = BN_new();

    BN_hex2bn(&m, "416e61737461736961204b617473697069");
    BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
    BN_hex2bn(&e, "0D88C3");
    BN_hex2bn(&d, "3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB");

    // Print values of m, n, e, and d
    printBN("m = ", m);
    printBN("n = ", n);
    printBN("e = ", e);
    printBN("d = ", d);

    // calculate encrypted
    BN_mod_exp(encrypted, m, e, n, ctx);
    // print result
    printBN("encrypted = ", encrypted);

    // calculate decrypted
    BN_mod_exp(decrypted, encrypted, d, n, ctx);
    // print result
    printBN("decrypted = ", decrypted);

    return 0;
}

