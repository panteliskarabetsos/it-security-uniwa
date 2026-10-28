# RSA & Digital Signatures

Implementation of core RSA operations in C using the **OpenSSL BIGNUM** API,
following the SEED Labs "RSA Public-Key Encryption and Signature" lab.

Each program manipulates large integers (`BIGNUM`) with modular arithmetic
(`BN_mod_exp`, `BN_mod_inverse`, `BN_mul`) and prints results in hexadecimal.

## Programs

| File | What it does |
|------|--------------|
| [`rsa-key-generation.c`](src/rsa-key-generation.c) | Derives the private exponent `d` from primes `p`, `q` and public exponent `e`: computes `N = p·q`, `φ(N) = (p-1)(q-1)`, and `d = e⁻¹ mod φ(N)`. |
| [`rsa-encrypt-decrypt.c`](src/rsa-encrypt-decrypt.c) | Encrypts a message `m` with the public key (`c = mᵉ mod N`) and decrypts it back with the private key (`m = cᵈ mod N`). |
| [`rsa-decrypt-ciphertext.c`](src/rsa-decrypt-ciphertext.c) | Decrypts a given ciphertext using the private key. |
| [`rsa-verify-signature.c`](src/rsa-verify-signature.c) | Verifies an RSA signature (`m = sᵉ mod N`) and shows how a single altered bit breaks verification. |
| [`x509-verify-certificate.c`](src/x509-verify-certificate.c) | Verifies the issuer's signature on a real X.509 certificate obtained from a live web server. |

## Build & run

Requires the OpenSSL development headers (`libssl-dev` on Debian/Ubuntu).

```bash
cd src
gcc rsa-key-generation.c -o rsa-key-generation -lcrypto
./rsa-key-generation
```

Replace the filename to build any of the other programs.

> The hexadecimal inputs in the source files are the sample values provided by the
> lab assignment.
