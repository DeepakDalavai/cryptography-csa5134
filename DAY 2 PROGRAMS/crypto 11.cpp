#include <stdio.h>
#include <string.h>

// Function to calculate the number of effectively unique keys for the Playfair cipher
unsigned long long calculateEffectiveKeys(char *key) {
    // The key matrix is 5x5, so it can have 25 unique letters
    int matrixSize = 25;

    // Initialize an array to keep track of used letters
    char usedLetters[matrixSize];
    memset(usedLetters, '\0', sizeof(usedLetters));

    int index = 0;

    // Fill the usedLetters array with unique letters from the key
    for (int i = 0; i < strlen(key); i++) {
        if (key[i] != ' ' && key[i] != 'J' && !strchr(usedLetters, key[i])) {
            usedLetters[index++] = key[i];
        }
    }

    // Calculate the number of remaining empty slots in the key matrix
    int emptySlots = matrixSize - index;

    // Calculate the number of effectively unique keys
    unsigned long long effectiveKeys = 1;
    for (int i = matrixSize; i > emptySlots; i--) {
        effectiveKeys *= i;
    }

    return effectiveKeys;
}

int main() {
    char key[26];

    // Input the key from the user
    printf("Enter the key for the Playfair cipher (without spaces, 'J' excluded): ");
    scanf("%s", key);

    // Calculate and display the number of effectively unique keys
    unsigned long long uniqueKeys = calculateEffectiveKeys(key);
    printf("Number of effectively unique keys: %llu\n", uniqueKeys);

    return 0;
}
