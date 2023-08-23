#include <stdio.h>

int computeSeries(int n, int term, int sign) {
    // Base case: when n is 1, return the term
    if (n == 1) {
        return term;
    }
    
    // Recursive case: calculate the next term and add it to the sum
    int nextTerm = term + sign * (n * n);
    return nextTerm + computeSeries(n - 1, nextTerm, -sign);
}

int main() {
    int n;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int sum = computeSeries(n, 0, 1);
    
    printf("Sum of the series: %d\n", sum);
    
    return 0;
}