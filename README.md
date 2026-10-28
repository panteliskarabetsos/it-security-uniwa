# Information Technology Security — Coursework

Coursework for the **Information Technology (IT) Security** course
(*Ασφάλεια στην Τεχνολογία της Πληροφορίας*) at the Department of Informatics and
Computer Engineering, **University of West Attica (UNIWA)**.

**Author:** Pantelis Karampetsos · Reg. No. 20390089

The projects cover hands-on offensive and defensive security: exploiting a memory
corruption vulnerability, implementing RSA and digital signatures with OpenSSL,
repackaging an Android application, building a PKI, and configuring a firewall.
Most labs were carried out in the [SEED Labs](https://seedsecuritylabs.org/)
virtual-machine environment.

## Projects

| # | Project | Topic | Deliverables |
|---|---------|-------|--------------|
| 1 | [Buffer Overflow Attack](01-buffer-overflow/) | Stack-based buffer overflow, shellcode injection, countermeasures (ASLR, StackGuard, non-executable stack) | Report |
| 2 | [RSA & Digital Signatures](02-rsa-digital-signatures/) | RSA key generation, encryption/decryption and signature verification implemented in C with the OpenSSL BIGNUM API; manual X.509 certificate verification | C source + report |
| 3 | [Android Repackaging](03-android-repackaging/) | Decompiling, injecting malicious code into, and re-signing an APK; ADB and sideloading delivery | Report |
| 4 | [Public Key Infrastructure (PKI)](04-pki/) | Building a Certificate Authority, issuing certificates, HTTPS with Apache/OpenSSL, and a man-in-the-middle attack with a compromised CA | Report |
| 5 | [OPNsense Firewall](05-opnsense-firewall/) | Perimeter security and firewall rule configuration | Assignment brief |

## Skills demonstrated

- Low-level memory exploitation and defensive countermeasures
- Applied cryptography: RSA, digital signatures, X.509 certificates
- C programming with the OpenSSL library
- Public Key Infrastructure and TLS/HTTPS
- Android application security
- Network perimeter security and firewalls

## Notes

Reports are written in Greek. The code and this overview are in English.
Course lecture material and third-party work are intentionally **not** included in
this repository.

---

*Παντελής Καραμπέτσος — Πανεπιστήμιο Δυτικής Αττικής, Τμήμα Μηχανικών Πληροφορικής και Υπολογιστών*
