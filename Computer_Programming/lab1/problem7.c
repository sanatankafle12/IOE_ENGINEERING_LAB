/*Write a program to read price of two pens and five copies of same type and calculate the
price after discounting  10%*/

#include <stdio.h>

int main()
{
    int p,c,total;
    float total_after_discount;
    printf("Enter price of pen and copies: ");
    scanf("%d %d",&p,&c);
    total = 2*p+5*c;
    total_after_discount = total - 1.0/10.0*total;
    printf("%.2f",total_after_discount);
    return 0;
}