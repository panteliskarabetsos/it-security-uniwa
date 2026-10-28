#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM * a)
{
 
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);

} 

int main ()
{

    BN_CTX *ctx = BN_CTX_new(); //ctx structure
    BIGNUM *num1 = BN_new(); 
    BIGNUM *p = BN_new(); 
    BIGNUM *q = BN_new(); 
    BIGNUM *e = BN_new(); 
    BIGNUM *N = BN_new(); 
    BIGNUM *res2 = BN_new(); 
    BIGNUM *res3 = BN_new(); 
    BIGNUM *fN = BN_new(); 
    BIGNUM *d = BN_new();

    // Initialize a, b, n
    BN_hex2bn(&num1, "1");
    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");

    // calculate res = p*q
    BN_mul(N, p, q, ctx);
    // print result
    printBN("p * q = ", N);

    // calculate res = p - 1
    BN_sub(res2, p, num1);
    // print result
    printBN("p - 1 = ", res2); 

    //Calculate res = q - 1
    BN_sub(res3, q, num1);
    // print result
    printBN(" q - 1 = ", res3);

    // calculate fN = (p - 1)*(q - 1)
    BN_mul(fN, res2, res3, ctx);
    // print result
    printBN("f(N) = (p - 1)*(q - 1) = ", fN); 

    // calculate rd
    BN_mod_inverse(d, e, fN, ctx);
    // print result
    printBN("Private key d = ", d);

    return 0;
} 
