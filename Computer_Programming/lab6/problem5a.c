#include <stdio.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Sequence: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    return 0;
}