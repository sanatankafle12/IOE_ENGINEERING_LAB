/* Write a program to compute equivalent resistance of two resistors RI and R2 when they are
connected in series and parallel connection */

#include <stdio.h>

int main()
{
    float R1,R2,PR,SR;
    printf("Enter Resisters value: ");
    scanf("%f %f",&R1,&R2);
    SR = R1 + R2;
    PR = (R1*R2)/(R1 + R2);
    printf("Series = %.2f\n Parallel = %.2f.",SR,PR);
    return 0;
}