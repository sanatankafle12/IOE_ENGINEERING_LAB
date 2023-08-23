#include <stdio.h>

// Function to check if a number is a palindrome
int isPalindrome(unsigned int num) {
    unsigned int reversedNum = 0;
    unsigned int tempNum = num;

    while (tempNum != 0) {
        reversedNum = reversedNum * 10 + tempNum % 10;
        tempNum /= 10;
    }

    return (num == reversedNum);
}

int main() {
    unsigned int number;

    printf("Enter a positive integer: ");
    scanf("%u", &number);

    if (isPalindrome(number)) {
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }

    return 0;
}