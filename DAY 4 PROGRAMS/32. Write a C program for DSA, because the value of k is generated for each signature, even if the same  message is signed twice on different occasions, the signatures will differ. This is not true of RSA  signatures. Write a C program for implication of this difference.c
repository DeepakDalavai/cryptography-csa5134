#include <stdio.h>
#include <openssl/dsa.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include <openssl/err.h>

#define MESSAGE "Hello, World!"

void print_hex(const char* label, const unsigned char* data, size_t len) {
    printf("%s: ", label);
    for (size_t i = 0; i < len; ++i) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void dsa_signature_example() {
    DSA* dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
    DSA_generate_key(dsa);

    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((const unsigned char*)MESSAGE, sizeof(MESSAGE), hash);

    DSA_SIG* signature = DSA_do_sign(hash, SHA_DIGEST_LENGTH, dsa);

    printf("DSA Signature:\n");
    print_hex("r", (unsigned char*)&(signature->r), BN_num_bytes(signature->r));
    print_hex("s", (unsigned char*)&(signature->s), BN_num_bytes(signature->s));

    DSA_free(dsa);
    DSA_SIG_free(signature);
}

void rsa_signature_example() {
    RSA* rsa = RSA_generate_key(1024, RSA_F4, NULL, NULL);

    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((const unsigned char*)MESSAGE, sizeof(MESSAGE), hash);

    unsigned int signature_len;
    unsigned char* signature = (unsigned char*)malloc(RSA_size(rsa));
    RSA_sign(NID_sha1, hash, SHA_DIGEST_LENGTH, signature, &signature_len, rsa);

    printf("\nRSA Signature:\n");
    print_hex("", signature, signature_len);

    RSA_free(rsa);
    free(signature);
}

int main() {
    printf("Message: %s\n\n", MESSAGE);

    printf("First DSA Signature:\n");
    dsa_signature_example();

    printf("\nSecond DSA Signature:\n");
    dsa_signature_example();

    printf("\nRSA Signature:\n");
    rsa_signature_example();

    return 0;
}
