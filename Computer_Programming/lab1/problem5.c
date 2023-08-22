/*-Write a program to read four integers from the user and display mean of the numbers*/

#include <stdio.h>

int main()
{
   int a,b,c,d;
   float mean;
   printf("Enter the four integers: ");
   scanf("%d %d %d %d",&a,&b,&c,&d);
   mean = (a+b+c+d)/4.0;
   printf("THe mean is %.2f. ",mean);
   return 0;
}