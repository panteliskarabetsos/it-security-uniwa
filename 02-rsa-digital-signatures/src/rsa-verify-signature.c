#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM * a)
{
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
} 

int main() {
    
    //PART A
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *MD = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *s = BN_new();
    BIGNUM *MD_DECRYPTED = BN_new();
    BIGNUM *s_changed = BN_new();
    BIGNUM *MD_DECRYPTED_changed = BN_new();

    BN_hex2bn(&MD, "546865732077656174686572206973207065726665637421");
    BN_hex2bn(&s_changed, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&s, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");

    // calculate MD_DECRYPTED
    BN_mod_exp(MD_DECRYPTED, s, e, n, ctx);
    // print result
    printBN("Sign decrypted = ", MD_DECRYPTED);

    // calculate MD_DECRYPTED
    BN_mod_exp(MD_DECRYPTED_changed, s_changed, e, n, ctx);
    // print result
    printBN("Sign wrong decrypted = ", MD_DECRYPTED_changed);

    //PART B
    BIGNUM *s_alice = BN_new();
    BIGNUM *e_alice = BN_new();
    BIGNUM *n_alice = BN_new();
    BIGNUM *MD_DECRYPTED_alice = BN_new();
    
    BN_hex2bn(&n_alice, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e_alice, "010001");
    BN_hex2bn(&s_alice, "DB3F7CDB93483FC1E70E4EACA650E3C6505A3E5F49EA6EDF3E95E9A7C6C7A320");

    // calculate MD_DECRYPTED
    BN_mod_exp(MD_DECRYPTED_alice, s_alice, e_alice, n_alice, ctx);
    // print result
    printBN("Sign decrypted = ", MD_DECRYPTED_alice);

    return 0;
}
