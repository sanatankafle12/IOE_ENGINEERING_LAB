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

// Function to check if a number is a twin prime
bool isTwinPrime(unsigned int num) {
    if (isPrime(num) && (isPrime(num - 2) || isPrime(num + 2))) {
        return true;
    }

    return false;
}

int main() {
    unsigned int number;

    printf("Enter a positive integer: ");
    scanf("%u", &number);

    if (isTwinPrime(number)) {
        printf("The number is a twin prime.\n");
    } else {
        printf("The number is not a twin prime.\n");
    }

    return 0;
}