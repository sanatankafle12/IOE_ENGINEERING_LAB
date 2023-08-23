#include <stdio.h>

void SumOfDigits(int number) {
    int sum = 0;
    int temp = number;
    
    while (temp != 0) {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;
    }
    
    printf("Sum of digits in %d is: %d\n", number, sum);
}

int main() {
    int number = 12345;
    SumOfDigits(number);
    
    return 0;
}