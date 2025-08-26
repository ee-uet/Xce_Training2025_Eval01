#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_power_of_two(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);

    // Count number of set bits (Kernighan’s algorithm)
    int count = 0;
    int temp = N;
    while (temp != 0) {
        temp = temp & (temp - 1);
        count++;
    }
    printf("No of set bits in %d: %d\n", N, count);

    // Reverse all bits (just ~ for demo)
    printf("Reverse all bits of %d is: %d\n", N, ~N);

    // Check if power of 2
    if (is_power_of_two(N))
        printf("%d is a power of 2\n", N);
    else
        printf("%d is NOT a power of 2\n", N);

    return 0;
}
