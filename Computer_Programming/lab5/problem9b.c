#include <stdio.h>
#include <math.h>

// Function to calculate the number of digits in a number
int countDigits(unsigned int num) {
    int count = 0;

    while (num != 0) {
        num /= 10;
        count++;
    }

    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(unsigned int num) {
    unsigned int tempNum = num;
    int numDigits = countDigits(num);
    unsigned int sum = 0;

    while (tempNum != 0) {
        int digit = tempNum % 10;
        sum += pow(digit, numDigits);
        tempNum /= 10;
    }

    return (num == sum);
}

int main() {
    unsigned int number;

    printf("Enter a positive integer: ");
    scanf("%u", &number);

    if (isArmstrong(number)) {
        printf("The number is an Armstrong number.\n");
    } else {
        printf("The number is not an Armstrong number.\n");
    }

    return 0;
}