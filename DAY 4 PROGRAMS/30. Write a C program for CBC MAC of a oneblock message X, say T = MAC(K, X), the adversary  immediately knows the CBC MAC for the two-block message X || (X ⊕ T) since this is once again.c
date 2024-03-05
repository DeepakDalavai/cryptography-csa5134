#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16
void xor_blocks(uint8_t *a, uint8_t *b, uint8_t *result) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = a[i] ^ b[i];
    }
}
void aes_encrypt(uint8_t *plaintext, uint8_t *key, uint8_t *ciphertext) {
    memcpy(ciphertext, plaintext, BLOCK_SIZE);
}
void cbc_mac(uint8_t *message, uint8_t *key, uint8_t *mac) {
    uint8_t iv[BLOCK_SIZE] = {0}; 
    uint8_t xor_result[BLOCK_SIZE];
    xor_blocks(iv, message, xor_result);

    aes_encrypt(xor_result, key, mac);
}

int main() {
    
    uint8_t message[BLOCK_SIZE] = "Hello, World!"; 
    uint8_t key[BLOCK_SIZE] = "ThisIsASecretKey"; 
    uint8_t mac[BLOCK_SIZE];
    cbc_mac(message, key, mac);
    printf("MAC for one-block message X: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", mac[i]);
    }
    printf("\n");

    return 0;
}

