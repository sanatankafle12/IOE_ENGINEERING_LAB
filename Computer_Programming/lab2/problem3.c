/* Write a program to read two end points of a line, compute their mid point and display it*/

#include <stdio.h>

int main()
{
    float x1,x2,x,y1,y2,y;
    printf("Enter x1 , y1 , x2 and y2 respectively:  ");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    x = (x1+x2)/2;
    y = (y1+y2)/2;
    printf("(x,y) = (%.2f,%.2f)",x,y);
    return 0;
}