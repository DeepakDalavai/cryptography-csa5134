#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

// Define the key matrix globally
int key[MATRIX_SIZE][MATRIX_SIZE];

// Encrypt function using the Hill cipher
void hillEncrypt(char *plaintext, char *ciphertext) {
    int x[MATRIX_SIZE];
    int y[MATRIX_SIZE];

    // Convert characters to numerical values
    for (int i = 0; i < MATRIX_SIZE; i++) {
        x[i] = plaintext[i] - 'a';
    }

    // Perform matrix multiplication for encryption
    for (int i = 0; i < MATRIX_SIZE; i++) {
        y[i] = 0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            y[i] += key[i][j] * x[j];
        }
        y[i] %= 26; // Apply modulo 26
    }

    // Convert numerical values to characters
    for (int i = 0; i < MATRIX_SIZE; i++) {
        ciphertext[i] = y[i] + 'a';
    }
    ciphertext[MATRIX_SIZE] = '\0'; // Null-terminate the string
}

int main() {
    char plaintext[MATRIX_SIZE + 1]; // +1 for null terminator
    char ciphertext[MATRIX_SIZE + 1]; // +1 for null terminator

    // Prompt user to enter the key matrix
    printf("Enter the key matrix for Hill cipher (3x3):\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    // Prompt user to enter the plaintext for encryption
    printf("Enter the plaintext (3 characters): ");
    scanf("%s", plaintext);

    // Perform encryption
    hillEncrypt(plaintext, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
