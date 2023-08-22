/*write a program to calculate  the volume of sphere of radius r*/

#include <stdio.h>

int main()
{
    float r,vol,pi=3.14;
    printf("Enter the radius: ");
    scanf("%f",&r);
    vol = 4.0/3.0*pi*r*r*r;
    printf("The volume of the sphere with radius %f is %.2f.",r,vol);
    return 0;
}