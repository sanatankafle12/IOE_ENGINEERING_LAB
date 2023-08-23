#include <stdio.h>
#include <math.h>

void check_prime() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Check for real numbers
    if (number < 0 || number != (int)number) {
        printf("Invalid input. Please enter a positive integer.\n");
        return;
    }
    
    // Check for negative numbers
    if (number < 2) {
        printf("%d is not a prime number.\n", number);
        return;
    }
    
    // Check for prime numbers
    int isPrime = 1;
    int limit = sqrt(number);
    
    for (int i = 2; i <= limit; i++) {
        if (number % i == 0) {
            isPrime = 0;
            break;
        }
    }
    
    if (isPrime) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }
}

int main() {
    check_prime();
    
    return 0;
}