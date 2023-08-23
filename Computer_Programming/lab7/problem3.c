#include <stdio.h>

unsigned int fact(unsigned int number) {
    unsigned int factorial = 1;
    
    for (unsigned int i = 1; i <= number; i++) {
        factorial *= i;
    }
    
    return factorial;
}

int main() {
    unsigned int number;
    
    printf("Enter a non-negative integer: ");
    scanf("%u", &number);
    
    unsigned int result = fact(number);
    
    printf("Factorial of %u is: %u\n", number, result);
    
    return 0;
}