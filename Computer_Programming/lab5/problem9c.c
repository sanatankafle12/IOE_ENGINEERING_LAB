#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(unsigned int num) {
    if (num < 2) {
        return false;
    }

    for (unsigned int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    unsigned int number;

    printf("Enter a positive integer: ");
    scanf("%u", &number);

    if (isPrime(number)) {
        printf("The number is a prime number.\n");
    } else {
        printf("The number is not a prime number.\n");
    }

    return 0;
}