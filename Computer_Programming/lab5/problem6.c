#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate x^n/n!
double calculateExpression(double x, int n) {
    double result = 1.0;
    int fact = 1;
    
    for (int i = 1; i <= n; i++) {
        fact *= i;
        result *= x / fact;
    }
    
    return result;
}

int main() {
    double x;
    int n;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    double result = calculateExpression(x, n);

    printf("Result: %.6f\n", result);

    return 0;
}