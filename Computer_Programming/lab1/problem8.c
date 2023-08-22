/* Write a program to read time given  for C programming study  a day at your home in
hours, minutes and seconds and display the total time  in seconds in 30 days*/

#include <stdio.h>

int main()
{
    int h=2,m=20,s=35,total;
    total = h*m*s*30;
    printf("The total is %d.",total);
    return 0;
}