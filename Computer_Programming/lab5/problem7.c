#include <stdio.h>

// Function to display Fibonacci sequence up to a given number of terms
void displayFibonacci(int n) {
    int first = 0, second = 1;
    int next;

    printf("Fibonacci Sequence: ");
    printf("%d, %d, ", first, second);

    for (int i = 3; i <= n; i++) {
        next = first + second;
        printf("%d, ", next);
        first = second;
        second = next;
    }
}

int main() {
    int numTerms;

    printf("Enter the number of terms: ");
    scanf("%d", &numTerms);

    displayFibonacci(numTerms);

    return 0;
}