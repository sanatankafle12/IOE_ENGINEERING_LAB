/*write  a program to calculate  the simple interest. Read values of P, T, R from the user*/ 

#include <stdio.h>

int main()
{
    float R , I,p,T;
    printf("Enter rate, money and the time. ");
    scanf("%f %f %f",&R,&p,&T);
    I = p*T*R/100.0;
    printf("The simple interest is %.2f",I);
    return 0;
}