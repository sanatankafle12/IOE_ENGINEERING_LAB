#include <stdio.h>

int main() {
    int rows = 4;
    int spaces = 0;
    
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
        spaces++;
    }
    
    return 0;
}