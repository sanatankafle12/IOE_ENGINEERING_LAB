#include <stdio.h>

void countDigits(unsigned int number, int *oddCount, int *evenCount) {
    *oddCount = 0;
    *evenCount = 0;
    
    while (number > 0) {
        int digit = number % 10;
        
        if (digit % 2 == 0) {
            (*evenCount)++;
        } else {
            (*oddCount)++;
        }
        
        number /= 10;
    }
}

int main() {
    unsigned int number;
    
    printf("Enter an unsigned integer: ");
    scanf("%u", &number);
    
    int oddCount, evenCount;
    countDigits(number, &oddCount, &evenCount);
    
    printf("Number of odd digits: %d\n", oddCount);
    printf("Number of even digits: %d\n", evenCount);
    
    return 0;
}