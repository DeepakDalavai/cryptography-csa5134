#include <stdio.h>
#include <ctype.h>

int main() {
    char pt[1000], ct[1000], key[27];
    int i;

    printf("Enter plaintext: "); fgets(pt, sizeof(pt), stdin);
    printf("Enter substitution key (26 unique letters): "); fgets(key, sizeof(key), stdin);

    for (i = 0; pt[i] != '\0'; i++)
        ct[i] = isalpha(pt[i]) ? (islower(pt[i]) ? key[pt[i] - 'a'] : toupper(key[pt[i] - 'A'])) : pt[i];
    ct[i] = '\0';

    printf("Ciphertext: %s\n", ct);

    return 0;
}
