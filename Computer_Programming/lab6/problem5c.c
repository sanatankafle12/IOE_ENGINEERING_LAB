#include <stdio.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Sequence: ");
    int num = 1;
    int increment = 1;
    for (int i = 1; i <= n; i++) {
        printf("%d ", num);
        num += increment;
        increment += 2;
    }

    return 0;
}