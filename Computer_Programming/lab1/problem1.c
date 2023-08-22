/* Write a program to calculate the area. circumference of a circle of radius r.*/

#include <stdio.h>

int main()
{
    float r,area,c,pi=3.14;
    printf("Enter the radius of circle: ");
    scanf("%f",&r);
    area = pi*r*r;
    c = 2*pi*r;
    printf("The area and circumference of circle having radius %f is %.2f and %.2f.\n",r,area,c);
    return 0;
}