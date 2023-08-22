/*Write a program to read  values of x and y from the user and evaluate the expression v=x^3+y^2-100/x*/

#include <stdio.h>

int main()
{
    float x,y,v;
    printf("Enter x and y: ");
    scanf("%f %f",&x,&y);
    v = x*x*x+y*y-100.0/x;
    printf("v = %.2f",v);
    return 0;
}