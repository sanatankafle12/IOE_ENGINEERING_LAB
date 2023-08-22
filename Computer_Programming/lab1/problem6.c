/*Write a program  to read  a l,b,and  h of a •cuboid and display its volume */

#include <stdio.h>

int main()
{
    float l,b,h,vol;
    printf("Enter length, breadth and height: ");
    scanf("%f %f %f",&l,&b,&h);
    vol = l*b*h;
    printf("The volume is %.2f.",vol);
    return 0;
}