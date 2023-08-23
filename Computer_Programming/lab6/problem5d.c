#include <stdio.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Sequence: ");
    for (int i = 1; i <= n; i++) {
        printf("%.2f ", 1.0 / (2 * i - 1));
    }

    return 0;
}