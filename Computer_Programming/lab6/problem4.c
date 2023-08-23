#include <stdio.h>

int main() {
    int number;
    int sum = 0;

    printf("Enter positive numbers (enter 0 to stop):\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &number);

        if (number > 0) {
            sum += number;
        }
    } while (number != 0);

    printf("Sum of the positive numbers: %d\n", sum);

    return 0;
}