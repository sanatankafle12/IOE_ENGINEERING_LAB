#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    int reversedNum = 0;
    int tempNum = num;

    while (tempNum != 0) {
        reversedNum = reversedNum * 10 + tempNum % 10;
        tempNum /= 10;
    }

    return (num == reversedNum);
}

int main() {
    int n1, n2;
    int primeCount = 0, palindromeCount = 0;

    printf("Enter two positive integers (n1 and n2, where n1 < n2): ");
    scanf("%d %d", &n1, &n2);

    printf("Prime numbers between %d and %d: ", n1, n2);
    for (int i = n1; i <= n2; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            primeCount++;
        }
    }
    printf("\n");
    printf("Count of prime numbers: %d\n", primeCount);

    printf("Palindrome numbers between %d and %d: ", n1, n2);
    for (int i = n1; i <= n2; i++) {
        if (isPalindrome(i)) {
            printf("%d ", i);
            palindromeCount++;
        }
    }
    printf("\n");
    printf("Count of palindrome numbers: %d\n", palindromeCount);

    return 0;
}