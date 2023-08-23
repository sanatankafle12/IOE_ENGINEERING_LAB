#include <stdio.h>

int main() {
    int M, N, R;

    printf("Enter the value of M: ");
    scanf("%d", &M);

    printf("Enter the value of N: ");
    scanf("%d", &N);

    printf("Enter the range R: ");
    scanf("%d", &R);

    printf("Multiplication Table:\n");

    for (int i = 1; i <= R; i++) {
        for (int j = M; j <= N; j++) {
            printf("%d * %d = %d\t", j, i, j * i);
        }
        printf("\n");
    }

    return 0;
}