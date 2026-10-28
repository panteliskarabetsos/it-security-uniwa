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
    BIGNUM *c = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *decrypted_c = BN_new();

    BN_hex2bn(&c, "9D368A5F8F562EB9553F6081B492C3D9527298DA5557B1895E6F7B7C8B01A308");
    BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
    BN_hex2bn(&e, "0D88C3");
    BN_hex2bn(&d, "3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB");

    // Print values of m, n, e, and d
    printBN("n = ", n);
    printBN("e = ", e);
    printBN("d = ", d);

    // calculate decrypted_c
    BN_mod_exp(decrypted_c, c, d, n, ctx);
    // print result
    printBN("decrypted = ", decrypted_c);

    return 0;
}


