//Write a program to read three sides of a triangle ftom the user and calculate the area of the
//triangle. Be sure to check the condition of triangle if sides are given.

#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c,S,A;
    printf("Enter the sides: ");
    scanf("%f %f %f",&a,&b,&c);
    if((a+b)<c || (c+a)<b || (c+b)<a)
    {
        printf("Invalid triangle");
        return 0;
    }
    S = (a+b+c)/2;
    S = S*(S-a)*(S-b)*(S-c);
    A = pow(S,0.5);
    printf("The area is %f",A);
    return 0;
}