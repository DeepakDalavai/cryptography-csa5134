#include <stdio.h>
#include <stdlib.h>
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long n; 
    long long block; 
    printf("Enter n (pq): ");
    scanf("%lld", &n);
    
    printf("Enter the block: ");
    scanf("%lld", &block);
    long long factor = gcd(n, block);
    if (factor > 1) {
        printf("Found a non-trivial common factor of n and the block: %lld\n", factor);
        printf("This factor can potentially be used to factorize n and break the RSA encryption.\n");
    } else {
        printf("No non-trivial common factor found between n and the block.\n");
    }

    return 0;
}
