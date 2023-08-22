//WAP to calculate x^n/n!.
//Where x is floating and n is non zero positive integer

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float x,value,factorial=1;
    printf("Enter x and n: ");
    scanf("%f %d",&x,&n);
    if(n==0)
    {
        factorial = 1;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            factorial*=i;
        }
    }
    value = pow(x,n)/factorial;
    printf("%.2f",value);
    return 0;
}