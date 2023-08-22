//Write a program to determine all roots of a quadratic equation ax +bx+c=0. Read the values of a, b, and c from the user.
#include <math.h>
#include <stdio.h>

int main() 
{
    float a, b, c, d, r1, r2, realPart, imagPart;
    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;
    if (d > 0) {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("r1 = %.2f and r2 = %.2f", r1, r2);
    }
    else if (d == 0) {
        r1 = r2 = -b / (2 * a);
        printf("r1 = r2 = %.2f;", r1);
    }
    else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-d) / (2 * a);
        printf("r1 = %.2f+%.2fi and r2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
    }

    return 0;
} 