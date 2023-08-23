#include <stdio.h>

int nont_ndd(int noat) {
    int sum = 0;
    
    while (noat > 0) {
        sum += noat % 10;
        noat /= 10;
    }
    
    return sum;
}

int main() {
    int number = 12345;
    int result = nont_ndd(number);
    
    printf("Sum of digits in %d is: %d\n", number, result);
    
    return 0;
}