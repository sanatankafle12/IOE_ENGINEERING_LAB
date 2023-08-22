//Write program to swap values of two variables,say a and b

#include <stdio.h>

int main()
{
    float a,b,temp;
    printf("Enter the two variables: ");
    scanf("%f %f",&a,&b);
    temp = a;
    a = b;
    b = temp;
    printf("%.2f %.2f",a,b); 
    return 0;
}